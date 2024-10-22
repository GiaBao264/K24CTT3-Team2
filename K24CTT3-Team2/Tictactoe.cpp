#include "Tictactoe.h"
#include "Library.h"
#include "Console.h"
#include "Graphic.h"
#include "MainCaro.h"

int dx[]{ -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[]{ -1, 0, 1, -1, 1, 0, -1, 1 };

const int INF = 1e9;
const int N = 17;

struct ScoreOfaMove {
    int score;
    pair <int, int> move;
};

bool cmp(ScoreOfaMove x, ScoreOfaMove y) {
    return x.score > y.score;
}

ScoreOfaMove min_turn(int alpha, int beta);
ScoreOfaMove max_turn(int alpha, int beta);

ii Winning_Position;
char cur_player;
int win_type;   
char board[N][N];
vector <ii> moveMade;

char player(){
     
     // given a current board, return to the player who has the next turn

     int count_X = 0;
     int count_O = 0;

     for (int i = 1; i <= 15; ++i)
        for (int j = 1; j <= 15; ++j){
            if (board[i][j] == 'X') count_X++;
            else if (board[i][j] == 'O') count_O++;
        }
    
    if (count_X == count_O) return 'X';
    return 'O';
}

bool is_valid_move(int row, int col){
    
    // check if the move is valid
    
    if (row < 1 || row > 15 || col < 1 || col > 15) return false;
    if (board[row][col] != '.') return false;
    return true;
}

bool valid_cell(int row, int col){
    
    // check if the cell is valid
    
    if (row < 1 || row > 15 || col < 1 || col > 15) return false;
    return true;
}

vector <ii> actions(){
    
    // return a vector of all possible actions
    
    vector<ii> possible_moves;
    for (int i = 1; i <= 15; ++i)
        for (int j = 1; j <= 15; ++j)
            if (board[i][j] == '.'){
                bool ok = 0;
                for (int k = -2; k <= 2; ++k)
                    for (int l = -2; l <= 2; ++l)
                         if (i + k >= 1 && i + k <= 15 && j + l >= 1 && j + l <= 15)
                            if (board[i + k][j + l] != '.') ok = 1;
                if (ok) possible_moves.push_back({i, j});
            }
    return possible_moves;
}

int is_terminated(){
    // -1 if no one can make move
    // 0 if the game is still going
    // 1 if X wins
    // 2 if O wins
    if (!actions().size()) return -1;
    for (int i = 1; i <= 15; ++i) {
        for (int j = 1; j <= 15; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') continue;
            int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
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

bool isWinningState(int row, int col){
    
    // check if there is a 5 in a row or 4 in a row without blocked
    
    int i = row, j = row;
    while (i >= 1 && board[i][col] == cur_player) --i;
    while (j <= 15 && board[j][col] == cur_player) ++j;
    if (j - i >= 6) return true;
    if (j - i == 5 && is_valid_move(i, col) && is_valid_move(j, col)) return true;
    i = col, j = col;
    while (i >= 1 && board[row][i] == cur_player) --i;
    while (j <= 15 && board[row][j] == cur_player) ++j;
    if (j - i >= 6) return true;
    if (j - i == 5 && is_valid_move(row, i) && is_valid_move(row, j)) return true;
    int c = 0;
    i = row, j = col;
    while (i >= 1 && j >= 1 && board[i][j] == cur_player) --i, --j, ++c;
    int k = row, l = col;
    while (k <= 15 && l <= 15 && board[k][l] == cur_player) ++k, ++l, ++c;
    if (c >= 6) return true;
    if (c == 5 && is_valid_move(i, j) && is_valid_move(k, l)) return true;
    c = 0;
    i = row, j = col;
    while (i >= 1 && j <= 15 && board[i][j] == cur_player) --i, ++j, ++c;
    k = row, l = col;
    while (k <= 15 && l >= 1 && board[k][l] == cur_player) ++k, --l, ++c;
    if (c >= 6) return true;
    if (c == 5 && is_valid_move(i, j) && is_valid_move(k, l)) return true;
    return false;
}

bool IsLosingState(){
     
     // check if opponent has 3 in a row without being blocked || opponent has 4 in a row with 1 blocked
     // case 1 no phai trong nhu the nay: . O O O . .

    char opponent = (cur_player == 'X' ? 'O' : 'X');

     for (int row = 1; row <= 15; ++row){
        for (int col = 1; col <= 15; ++col){
             if (board[row][col] == opponent){
                 int i = row, j = row, k, l;
                 int c = 0;
                 while (i >= 1 && board[i][col] == opponent) --i, ++c;
                 while (j <= 15 && board[j][col] == opponent) ++j, ++c;
                 if (((c == 4 && is_valid_move(i, col) && is_valid_move(j, col)) && (is_valid_move(i - 1, col) || is_valid_move(j + 1, col)))||
                     (c == 5 && (is_valid_move(i, col) || is_valid_move(j, col)))) return true;

                 i = col, j = col, c = 0;
                 while (i >= 1 && board[row][i] == opponent) --i, ++c;
                 while (j <= 15 && board[row][j] == opponent) ++j, ++c;
                 if (((c == 4 && is_valid_move(row, i) && is_valid_move(row, j)) && (is_valid_move(row, i - 1) || is_valid_move(row, j + 1))) ||
                     (c == 5 && (is_valid_move(row, i) || is_valid_move(row, j)))) return true;

                 i = row, j = col, k = row, l = col, c = 0;
                 while (i >= 1 && j >= 1 && board[i][j] == opponent) --i, --j, ++c;
                 while (k <= 15 && l <= 15 && board[k][l] == opponent) ++k, ++l, ++c;
                 if (((c == 4 && is_valid_move(i, j) && is_valid_move(k, l)) && (is_valid_move(i - 1, j - 1) || is_valid_move(k + 1, l + 1))) ||
                     (c == 5 && (is_valid_move(i, j) || is_valid_move(k, l)))) return true;
                
                 i = row, j = col, k = row, l = col, c = 0;
                 while (i >= 1 && j <= 15 && board[i][j] == opponent) --i, ++j, ++c;
                 while (k <= 15 && l >= 1 && board[k][l] == opponent) ++k, --l, ++c;
                 if (((c == 4 && is_valid_move(i, j) && is_valid_move(k, l)) && (is_valid_move(i - 1, j + 1) || is_valid_move(k + 1, l - 1))) ||
                     (c == 5 && (is_valid_move(i, j) || is_valid_move(k, l)))) return true;
             }
        }
     }
     return false;
}

bool BlockOpponent(){
     
     // check if opponent has 4 in a row with 2 blocked || opponent has 3 in a row with 1 blocked
     
     char opponent = (cur_player == 'X' ? 'O' : 'X');
     for (int row = 1; row <= 15; ++row)
        for (int col = 1; col <= 15; ++col)
             if (board[row][col] == opponent){
                 int i = row, j = col;
                 int c = 0;
                 while (i >= 1 && board[i][col] == opponent) --i, ++c;
                 while (j <= 15 && board[j][col] == opponent) ++j, ++c;
                 if (c >= 4 && (board[i][col] != '.' || board[j][col] != '.')) return true;

                 i = col, j = col, c = 0;
                 c = 0;
                 while (i >= 1 && board[row][i] == opponent) --i, ++c;
                 while (j <= 15 && board[row][j] == opponent) ++j, ++c;
                 if (c >= 4 && (board[row][i] != '.' || board[row][j] != '.')) return true;

                 i = row, j = col, c = 0;
                 int k = row, l = col;
                 while (i >= 1 && j >= 1 && board[i][j] == opponent) --i, --j, ++c;
                 while (k <= 15 && l <= 15 && board[k][l] == opponent) ++k, ++l, ++c;
                 if (c >= 4 && (board[i][j] != '.' || board[k][l] != '.')) return true;

                 i = row, j = col, c = 0;
                 k = row, l = col;
                 while (i >= 1 && j <= 15 && board[i][j] == opponent) --i, ++j, ++c;
                 while (k <= 15 && l >= 1 && board[k][l] == opponent) ++k, --l, ++c;
                 if (c >= 4 && (board[i][j] != '.' || board[k][l] != '.')) return true;
             }
     return false;
}

bool ThreeInARow(char cur_player, int desire){

     // check if there is a 3 in a row without being blocked

     for (int row = 1; row <= 15; ++row){
        for (int col = 1; col <= 15; ++col){
             int i = row, j = row;
             int c = 0;
             while (i >= 1 && board[i][col] == cur_player) --i, ++c;
             while (j <= 15 && board[j][col] == cur_player) ++j, ++c;
             if (c == desire && is_valid_move(i, col) && is_valid_move(j, col)) return true;

             i = col, j = col, c = 0;
             while (i >= 1 && board[row][i] == cur_player) --i, ++c;
             while (j <= 15 && board[row][j] == cur_player) ++j, ++c;
             if (c == desire && is_valid_move(row, i) && is_valid_move(row, j)) return true;

             i = row, j = col, c = 0;
             int k = row, l = col;
             while (i >= 1 && j >= 1 && board[i][j] == cur_player) --i, --j, ++c;
             while (k <= 15 && l <= 15 && board[k][l] == cur_player) ++k, ++l, ++c;
             if (c == desire && is_valid_move(i, j) && is_valid_move(k, l)) return true;

             i = row, j = col, c = 0;
             k = row, l = col;
             while (i >= 1 && j <= 15 && board[i][j] == cur_player) --i, ++j, ++c;
             while (k <= 15 && l >= 1 && board[k][l] == cur_player) ++k, --l, ++c;
             if (c == desire && is_valid_move(i, j) && is_valid_move(k, l)) return true;
        }
     }
     return false;
}

int MoveGoodness(char cur_player, int row, int col){
    
    // return how good of the move given that cur_player just made a move resulting in the current board
    
    // 5 in a row || 4 in a row without block = 10
    // opponent 3 in a row without being blocked || opponent 4 in a row with 1 blocked = -10
    // opponent 4 in a row with 2 blocked = 5
    // opponent 3 in a row with 1 blocked = 5
    // 3 in a row with no blocked = 2
    // opponent 2 in a row without being blocked = -1
    // else 0
    // Warning: must check the case near the border of the board (tips: coi nhung cai border la y nhu bi blocked boi doi thu)
    // khong can check opponent 5 in a row vi sao? vi neu opponent 5 in a row thi no da xet truoc cai -10 do va khong di vao nhanh do luon roi

    if (isWinningState(row, col)) return 10;
    if (IsLosingState()) return -10;
    if (BlockOpponent()) return 5;
    if (ThreeInARow(cur_player, 4)) return 2;
    if (ThreeInARow((cur_player == 'X' ? 'O' : 'X'), 3)) return -1;
    return 0;
}

ScoreOfaMove min_turn(int alpha, int beta);

ScoreOfaMove max_turn(int alpha, int beta){
    char cur_player = player();
    ii best_move = {0, 0};
    vector <ScoreOfaMove> MoveScore;

    vector <ii> tmp_actions = actions();
    for (int u = 0; u < (int)tmp_actions.size(); ++u){
        int i = tmp_actions[u].first, j = tmp_actions[u].second;
         board[i][j] = cur_player;
         MoveScore.push_back({MoveGoodness(cur_player, i, j), {i, j}});
         board[i][j] = '.';
    }
    sort(MoveScore.begin(), MoveScore.end(), cmp);
    
    int best_val = -1;
    for (int i = 0; i < (int)MoveScore.size(); ++i){
        int row = MoveScore[i].move.first;
        int col = MoveScore[i].move.second;
        board[row][col] = cur_player;
        int tmp = min_turn(alpha, beta).score;
        alpha = max(alpha, tmp);
        if (tmp >= best_val){
            best_val = tmp;
            best_move = {row, col};
        }
        board[row][col] = '.';
        if (beta <= alpha) break;
        if (best_val == 1) break;
    }
    return {best_val, best_move};
}

ScoreOfaMove min_turn(int alpha, int beta){
    char cur_player = player();
    ii best_move = {0, 0};
    vector <ScoreOfaMove> MoveScore;
    
	vector <ii> tmp_actions = actions();
	for (int u = 0; u < (int)tmp_actions.size(); ++u){
		 int i = tmp_actions[u].first, j = tmp_actions[u].second;
         board[i][j] = cur_player;
         MoveScore.push_back({MoveGoodness(cur_player, i, j), {i, j}});
         board[i][j] = '.';
    }
    sort(MoveScore.begin(), MoveScore.end(), cmp);

    int best_val = 1;
    for (int i = 0; i < (int)MoveScore.size(); ++i){
        int row = MoveScore[i].move.first;
        int col = MoveScore[i].move.second;
        board[row][col] = cur_player;
        int tmp = max_turn(alpha, beta).score;
        beta = min(beta, tmp);
        if (tmp <= best_val){
            best_val = tmp;
            best_move = {row, col};
        }
        board[row][col] = '.';
        if (beta <= alpha) break;
        if (best_val == -1) break;
    }
    return {best_val, best_move};
}

ii minimax(){
    
    // minimax function with alpha-beta pruning

     char cur_player = player();
     if (cur_player == 'X') return max_turn(-INF, INF).move;
     return min_turn(-INF, INF).move; 
     // remember when tell AI the best move, first have to check if the board is terminated or not
}

void makeMove(char player, int row, int col);

void botPlay(){
        
        // bot play with the player
        
        ii move = minimax();
        makeMove(cur_player, move.first, move.second);
}

void makeMove(char player, int row, int col){
     
     board[row][col] = player;

     setPos(row, col);
     if (player == 'X'){
         setColor(15, 4);
         cout << 'X';
     }
     else if (player == 'O'){
         setColor(15, 1);
         cout << 'O';
     }
     else cout << '.';
     setPos(row, col);
}

void displayWinLine(){
     // truoc khi goi ham nay thi tai dau do' phai goi ham is_terminated truoc de cap nhat Winning_Position va win_type

     vector <ii> winning_pos;
     winning_pos.push_back(Winning_Position);
     int x = Winning_Position.first;
     int y = Winning_Position.second;
     
     if (win_type == 1){
         int i = x, j = y - 1;
         while (j >= 1 && board[i][j] == board[x][y]) winning_pos.push_back({i, j}), --j;
         i = x, j = y + 1;
         while (j <= 15 && board[i][j] == board[x][y]) winning_pos.push_back({i, j}), ++j;
     }
     else if (win_type == 2){
          int i = x - 1, j = y;
          while (i >= 1 && board[i][j] == board[x][y]) winning_pos.push_back({i, j}), --i;
          i = x + 1, j = y;
          while (i <= 15 && board[i][j] == board[x][y]) winning_pos.push_back({i, j}), ++i;
     }
     else if (win_type == 3){
          int i = x - 1, j = y - 1;
          while (i >= 1 && j >= 1 && board[i][j] == board[x][y]) winning_pos.push_back({i, j}), --i, --j;
          i = x + 1, j = y + 1;
          while (i <= 15 && j <= 15 && board[i][j] == board[x][y]) winning_pos.push_back({i, j}), ++i, ++j;
     }
     else{
          int i = x - 1, j = y + 1;
          while (i >= 1 && j <= 15 && board[i][j] == board[x][y]) winning_pos.push_back({i, j}), --i, ++j;
          i = x + 1, j = y - 1;
          while (i <= 15 && j >= 1 && board[i][j] == board[x][y]) winning_pos.push_back({i, j}), ++i, --j;
     }

     for (int blinking_time = 0; blinking_time < 5; ++blinking_time){
          for (int u = 0; u < (int)winning_pos.size(); ++u){
               int i = winning_pos[u].first;
               int j = winning_pos[u].second;
               setPos(i, j);
               setColor(15, 4);
               cout << board[i][j] << " ";
               setPos(i, j);
               setColor(15, 0);
               cout << board[i][j] << " ";
          }
          Sleep(300);
     }
}
