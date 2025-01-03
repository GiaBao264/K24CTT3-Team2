#include "Tictactoe.h"
#include "Library.h"
#include "Console.h"
#include "Graphic.h"
#include "MainCaro.h"
#include "LoadGame.h"
#include "Language.h"

#define moveTo(x, y) setPos(status[x][y].X, status[x][y].Y)
const int boardSize = 15;
_Point status[boardSize + 5][boardSize + 5];
int dx[]{ -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[]{ -1, 0, 1, -1, 1, 0, -1, 1 };

const int INF = 1e9;
const int N = 17;

struct _time {
    int min;
    int sec;
};
struct ScoreOfaMove {
    int score;
    pair <int, int> move;
};

bool cmp(ScoreOfaMove x, ScoreOfaMove y) {
    return x.score > y.score;
}

ii Winning_Position;
int win_type, cnt_moves;
char board[N][N];
vector <ii> moveMade;
bool noth;

char player() {

    // given a current board, return to the player who has the next turn

    int count_X = 0;
    int count_O = 0;

    for (int i = 1; i <= 15; ++i)
        for (int j = 1; j <= 15; ++j) {
            if (board[i][j] == 'X') count_X++;
            else if (board[i][j] == 'O') count_O++;
        }

    if (count_X == count_O) return 'X';
    return 'O';
}

bool is_valid_move(int row, int col) {

    // check if the move is valid

    if (row < 1 || row > 15 || col < 1 || col > 15) return false;
    if (board[row][col] != '.') return false;
    return true;
}

bool valid_cell(int x, int y) {
    return x >= 1 && x <= 15 && y >= 1 && y <= 15;
}

vector <ii> actions() {

    // return a vector of all possible actions

    vector<ii> possible_moves;
    for (int i = 1; i <= 15; ++i)
        for (int j = 1; j <= 15; ++j)
            if (board[i][j] == '.') {
                bool ok = 0;
                for (int k = -2; k <= 2; ++k)
                    for (int l = -2; l <= 2; ++l)
                        if (i + k >= 1 && i + k <= 15 && j + l >= 1 && j + l <= 15)
                            if (board[i + k][j + l] != '.') ok = 1;
                if (ok) possible_moves.push_back({ i, j });
            }
    return possible_moves;
}

int is_terminated() {
    // -1 if no one can make move
    // 0 if the game is still going
    // 1 if X wins
    // 2 if O wins
    if (!actions().size()) return -1;
    for (int i = 1; i <= 15; ++i) {
        for (int j = 1; j <= 15; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') continue;
            int c1 = 1, c2 = 1, c3 = 1, c4 = 1;
            bool ok1l = 1, ok1r = 1, ok2l = 1, ok2r = 1, ok3l = 1, ok3r = 1, ok4l = 1, ok4r = 1;
            for (int k = 1; k <= 5; ++k) {
                if (ok1l && valid_cell(i, j - k) && board[i][j - k] == board[i][j]) c1++;
                else ok1l = 0;
                if (ok1r && valid_cell(i, j + k) && board[i][j + k] == board[i][j]) c1++;
                else ok1r = 0;
                if (ok2l && valid_cell(i - k, j) && board[i - k][j] == board[i][j]) c2++;
                else ok2l = 0;
                if (ok2r && valid_cell(i + k, j) && board[i + k][j] == board[i][j]) c2++;
                else ok2r = 0;
                if (ok3l && valid_cell(i - k, j - k) && board[i - k][j - k] == board[i][j]) c3++;
                else ok3l = 0;
                if (ok3r && valid_cell(i + k, j + k) && board[i + k][j + k] == board[i][j]) c3++;
                else ok3r = 0;
                if (ok4l && valid_cell(i - k, j + k) && board[i - k][j + k] == board[i][j]) c4++;
                else ok4l = 0;
                if (ok4r && valid_cell(i + k, j - k) && board[i + k][j - k] == board[i][j]) c4++;
                else ok4r = 0;
            }
            int mx = c1;
            mx = max(mx, c2);
            mx = max(mx, c3);
            mx = max(mx, c4);
            if (mx >= 5) {
                Winning_Position = { i, j };
                if (c1 >= 5) win_type = 1;
                else if (c2 >= 5) win_type = 2;
                else if (c3 >= 5) win_type = 3;
                else win_type = 4;
                return (board[i][j] == 'X' ? 1 : 2);
            }
        }
    }
    return 0;
}

bool isWinningState(char cur_player, int row, int col) {

    // check if there is a 5 in a row

    int i = row, j = row;
    while (i >= 1 && board[i][col] == cur_player) --i;
    while (j <= 15 && board[j][col] == cur_player) ++j;
    if (j - i >= 6) return true;
    i = col, j = col;
    while (i >= 1 && board[row][i] == cur_player) --i;
    while (j <= 15 && board[row][j] == cur_player) ++j;
    if (j - i >= 6) return true;
    int c = 0;
    i = row, j = col;
    while (i >= 1 && j >= 1 && board[i][j] == cur_player) --i, --j, ++c;
    int k = row, l = col;
    while (k <= 15 && l <= 15 && board[k][l] == cur_player) ++k, ++l, ++c;
    if (c >= 6) return true;
    c = 0;
    i = row, j = col;
    while (i >= 1 && j <= 15 && board[i][j] == cur_player) --i, ++j, ++c;
    k = row, l = col;
    while (k <= 15 && l >= 1 && board[k][l] == cur_player) ++k, --l, ++c;
    if (c >= 6) return true;
    return false;
}

bool isWinningState2(char cur_player, int row, int col) {

    // 4 in a row with no blocked

    int i = row, j = row;
    while (i >= 1 && board[i][col] == cur_player) --i;
    while (j <= 15 && board[j][col] == cur_player) ++j;
    if (j - i == 5 && is_valid_move(i, col) && is_valid_move(j, col)) return true;
    if (j - i >= 4) noth = 1;
    i = col, j = col;
    while (i >= 1 && board[row][i] == cur_player) --i;
    while (j <= 15 && board[row][j] == cur_player) ++j;
    if (j - i == 5 && is_valid_move(row, i) && is_valid_move(row, j)) return true;
    if (j - i >= 4) noth = 1;
    int c = 0;
    i = row, j = col;
    while (i >= 1 && j >= 1 && board[i][j] == cur_player) --i, --j, ++c;
    int k = row, l = col;
    while (k <= 15 && l <= 15 && board[k][l] == cur_player) ++k, ++l, ++c;
    if (c == 5 && is_valid_move(i, j) && is_valid_move(k, l)) return true;
    if (c >= 4) noth = 1;
    c = 0;
    i = row, j = col;
    while (i >= 1 && j <= 15 && board[i][j] == cur_player) --i, ++j, ++c;
    k = row, l = col;
    while (k <= 15 && l >= 1 && board[k][l] == cur_player) ++k, --l, ++c;
    if (c == 5 && is_valid_move(i, j) && is_valid_move(k, l)) return true;
    if (c >= 4) noth = 1;
    return false;
}

bool IsLosingState(char cur_player) {

    // opponent has 4 in a row with 1 blocked

    char opponent = (cur_player == 'X' ? 'O' : 'X');

    for (int row = 1; row <= 15; ++row) {
        for (int col = 1; col <= 15; ++col) {
            if (board[row][col] == opponent) {
                int i = row, j = row, k, l;
                int c = 0;
                while (i >= 1 && board[i][col] == opponent) --i, ++c;
                while (j <= 15 && board[j][col] == opponent) ++j, ++c;
                if (c == 5 && (is_valid_move(i, col) || is_valid_move(j, col))) return true;

                i = col, j = col, c = 0;
                while (i >= 1 && board[row][i] == opponent) --i, ++c;
                while (j <= 15 && board[row][j] == opponent) ++j, ++c;
                if (c == 5 && (is_valid_move(row, i) || is_valid_move(row, j))) return true;

                i = row, j = col, k = row, l = col, c = 0;
                while (i >= 1 && j >= 1 && board[i][j] == opponent) --i, --j, ++c;
                while (k <= 15 && l <= 15 && board[k][l] == opponent) ++k, ++l, ++c;
                if (c == 5 && (is_valid_move(i, j) || is_valid_move(k, l))) return true;

                i = row, j = col, k = row, l = col, c = 0;
                while (i >= 1 && j <= 15 && board[i][j] == opponent) --i, ++j, ++c;
                while (k <= 15 && l >= 1 && board[k][l] == opponent) ++k, --l, ++c;
                if (c == 5 && (is_valid_move(i, j) || is_valid_move(k, l))) return true;
            }
        }
    }
    return false;
}

bool isLosingState2(char cur_player) {
    // check if opponent has 3 in a row without being blocked
    // case 1 no phai trong nhu the nay: . O O O . .

    char opponent = (cur_player == 'X' ? 'O' : 'X');

    for (int row = 1; row <= 15; ++row) {
        for (int col = 1; col <= 15; ++col) {
            if (board[row][col] == opponent) {
                int i = row, j = row, k, l;
                int c = 0;
                while (i >= 1 && board[i][col] == opponent) --i, ++c;
                while (j <= 15 && board[j][col] == opponent) ++j, ++c;
                if ((c == 4 && is_valid_move(i, col) && is_valid_move(j, col)) && (is_valid_move(i - 1, col) || is_valid_move(j + 1, col))) return true;

                i = col, j = col, c = 0;
                while (i >= 1 && board[row][i] == opponent) --i, ++c;
                while (j <= 15 && board[row][j] == opponent) ++j, ++c;
                if ((c == 4 && is_valid_move(row, i) && is_valid_move(row, j)) && (is_valid_move(row, i - 1) || is_valid_move(row, j + 1))) return true;

                i = row, j = col, k = row, l = col, c = 0;
                while (i >= 1 && j >= 1 && board[i][j] == opponent) --i, --j, ++c;
                while (k <= 15 && l <= 15 && board[k][l] == opponent) ++k, ++l, ++c;
                if ((c == 4 && is_valid_move(i, j) && is_valid_move(k, l)) && (is_valid_move(i - 1, j - 1) || is_valid_move(k + 1, l + 1))) return true;

                i = row, j = col, k = row, l = col, c = 0;
                while (i >= 1 && j <= 15 && board[i][j] == opponent) --i, ++j, ++c;
                while (k <= 15 && l >= 1 && board[k][l] == opponent) ++k, --l, ++c;
                if ((c == 4 && is_valid_move(i, j) && is_valid_move(k, l)) && (is_valid_move(i - 1, j + 1) || is_valid_move(k + 1, l - 1))) return true;
            }
        }
    }
    return false;
}

bool BlockOP_connectPath(char cur_player, int row, int col) {
    // check if the move of the current player block the opponent to have 4 in a row
    char opponent = (cur_player == 'X' ? 'O' : 'X');

    int i = row - 1, j = row + 1, c = 0;
    while (i >= 1 && board[i][col] == opponent) --i, ++c;
    while (j <= 15 && board[j][col] == opponent) ++j, ++c;
    if (c >= 3 && is_valid_move(i, col) && is_valid_move(j, col)) return true;

    i = col - 1, j = col + 1, c = 0;
    while (i >= 1 && board[row][i] == opponent) --i, ++c;
    while (j <= 15 && board[row][j] == opponent) ++j, ++c;
    if (c >= 3 && is_valid_move(row, i) && is_valid_move(row, j)) return true;

    c = 0;
    i = row - 1, j = col - 1;
    while (i >= 1 && j >= 1 && board[i][j] == opponent) --i, --j, ++c;
    int k = row + 1, l = col + 1;
    while (k <= 15 && l <= 15 && board[k][l] == opponent) ++k, ++l, ++c;
    if (c >= 3 && is_valid_move(i, j) && is_valid_move(k, l)) return true;

    c = 0;
    i = row - 1, j = col + 1;
    while (i >= 1 && j <= 15 && board[i][j] == opponent) --i, ++j, ++c;
    k = row + 1, l = col - 1;
    while (k <= 15 && l >= 1 && board[k][l] == opponent) ++k, --l, ++c;
    if (c >= 3 && is_valid_move(i, j) && is_valid_move(k, l)) return true;

    return false;
}

bool BlockOPsWin(char opponent, int row, int col) {
    // assume that the move is made by the opposite player, will the game end?
    int i = row - 1, j = row + 1, c = 0;
    while (i >= 1 && board[i][col] == opponent) --i, ++c;
    while (j <= 15 && board[j][col] == opponent) ++j, ++c;
    if (c >= 4) return true;

    i = col - 1, j = col + 1, c = 0;
    while (i >= 1 && board[row][i] == opponent) --i, ++c;
    while (j <= 15 && board[row][j] == opponent) ++j, ++c;
    if (c >= 4) return true;

    c = 0;
    i = row - 1, j = col - 1;
    while (i >= 1 && j >= 1 && board[i][j] == opponent) --i, --j, ++c;
    int k = row + 1, l = col + 1;
    while (k <= 15 && l <= 15 && board[k][l] == opponent) ++k, ++l, ++c;
    if (c >= 4) return true;

    c = 0;
    i = row - 1, j = col + 1;
    while (i >= 1 && j <= 15 && board[i][j] == opponent) --i, ++j, ++c;
    k = row + 1, l = col - 1;
    while (k <= 15 && l >= 1 && board[k][l] == opponent) ++k, --l, ++c;
    if (c >= 4) return true;

    return false;
}

int BlockOpponent(char cur_player, int row, int col) {

    // check if opponent has 4 in a row with 2 blocked || opponent has 3 in a row with 1 blocked

    char opponent = (cur_player == 'X' ? 'O' : 'X');
    int pts = 0;

    if (col >= 6 && board[row][col - 1] == opponent && board[row][col - 2] == opponent && board[row][col - 3] == opponent && board[row][col - 4] == '.' && board[row][col - 5] == '.') pts += 3;
    if (col == 6 && board[row][col - 1] == '.' && board[row][col - 2] == opponent && board[row][col - 3] == opponent && board[row][col - 4] == opponent && board[row][col - 5] == '.') pts += 3;
    if (col == 5 && board[row][col - 1] == opponent && board[row][col - 2] == opponent && board[row][col - 3] == opponent && board[row][col - 4] == opponent) pts += 50;
    if (col >= 6 && board[row][col - 5] == cur_player && board[row][col - 4] == opponent && board[row][col - 3] == opponent && board[row][col - 2] == opponent && board[row][col - 1] == opponent) pts += 50;

    if (row >= 6 && board[row - 1][col] == opponent && board[row - 2][col] == opponent && board[row - 3][col] == opponent && board[row - 4][col] == '.' && board[row - 5][col] == '.') pts += 3;
    if (row == 6 && board[row - 1][col] == '.' && board[row - 2][col] == opponent && board[row - 3][col] == opponent && board[row - 4][col] == opponent && board[row - 5][col] == '.') pts += 3;
    if (row == 5 && board[row - 1][col] == opponent && board[row - 2][col] == opponent && board[row - 3][col] == opponent && board[row - 4][col] == opponent) pts += 50;
    if (row >= 6 && board[row - 5][col] == cur_player && board[row - 4][col] == opponent && board[row - 3][col] == opponent && board[row - 2][col] == opponent && board[row - 1][col] == opponent) pts += 50;

    if (row >= 6 && col >= 6 && board[row - 1][col - 1] == opponent && board[row - 2][col - 2] == opponent && board[row - 3][col - 3] == opponent && board[row - 4][col - 4] == '.' && board[row - 5][col - 5] == '.') pts += 3;
    if (row == 6 && col == 6 && board[row - 1][col - 1] == '.' && board[row - 2][col - 2] == opponent && board[row - 3][col - 3] == opponent && board[row - 4][col - 4] == opponent && board[row - 5][col - 5] == '.') pts += 3;
    if (row == 5 && col == 5 && board[row - 1][col - 1] == opponent && board[row - 2][col - 2] == opponent && board[row - 3][col - 3] == opponent && board[row - 4][col - 4] == opponent) pts += 50;
    if (row >= 6 && col >= 6 && board[row - 5][col - 5] == cur_player && board[row - 4][col - 4] == opponent && board[row - 3][col - 3] == opponent && board[row - 2][col - 2] == opponent && board[row - 1][col - 1] == opponent) pts += 50;

    if (row >= 6 && col <= 10 && board[row - 1][col + 1] == opponent && board[row - 2][col + 2] == opponent && board[row - 3][col + 3] == opponent && board[row - 4][col + 4] == '.' && board[row - 5][col + 5] == '.') pts += 3;
    if (row == 6 && col == 10 && board[row - 1][col + 1] == '.' && board[row - 2][col + 2] == opponent && board[row - 3][col + 3] == opponent && board[row - 4][col + 4] == opponent && board[row - 5][col + 5] == '.') pts += 3;
    if (row == 5 && col == 11 && board[row - 1][col + 1] == opponent && board[row - 2][col + 2] == opponent && board[row - 3][col + 3] == opponent && board[row - 4][col + 4] == opponent) pts += 50;
    if (row >= 6 && col <= 10 && board[row - 5][col + 5] == cur_player && board[row - 4][col + 4] == opponent && board[row - 3][col + 3] == opponent && board[row - 2][col + 2] == opponent && board[row - 1][col + 1] == opponent) pts += 50;

    if (row <= 10 && board[row + 1][col] == opponent && board[row + 2][col] == opponent && board[row + 3][col] == opponent && board[row + 4][col] == '.' && board[row + 5][col] == '.') pts += 3;
    if (row == 10 && board[row + 1][col] == '.' && board[row + 2][col] == opponent && board[row + 3][col] == opponent && board[row + 4][col] == opponent && board[row + 5][col] == '.') pts += 3;
    if (row == 11 && board[row + 1][col] == opponent && board[row + 2][col] == opponent && board[row + 3][col] == opponent && board[row + 4][col] == opponent) pts += 50;
    if (row <= 10 && board[row + 5][col] == cur_player && board[row + 4][col] == opponent && board[row + 3][col] == opponent && board[row + 2][col] == opponent && board[row + 1][col] == opponent) pts += 50;

    if (row <= 10 && col <= 10 && board[row + 1][col + 1] == opponent && board[row + 2][col + 2] == opponent && board[row + 3][col + 3] == opponent && board[row + 4][col + 4] == '.' && board[row + 5][col + 5] == '.') pts += 3;
    if (row == 10 && col == 10 && board[row + 1][col + 1] == '.' && board[row + 2][col + 2] == opponent && board[row + 3][col + 3] == opponent && board[row + 4][col + 4] == opponent && board[row + 5][col + 5] == '.') pts += 3;
    if (row == 11 && col == 11 && board[row + 1][col + 1] == opponent && board[row + 2][col + 2] == opponent && board[row + 3][col + 3] == opponent && board[row + 4][col + 4] == opponent) pts += 50;
    if (row <= 10 && col <= 10 && board[row + 5][col + 5] == cur_player && board[row + 4][col + 4] == opponent && board[row + 3][col + 3] == opponent && board[row + 2][col + 2] == opponent && board[row + 1][col + 1] == opponent) pts += 50;

    if (row <= 10 && col >= 6 && board[row + 1][col - 1] == opponent && board[row + 2][col - 2] == opponent && board[row + 3][col - 3] == opponent && board[row + 4][col - 4] == '.' && board[row + 5][col - 5] == '.') pts += 3;
    if (row == 10 && col == 6 && board[row + 1][col - 1] == '.' && board[row + 2][col - 2] == opponent && board[row + 3][col - 3] == opponent && board[row + 4][col - 4] == opponent && board[row + 5][col - 5] == '.') pts += 3;
    if (row == 11 && col == 5 && board[row + 1][col - 1] == opponent && board[row + 2][col - 2] == opponent && board[row + 3][col - 3] == opponent && board[row + 4][col - 4] == opponent) pts += 50;
    if (row <= 10 && col >= 6 && board[row + 5][col - 5] == cur_player && board[row + 4][col - 4] == opponent && board[row + 3][col - 3] == opponent && board[row + 2][col - 2] == opponent && board[row + 1][col - 1] == opponent) pts += 50;

    if (col <= 10 && board[row][col + 1] == opponent && board[row][col + 2] == opponent && board[row][col + 3] == opponent && board[row][col + 4] == '.' && board[row][col + 5] == '.') pts += 3;
    if (col == 10 && board[row][col + 1] == '.' && board[row][col + 2] == opponent && board[row][col + 3] == opponent && board[row][col + 4] == opponent && board[row][col + 5] == '.') pts += 3;
    if (col == 11 && board[row][col + 1] == opponent && board[row][col + 2] == opponent && board[row][col + 3] == opponent && board[row][col + 4] == opponent) pts += 50;
    if (col <= 10 && board[row][col + 5] == cur_player && board[row][col + 4] == opponent && board[row][col + 3] == opponent && board[row][col + 2] == opponent && board[row][col + 1] == opponent) pts += 50;

    return pts;
}

int BlockOpponent2(char opponent, int row, int col) {
    // check if there the move blocks combined strategy of the opponent
    int pts = 0;

    int i = row - 1, j = row + 1, c = 0;
    while (i >= 1 && board[i][col] == opponent) --i, ++c;
    while (j <= 15 && board[j][col] == opponent) ++j, ++c;
    if (c >= 2) pts += 3;

    i = col - 1, j = col + 1, c = 0;
    while (i >= 1 && board[row][i] == opponent) --i, ++c;
    while (j <= 15 && board[row][j] == opponent) ++j, ++c;
    if (c >= 2) pts += 3;

    c = 0;
    i = row - 1, j = col - 1;
    while (i >= 1 && j >= 1 && board[i][j] == opponent) --i, --j, ++c;
    int k = row + 1, l = col + 1;
    while (k <= 15 && l <= 15 && board[k][l] == opponent) ++k, ++l, ++c;
    if (c >= 2) pts += 3;

    c = 0;
    i = row - 1, j = col + 1;
    while (i >= 1 && j <= 15 && board[i][j] == opponent) --i, ++j, ++c;
    k = row + 1, l = col - 1;
    while (k <= 15 && l >= 1 && board[k][l] == opponent) ++k, --l, ++c;
    if (c >= 2) pts += 3;

    i = row - 2, c = 0;
    while (i >= 1 && board[i][col] == opponent) --i, ++c;
    if (c >= 2) pts += 3;

    i = col - 2, c = 0;
    while (i >= 1 && board[row][i] == opponent) --i, ++c;
    if (c >= 2) pts += 3;

    j = row + 2, c = 0;
    while (j <= 15 && board[j][col] == opponent) ++j, ++c;
    if (c >= 2) pts += 3;

    j = col + 2, c = 0;
    while (j <= 15 && board[row][j] == opponent) ++j, ++c;
    if (c >= 2) pts += 3;

    c = 0;
    i = row - 2, j = col - 2;
    while (i >= 1 && j >= 1 && board[i][j] == opponent) --i, --j, ++c;
    if (c >= 2) pts += 3;

    c = 0;
    i = row - 2, j = col + 2;
    while (i >= 1 && j <= 15 && board[i][j] == opponent) --i, ++j, ++c;
    if (c >= 2) pts += 3;

    c = 0;
    i = row + 2, j = col - 2;
    while (i <= 15 && j >= 1 && board[i][j] == opponent) ++i, --j, ++c;
    if (c >= 2) pts += 3;

    c = 0;
    i = row + 2, j = col + 2;
    while (i <= 15 && j <= 15 && board[i][j] == opponent) ++i, ++j, ++c;
    if (c >= 2) pts += 3;

    return pts;
}

bool ThreeInARow(char cur_player, int row, int col) {

    // check if there is a 3 in a row without being blocked
    int pts = 0;

    int i = row, j = row, c = 0;
    while (i >= 1 && board[i][col] == cur_player) --i, ++c;
    while (j <= 15 && board[j][col] == cur_player) ++j, ++c;
    while (i >= 1 && board[i][col] == '.') --i;
    while (j <= 15 && board[j][col] == '.') ++j;
    if (j - i >= 7 && c >= 4) pts += 2;

    i = col, j = col, c = 0;
    while (i >= 1 && board[row][i] == cur_player) --i, ++c;
    while (j <= 15 && board[row][j] == cur_player) ++j, ++c;
    while (i >= 1 && board[row][i] == '.') --i;
    while (j <= 15 && board[row][j] == '.') ++j;
    if (j - i >= 7 && c >= 4) pts += 2;

    c = 0;
    i = row, j = col;
    while (i >= 1 && j >= 1 && board[i][j] == cur_player) --i, --j, ++c;
    int k = row, l = col, t = 0;
    while (k <= 15 && l <= 15 && board[k][l] == cur_player) ++k, ++l, ++c;
    while (i >= 1 && j >= 1 && board[i][j] == '.') --i, --j, ++t;
    while (k <= 15 && l <= 15 && board[k][l] == '.') ++k, ++l, ++t;
    if (c >= 4 && t >= 2) pts += 2;

    c = 0;
    i = row, j = col;
    while (i >= 1 && j <= 15 && board[i][j] == cur_player) --i, ++j, ++c;
    k = row, l = col, t = 0;
    while (k <= 15 && l >= 1 && board[k][l] == cur_player) ++k, --l, ++c;
    while (i >= 1 && j <= 15 && board[i][j] == '.') --i, ++j, ++t;
    while (k <= 15 && l >= 1 && board[k][l] == '.') ++k, --l, ++t;
    if (c >= 4 && t >= 2) pts += 2;

    return pts;
}

bool ThreeInARowOpponent(char cur_player) {

    // check if there is 3 in a row without being blocked

    for (int row = 1; row <= 15; ++row) {
        for (int col = 1; col <= 15; ++col) {
            int i = row, j = row;
            int c = 0;
            while (i >= 1 && board[i][col] == cur_player) --i, ++c;
            while (j <= 15 && board[j][col] == cur_player) ++j, ++c;
            if (c == 3 && is_valid_move(i, col) && is_valid_move(j, col)) return true;

            i = col, j = col, c = 0;
            while (i >= 1 && board[row][i] == cur_player) --i, ++c;
            while (j <= 15 && board[row][j] == cur_player) ++j, ++c;
            if (c == 3 && is_valid_move(row, i) && is_valid_move(row, j)) return true;

            i = row, j = col, c = 0;
            int k = row, l = col;
            while (i >= 1 && j >= 1 && board[i][j] == cur_player) --i, --j, ++c;
            while (k <= 15 && l <= 15 && board[k][l] == cur_player) ++k, ++l, ++c;
            if (c == 3 && is_valid_move(i, j) && is_valid_move(k, l)) return true;

            i = row, j = col, c = 0;
            k = row, l = col;
            while (i >= 1 && j <= 15 && board[i][j] == cur_player) --i, ++j, ++c;
            while (k <= 15 && l >= 1 && board[k][l] == cur_player) ++k, --l, ++c;
            if (c == 3 && is_valid_move(i, j) && is_valid_move(k, l)) return true;
        }
    }
    return false;
}

bool AroundTheCenter(int row, int col) {
    // check if the move is around the center
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (row + i >= 1 && row + i <= 15 && col + j >= 1 && col + j <= 15 && board[row + i][col + j] != '.') {
                if (row + i != row || col + j != col) return true;
            }
        }
    }
    return false;
}

int MoveGoodness(char cur_player, int row, int col) {

    // return how good of the move given that cur_player just made a move resulting in the current board
    noth = 0;
    int mx = 0;
    if (isWinningState(cur_player, row, col)) return 100000;
    bool tmp = isWinningState2(cur_player, row, col);
    if (IsLosingState(cur_player)) {
        if (noth) return -500;
        mx = max(mx, ThreeInARow(cur_player, row, col));
        if (AroundTheCenter(row, col)) mx += 2;
        if (mx) return -200;
        return -100000;
    }
    if (BlockOPsWin((cur_player == 'X' ? 'O' : 'X'), row, col)) return 20000;
    if (tmp) return 10000;
    if (isLosingState2(cur_player)) {
        if (noth) return -500;
        mx = max(mx, ThreeInARow(cur_player, row, col));
        if (AroundTheCenter(row, col)) mx += 2;
        if (mx) return -200;
        return -10000;
    }
    if (BlockOP_connectPath(cur_player, row, col)) {
        return 5000;
    }
    mx = 0;
    mx = max(mx, BlockOpponent(cur_player, row, col));
    mx = max(mx, ThreeInARow(cur_player, row, col));
    mx = max(mx, BlockOpponent2((cur_player == 'X' ? 'O' : 'X'), row, col));
    bool c = ThreeInARowOpponent((cur_player == 'X' ? 'O' : 'X'));
    if (AroundTheCenter(row, col) && !c) mx += 2;
    if (mx) return mx;
    if (c) return -5;
    return 1;
}

ScoreOfaMove min_turn(int alpha, int beta, int depth, int evaluation);

ScoreOfaMove max_turn(int alpha, int beta, int depth, int evaluation) {
    int board_value = is_terminated();
    // evaluation = MoveGoodness * (X = last played ? 1 : -1)

    if (depth == 0 || board_value != 0) return { evaluation , {0, 0} };

    vector <ii> possible_moves = actions();
    vector <ScoreOfaMove> moves;
    for (int i = 0; i < (int)possible_moves.size(); ++i) {
        board[possible_moves[i].first][possible_moves[i].second] = 'X';
        moves.push_back({ MoveGoodness('X', possible_moves[i].first, possible_moves[i].second), possible_moves[i] });
        board[possible_moves[i].first][possible_moves[i].second] = '.';
    }
    sort(moves.begin(), moves.end(), cmp);

    int best_score = -INF;
    ii best_action;
    for (int i = 0; i < min((int)moves.size(), 8 + 2 * depth); ++i) {
        ii move = moves[i].move;
        board[move.first][move.second] = 'X';
        int score = min_turn(alpha, beta, depth - 1, moves[i].score).score;
        board[move.first][move.second] = '.';

        if (score > best_score) {
            best_score = score;
            best_action = move;
        }
        alpha = max(alpha, best_score);
        if (beta <= alpha) break;
    }

    return { best_score, best_action };
}

ScoreOfaMove min_turn(int alpha, int beta, int depth, int evaluation) {
    int board_value = is_terminated();
    // evaluation = MoveGoodness * (X = last played ? 1 : -1)

    if (depth == 0 || board_value != 0) return { evaluation , {0, 0} };

    vector <ii> possible_moves = actions();
    vector <ScoreOfaMove> moves;
    for (int i = 0; i < (int)possible_moves.size(); ++i) {
        board[possible_moves[i].first][possible_moves[i].second] = 'O';
        moves.push_back({ MoveGoodness('O', possible_moves[i].first, possible_moves[i].second), possible_moves[i] });
        board[possible_moves[i].first][possible_moves[i].second] = '.';
    }
    sort(moves.begin(), moves.end(), cmp);

    int best_score = INF;
    ii best_action;
    for (int i = 0; i < min((int)moves.size(), 8 + 2 * depth); ++i) {
        ii move = moves[i].move;
        board[move.first][move.second] = 'O';
        int score = max_turn(alpha, beta, depth - 1, -moves[i].score).score;
        board[move.first][move.second] = '.';

        if (score < best_score) {
            best_score = score;
            best_action = move;
        }
        beta = min(beta, best_score);
        if (beta <= alpha) break;
    }
    return { best_score, best_action };
}


ii minimax() {
    return min_turn(-INF, INF, min(6, cnt_moves / 2 + 1), 0).move;
}



bool valid(int x, int y)
{
    return y > 0 && x > 0 && x <= boardSize && y <= boardSize;
}




void botMove(int& x, int& y)
{
    ShowCur(0);
    ii move = minimax();
    x = move.first;
    y = move.second;
    ShowCur(1);
}

void makeMove(char player, int row, int col) {

    board[row][col] = player;

    moveTo(row, col);
    if (player == 'X') {
        setColor(15, 4);
        cout << 'X';
    }
    else if (player == 'O') {
        setColor(15, 1);
        cout << 'O';
    }
    else cout << ' ';
    moveTo(row, col);
}

void displayWinLine(int z) {
    // truoc khi goi ham nay thi tai dau do' phai goi ham is_terminated truoc de cap nhat Winning_Position va win_type

    vector <ii> winning_pos;
    winning_pos.push_back(Winning_Position);
    int x = Winning_Position.first;
    int y = Winning_Position.second;

    if (win_type == 1) {
        int i = x, j = y - 1;
        while (j >= 1 && board[i][j] == board[x][y]) winning_pos.push_back({ i, j }), --j;
        i = x, j = y + 1;
        while (j <= 15 && board[i][j] == board[x][y]) winning_pos.push_back({ i, j }), ++j;
    }
    else if (win_type == 2) {
        int i = x - 1, j = y;
        while (i >= 1 && board[i][j] == board[x][y]) winning_pos.push_back({ i, j }), --i;
        i = x + 1, j = y;
        while (i <= 15 && board[i][j] == board[x][y]) winning_pos.push_back({ i, j }), ++i;
    }
    else if (win_type == 3) {
        int i = x - 1, j = y - 1;
        while (i >= 1 && j >= 1 && board[i][j] == board[x][y]) winning_pos.push_back({ i, j }), --i, --j;
        i = x + 1, j = y + 1;
        while (i <= 15 && j <= 15 && board[i][j] == board[x][y]) winning_pos.push_back({ i, j }), ++i, ++j;
    }
    else {
        int i = x - 1, j = y + 1;
        while (i >= 1 && j <= 15 && board[i][j] == board[x][y]) winning_pos.push_back({ i, j }), --i, ++j;
        i = x + 1, j = y - 1;
        while (i <= 15 && j >= 1 && board[i][j] == board[x][y]) winning_pos.push_back({ i, j }), ++i, --j;
    }

    for (int blinking_time = 0; blinking_time < 5; ++blinking_time) {
        for (int u = 0; u < (int)winning_pos.size(); ++u) {
            int i = winning_pos[u].first;
            int j = winning_pos[u].second;
            moveTo(i, j);
            setColor(15, z);
            cout << board[i][j] << " ";
            Sleep(100);
            moveTo(i, j);
            setColor(z, 15);
            cout << board[i][j] << " ";
        }
        Sleep(300);
    }
}

void startGame(bool vsBot, bool isNewGame, int XX, int YY, string name1, string name2, vector<ii> Data, string fileName, int Xscore, int Oscore) {
    int tmp1 = Xscore;
    int tmp2 = Oscore;
playAgain:
    srand(time(0));
    system("cls");
    char cur_player;
    int x, y;
    moveMade.clear();
    ShowCur(1);
    setColor(15, 0);
    drawBoard(XX, YY, name1, name2, Xscore, Oscore, fileName);
    if (isNewGame) {
        cnt_moves = 0;
        cur_player = 'X';
        x = 8, y = 8;
        moveTo(x, y);
        for (int i = 1; i <= 15; ++i)
            for (int j = 1; j <= 15; ++j)
                board[i][j] = '.';
    }
    else {
        Xscore = tmp1;
        Oscore = tmp2;
        for (int i = 1; i <= 15; ++i)
            for (int j = 1; j <= 15; ++j)
                board[i][j] = '.';
        cur_player = 'X';
        for (ii tmp : Data) {
            if (cur_player == 'O') ++cnt_moves;
            makeMove(cur_player, tmp.first, tmp.second);
            board[tmp.first][tmp.second] = cur_player;
            cur_player = (cur_player == 'X' ? 'O' : 'X');
        }
        moveMade = Data;
        if (Data.empty()) x = y = 8;
        else {
            x = Data.back().first;
            y = Data.back().second;
        }
    }
    drawWord_IN_MATCH(XX - 14, YY - 9, 15, 0);
    string scoreX = "Score: " + to_string(Xscore);
    string scoreO = "Score: " + to_string(Oscore);
    string player1 = "Player: " + name1;
    string player2 = "Player: " + name2;
    printCenteredAt(XX - 26, YY + 9, scoreX);
    printCenteredAt(XX - 26, YY + 10, player1);
    printCenteredAt(XX - 8 + 4 * boardmaxSize, YY + 9, scoreO);
    printCenteredAt(XX - 8 + 4 * boardmaxSize, YY + 10, player2);
    decorate_draw(XX - 39, YY + 12, "ARTS/amongus_bnw.txt");
    decorate_draw(XX - 22 + 4 * boardmaxSize, YY + 12, "ARTS/amongus_bnw_reversed.txt");
    int state = 0;
    bool nuh_uh = 0;
    while (!state) {
        COORD currentPos;
        saveCurPos(currentPos);
        if (cur_player == 'X') {
            ShowCur(0);
            drawX(XX - 30, YY + 2, 15, 12);
            decorate_draw(XX - 39, YY + 12, "ARTS/amongus2.txt");
            drawO(XX - 12 + 4 * boardmaxSize, YY + 2, 15, 8);
            decorate_draw(XX - 22 + 4 * boardmaxSize, YY + 12, "ARTS/amongus_bnw_reversed.txt");
            setPos(currentPos.X, currentPos.Y);
            ShowCur(1);
        }
        else {
            ShowCur(0);
            drawX(XX - 30, YY + 2, 15, 8);
            decorate_draw(XX - 39, YY + 12, "ARTS/amongus_bnw.txt");
            drawO(XX - 12 + 4 * boardmaxSize, YY + 2, 15, 9);
            decorate_draw(XX - 22 + 4 * boardmaxSize, YY + 12, "ARTS/amongus2_reversed.txt");
            setPos(currentPos.X, currentPos.Y);
            ShowCur(1);
        }
        moveTo(x, y);

        if (cur_player == 'O' && vsBot) {
            ++cnt_moves;
            botMove(x, y);
            ShowCur(0);
            moveTo(x, y);
            board[x][y] = cur_player;
            state = is_terminated();
        }
        else {
            sleep_for(milliseconds(50));
            while (1) {
                int Key = isNextMove();
                if (Key == 0 && board[x][y] == '.') break;
                if (Key == 1 && x > 1) x -= 1;
                if (Key == 2 && y > 1) y -= 1;
                if (Key == 3 && x < boardSize) x += 1;
                if (Key == 4 && y < boardSize) y += 1;
                if (Key == 5) { // exit game
                    drawOutBoard(XX - 9, YY + 2 * boardSize + 1, 4);
                    while (1) {
                        char key = _getch();
                        if (key == 'N' || key == 'n') {
                            break;
                        }
                        else if (key == 'Y' || key == 'y') {
                            return;
                        }
                    }
                    drawOutBoard(XX - 9, YY + 2 * boardSize + 1, 5);
                    ShowCur(1);
                }
                if (Key == 6) { // Undo
                    if (cnt_moves > 0) --cnt_moves;
                    for (int i = 0; i < (vsBot ? 2 : 1); i++) if (moveMade.size()) {
                        x = moveMade.back().first, y = moveMade.back().second;
                        moveMade.pop_back();
                        makeMove('.', x, y);
                        cur_player = (cur_player == 'X' ? 'O' : 'X');
                        if (cur_player == 'X') {
                            ShowCur(0);
                            drawX(XX - 30, YY + 2, 15, 12);
                            decorate_draw(XX - 39, YY + 12, "ARTS/amongus2.txt");
                            drawO(XX - 12 + 4 * boardmaxSize, YY + 2, 15, 8);
                            decorate_draw(XX - 22 + 4 * boardmaxSize, YY + 12, "ARTS/amongus_bnw_reversed.txt");
                            setPos(currentPos.X, currentPos.Y);
                            ShowCur(1);
                        }
                        else {
                            ShowCur(0);
                            drawX(XX - 30, YY + 2, 15, 8);
                            decorate_draw(XX - 39, YY + 12, "ARTS/amongus_bnw.txt");
                            drawO(XX - 12 + 4 * boardmaxSize, YY + 2, 15, 9);
                            decorate_draw(XX - 22 + 4 * boardmaxSize, YY + 12, "ARTS/amongus2_reversed.txt");
                            setPos(currentPos.X, currentPos.Y);
                            ShowCur(1);
                        }
                        moveTo(x, y);
                    }
                }
                if (Key == 7) { // save game
                    saveGame(XX, YY, moveMade, Xscore, Oscore, name1, name2, fileName, vsBot);
                    return;
                }
                moveTo(x, y);
            }
            board[x][y] = cur_player;
            state = is_terminated();
        }
        moveMade.push_back({ x, y });


        makeMove(cur_player, x, y);
        cur_player = (cur_player == 'X' ? 'O' : 'X');
        ShowCur(1);
        if ((int)moveMade.size() == boardSize * boardSize) {
            cur_player = '.';
            break;
        }
    }
    if (cur_player == 'X') Oscore++;
    else if (cur_player == 'O') Xscore++;
    int z = (cur_player == 'X' ? 1 : 4);
    if (cur_player != '.') displayWinLine(z);
    ShowCur(0);
    drawEndMatch(XX - 20, YY - 12, 11, 74);
    if (cur_player == 'O') {
        decorate_draw(XX - 18, YY - 12, "ARTS/amongus2_short.txt");
        drawWord_X_WIN(XX + 12, YY - 9, 15, 4);
    }
    else if (cur_player == 'X') {
        decorate_draw(XX - 18, YY - 12, "ARTS/amongus2_short_blue.txt");
        drawWord_O_WIN(XX + 12, YY - 9, 15, 1);
    }
    else {
        decorate_draw(XX - 18, YY - 12, "ARTS/amongus2_short_bnw.txt");
        drawWord("DRAW", XX + 12, YY - 9, 15, 0);
    }

    setPos(XX - (cur_player == 'O') + 11, YY - 3);
    setColor(15, 8);  cout << (*selectedLanguage)["<< Press Y to continue or N to exit >>"];
    setColor(15, 0);

    while (true) {
        char key = _getch();
        if (key == 'N' || key == 'n') {
            break;
        }
        else if (key == 'Y' || key == 'y') {
            isNewGame = 1;
            goto playAgain;
        }
    }
}
