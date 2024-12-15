#include "Library.h"
#include "Graphic.h"
#include "Language.h"
#include <map>
#define gameTheme 15, 0

map<string, string> english, vietnamese;

void dict() {
    english["    TRO CHOI MOI  "] = "     NEW GAME     ";
    english["    TAI TRO CHOI  "] = "     LOAD GAME    ";
    english["     THONG TIN    "] = "      ABOUT       ";
    english["     TRO GIUP     "] = "       HELP       ";
    english["     NGON NGU     "] = "     LANGUAGE     ";
    english["       THOAT      "] = "       EXIT       ";

    english[">> TRO CHOI MOI <<"] = ">>   NEW GAME   <<";
    english[">> TAI TRO CHOI <<"] = ">>   LOAD GAME  <<";
    english[">>   THONG TIN  <<"] = ">>     ABOUT    <<";
    english[">>   TRO GIUP   <<"] = ">>     HELP     <<";
    english[">>  NGON NGU  <<"] = ">>   LANGUAGE   <<";
    english[">>    THOAT    <<"] = ">>     EXIT     <<";

    // Loading Screen  
    english[" LOADING  "] = " LOADING  ";
    english["     Nhan ENTER de bat dau tro choi...      "] = "      Press ENTER to start the game...      ";

    // Board and Game Prompts  
    english["Ten Ban Co: "] = "Board's Name: ";
    english["[NULL]"] = "[NULL]";
    english["|  'I'- Luu  |  'U'- Quay Lai  |  'Esc'- Thoat  |"] = "|  'I'- Save  |  'U'- Undo  |  'Esc'- Exit  |";
    english[">> Ten Tap Tin:"] = ">> File's name:";
    english[">> Tap tin da ton tai, ban co muon thay the no? Nhan Y/N"] = ">> It already exists, do you want to replace it? Press Y/N";
    english[">> Ban co muon thoat? Nhan Y/N (Nho luu tro choi)"] = ">> Do you want to exit? Press Y/N (Remember to save game)";

    // Load Game Menu  
    english["      RONG       "] = "      EMPTY       ";
    english["     CHOI     "] = "     PLAY     ";
    english["    XOA    "] = "    DELETE    ";
    english["   DOI TEN   "] = "    RENAME    ";
    english[">>   CHOI   <<"] = ">>   PLAY   <<";
    english[">>  XOA  <<"] = ">>  DELETE  <<";
    english[">> DOI TEN <<"] = ">>  RENAME  <<";
    english[" Lua Chon: "] = " Choose: ";
    english[" Ten Moi:                                                         "] = " New Name:                                                         ";
    english[">> Da ton tai, ban co muon thay doi ten khac? Nhan Y/N"] = ">> It already exists, do you want to change another name? Press Y/N";

    // Player Names and Modes  
    english["TEN NGUOI CHOI: "] = "PLAYER NAME: ";
    english["[TEN BAN]"] = "[PLAYER]";
    english["May"] = "Bot";
    english["TEN NGUOI CHOI 1: "] = "PLAYER NAME 1: ";
    english["    [TEN]"] = "[player1]";
    english["TEN NGUOI CHOI 2: "] = "PLAYER NAME 2: ";
    english["    [TEN]"] = "[player2]";
    english["     CHOI VOI MAY     "] = "     PLAY WITH BOT     ";
    english["    CHOI VOI NGUOI    "] = "    PLAY WITH HUMAN    ";
    english[">>   CHOI VOI MAY   <<"] = ">>   PLAY WITH BOT   <<";
    english[">>  CHOI VOI NGUOI  <<"] = ">>  PLAY WITH HUMAN  <<";

    // About Section  
    english["HCMUS - 24CTT3 - Nhom 2:"] = "HCMUS - 24CTT3 - Group 2:";
    english["Giang vien: Dr.Truong Toan Thinh"] = "Lecturer: Dr.Truong Toan Thinh";
    english["24120240 - Vo Lan Tuan"] = "24120240 - Vo Lan Tuan";
    english["24120267 - Tran Huynh Gia Bao"] = "24120267 - Tran Huynh Gia Bao";
    english["24120249 - Vo Nguyen Viet Hoang"] = "24120249 - Vo Nguyen Viet Hoang";
    english["24120270 - Do Chi Cao"] = "24120270 - Do Chi Cao";
    english["24120238 - Pham Anh Tuan"] = "24120238 - Pham Anh Tuan";
    english["<< Nhan ESC de thoat >>"] = "<< Press ESC to exit >>";

    // Help Section  
    english["HUONG DAN BAN PHIM"] = "KEYBOARD GUIDE";
    english["CAC BUOC CHOI"] = "HOW TO PLAY";
    
    english["Len:        W           Len"] = "Go up:        W           Up";
    english["Xuong:      S          Xuong"] = "Go down:      S          Down";
    english["Trai:      A          Trai"] = "Go left:      A          Left";
    english["Phai:     D          Phai"] = "Go right:     D          Right";
    english["Danh dau:       Space       Enter"] = "Mark:       Space       Enter";
    english["Khac"] = "Other";
    english["Quay Lai: U    Luu: I    Thoat: Esc"] = "Undo: U    Save: I    Exit: Esc";

    // Game Information  
    english["Ban Co:"] = "CaroBoard:";
    english["Nguoi Choi:"] = "Players:";
    english["Luu Luong:"] = "Turn:";
    english["Muc Tieu:"] = "Target:";
    english["Hoa:"] = "Tie:";
    english["Square grid of 15x15 cells (225 cells)."] = "Square grid of 15x15 cells (225 cells).";
    english["Two players, using two types of symbols (usually X and O)."] = "Two players, using two types of symbols (usually X and O).";
    english["Players take turns marking an empty square on the board with their symbol."] = "Players take turns marking an empty square on the board with their symbol.";
    english["The winner is the first person to get 5 consecutive symbols in one of"] = "The winner is the first person to get 5 consecutive symbols in one of";
    english["the directions: horizontal, vertical, or diagonal."] = "the directions: horizontal, vertical, or diagonal.";
    english["The game is a draw if the board is full and no one wins."] = "The game is a draw if the board is full and no one wins.";
    english["Press ENTER to start the game..."] = "Press ENTER to start the game...";
    english["     NEW GAME     "] = "     NEW GAME     ";
    english["     LOAD GAME    "] = "     LOAD GAME    ";
    english["      ABOUT       "] = "      ABOUT       ";
    english["       HELP       "] = "       HELP       ";
    english["     LANGUAGE     "] = "     LANGUAGE     ";
    english["       EXIT       "] = "       EXIT       ";

    english[">>   NEW GAME   <<"] = ">>   NEW GAME   <<";
    english[">>   LOAD GAME  <<"] = ">>   LOAD GAME  <<";
    english[">>     ABOUT    <<"] = ">>     ABOUT    <<";
    english[">>     HELP     <<"] = ">>     HELP     <<";
    english[">>   LANGUAGE   <<"] = ">>   LANGUAGE   <<";
    english[">>     EXIT     <<"] = ">>     EXIT     <<";

	english["<< Press Y to continue or N to exit >>"] = "<< Press Y to continue or N to exit >>";
	english["<< Press ESC to exit >>"] = "<< Nhan ESC de thoat >>";
	english["<< Press ENTER to continue >>"] = "<< Nhan ENTER de tiep tuc >>";
	english["<< Nhan Y de tiep tuc hoac N de thoat >>"] = "<< Press Y to continue or N to exit >>";
	english["        ENGLISH       "] = "        ENGLISH       ";
	english["       TIENG ANH     "] = "        ENGLISH       ";

    english[" LOADING  "] = " LOADING  ";
    english["      Press ENTER to start the game...      "] = "      Press ENTER to start the game...      ";
    english["Board's Name: "] = "Board's Name: ";
    english["[NULL]"] = "[NULL]";
    english["|  'I'- Save  |  'U'- Undo  |  'Esc'- Exit  |"] = "|  'I'- Save  |  'U'- Undo  |  'Esc'- Exit  |";
    english[">> File's name:"] = ">> File's name:";
    english[">> It already exists, do you want to replace it? Press Y/N"] = ">> It already exists, do you want to replace it? Press Y/N";
    english[">> Do you want to exit? Press Y/N (Remember to save game)"] = ">> Do you want to exit? Press Y/N (Remember to save game)";

    english["      EMPTY       "] = "      EMPTY       ";
    english["     PLAY     "] = "     PLAY     ";
    english["    DELETE    "] = "    DELETE    ";
    english["    RENAME    "] = "    RENAME    ";
    english[">>   PLAY   <<"] = ">>   PLAY   <<";
    english[">>  DELETE  <<"] = ">>  DELETE  <<";
    english[">>  RENAME  <<"] = ">>  RENAME  <<";
    english[" Choose: "] = " Choose: ";
    english["      EMPTY       "] = "      EMPTY       ";
    english[" New Name:                                                         "] = " New Name:                                                         ";
    english[">> It already exists, do you want to change another name? Press Y/N"] = ">> It already exists, do you want to change another name? Press Y/N";

    english["PLAYER NAME: "] = "PLAYER NAME: ";
    english["[PLAYER]"] = "[PLAYER]";
    english["Bot"] = "Bot";
    english["PLAYER NAME 1: "] = "PLAYER NAME 1: ";
    english["[player1]"] = "[player1]";
    english["PLAYER NAME 2: "] = "PLAYER NAME 2: ";
    english["[player2]"] = "[player2]";
    english["     PLAY WITH BOT     "] = "     PLAY WITH BOT     ";
    english["    PLAY WITH HUMAN    "] = "    PLAY WITH HUMAN    ";
    english[">>   PLAY WITH BOT   <<"] = ">>   PLAY WITH BOT   <<";
    english[">>  PLAY WITH HUMAN  <<"] = ">>  PLAY WITH HUMAN  <<";

    english["HCMUS - 24CTT3 - Group 2:"] = "HCMUS - 24CTT3 - Group 2:";
    english["Lecturer: Dr.Truong Toan Thinh"] = "Lecturer: Dr.Truong Toan Thinh";
    english["24120240 - Vo Lan Tuan"] = "24120240 - Vo Lan Tuan";
    english["24120267 - Tran Huynh Gia Bao"] = "24120267 - Tran Huynh Gia Bao";
    english["24120249 - Vo Nguyen Viet Hoang"] = "24120249 - Vo Nguyen Viet Hoang";
    english["24120270 - Do Chi Cao"] = "24120270 - Do Chi Cao";
    english["24120238 - Pham Anh Tuan"] = "24120238 - Pham Anh Tuan";
    english["<< Press ESC to exit >>"] = "<< Press ESC to exit >>";

    english["KEYBOARD GUIDE"] = "KEYBOARD GUIDE";
    english["HOW TO PLAY"] = "HOW TO PLAY";
    english["Player 1"] = "Player 1";
    english["Player 2"] = "Player 2";


    english["Go up:        W           Up"] = "Go up:        W           Up";
    english["Go down:      S          Down"] = "Go down:      S          Down";
    english["Go left:      A          Left"] = "Go left:      A          Left";
    english["Go right:     D          Right"] = "Go right:     D          Right";
    english["Mark:       Space       Enter"] = "Mark:       Space       Enter";
    english["    Len:        W          Len   "] = "Go up:        W           Up";
    english["    Xuong:      S          Xuong "] = "Go down:      S          Down";
    english["    Trai:       A          Trai  "] = "Go left:      A          Left";
    english["    Phai:       D          Phai  "] = "Go right:     D          Right";
    english["    Danh dau:   Space      Enter "] = "Mark:       Space       Enter";
    vietnamese["Nguoi Choi 1"] = "Nguoi Choi 1";
    vietnamese["  Nguoi Choi 2"] = "  Nguoi Choi 2";
    vietnamese["Player 1"] = "Nguoi Choi 1";
    vietnamese["Player 2"] = "  Nguoi Choi 2";
    english["Nguoi Choi 1"] = "Player 1";
    english["  Nguoi Choi 2"] = "Player 2";
    vietnamese["    Len:        W          Len   "] = "    Len:          W          Len";
    vietnamese["    Xuong:      S          Xuong "] = "    Xuong:        S          Xuong";
    vietnamese["    Trai:       A          Trai  "] = "    Trai:         A          Trai";
    vietnamese["    Phai:       D          Phai  "] = "    Phai:         D          Phai";
    vietnamese["    Danh dau:   Space      Enter "] = "    Danh dau:     Space      Enter";
    vietnamese["Go up:        W           Up"] = "    Len:        W          Len   ";
    vietnamese["Go down:      S          Down"] = "    Xuong:      S          Xuong ";
    vietnamese["Go left:      A          Left"] = "    Trai:       A          Trai  ";
    vietnamese["Go right:     D          Right"] = "    Phai:       D          Phai  ";
    vietnamese["Mark:       Space       Enter"] = "    Danh dau:   Space      Enter ";

    english["Other"] = "Other";
    english["Undo: U    Save: I    Exit: Esc"] = "Undo: U    Save: I    Exit: Esc";
    english["Language"] = "Language";
    english["Ngon ngu"] = "Language";
	english[">>      ENGLISH     <<"] = ">>      ENGLISH     <<";
	english[">>     VIETNAMESE    <<"] = ">>     VIETNAMESE    <<";
    english[">>     TIENG ANH    <<"] = ">>      ENGLISH     <<";
	english[">>     VIETNAMESE    <<"] = ">>     VIETNAMESE    <<";
    vietnamese[">>      ENGLISH     <<"] = ">>     TIENG ANH    <<";
    vietnamese[">>     VIETNAMESE    <<"] = ">>    TIENG VIET    <<";

    english["       VIETNAMESE      "] = "       VIETNAMESE      ";
    english["      TIENG VIET      "] = "       VIETNAMESE      ";
    english["CaroBoard:"] = "CaroBoard:";
    english["Players:"] = "Players:";
    english["Turn:"] = "Turn:";
    english["Target:"] = "Target:";
    english["Tie:"] = "Tie:";


    vietnamese["        ENGLISH       "] = "       TIENG ANH     ";
    vietnamese["       VIETNAMESE      "] = "      TIENG VIET      ";
	
    vietnamese["     NEW GAME     "] = "    TRO CHOI MOI  ";
    vietnamese["     LOAD GAME    "] = "    TAI TRO CHOI  ";
    vietnamese["      ABOUT       "] = "     THONG TIN    ";
    vietnamese["       HELP       "] = "     TRO GIUP     ";
    vietnamese["     LANGUAGE     "] = "     NGON NGU     ";
    vietnamese["       EXIT       "] = "       THOAT      ";

    vietnamese[">>   NEW GAME   <<"] = ">> TRO CHOI MOI <<";
    vietnamese[">>   LOAD GAME  <<"] = ">> TAI TRO CHOI <<";
    vietnamese[">>     ABOUT    <<"] = ">>   THONG TIN  <<";
    vietnamese[">>     HELP     <<"] = ">>   TRO GIUP   <<";
    vietnamese[">>   LANGUAGE   <<"] = ">>  NGON NGU  <<";
    vietnamese[">>     EXIT     <<"] = ">>    THOAT    <<";

	vietnamese["<< Press Y to continue or N to exit >>"] = " << Nhan Y de tiep tuc hoac N de thoat >> ";

    vietnamese[" LOADING  "] = " LOADING  ";
    vietnamese["      Press ENTER to start the game...      "] = "     Nhan ENTER de bat dau tro choi...      ";
    vietnamese["Board's Name: "] = "Ten Ban Co: ";
    vietnamese["[NULL]"] = "[NULL]";
    vietnamese["|  'I'- Save  |  'U'- Undo  |  'Esc'- Exit  |"] = "|  'I'- Luu  |  'U'- Quay Lai  |  'Esc'- Thoat  |";
    vietnamese[">> File's name:"] = ">> Ten Tap Tin:";
    vietnamese[">> It already exists, do you want to replace it? Press Y/N"] = ">> Tap tin da ton tai, ban co muon thay the no? Nhan Y/N";
    vietnamese[">> Do you want to exit? Press Y/N (Remember to save game)"] = ">> Ban co muon thoat? Nhan Y/N (Nho luu tro choi)";

    vietnamese["      EMPTY       "] = "      RONG       ";
    vietnamese["     PLAY     "] = "     CHOI     ";
    vietnamese["    DELETE    "] = "    XOA    ";
    vietnamese["    RENAME    "] = "   DOI TEN   ";
    vietnamese[">>   PLAY   <<"] = ">>   CHOI   <<";
    vietnamese[">>  DELETE  <<"] = ">>  XOA  <<";
    vietnamese[">>  RENAME  <<"] = ">> DOI TEN <<";
    vietnamese[" Choose: "] = " Lua Chon: ";
    vietnamese["      EMPTY       "] = "      RONG       ";
    vietnamese[" New Name:                                                         "] = " Ten Moi:                                                         ";
    vietnamese[">> It already exists, do you want to change another name? Press Y/N"] = ">> Da ton tai, ban co muon thay doi ten khac? Nhan Y/N";

    vietnamese["PLAYER NAME: "] = "TEN NGUOI CHOI: ";
    vietnamese["[PLAYER]"] = "[TEN BAN]";
    vietnamese["Bot"] = "May";
    vietnamese["PLAYER NAME 1: "] = "TEN NGUOI CHOI 1: ";
    vietnamese["[player1]"] = "    [TEN]";
    vietnamese["PLAYER NAME 2: "] = "TEN NGUOI CHOI 2: ";
    vietnamese["[player2]"] = "    [TEN]";
    vietnamese["     PLAY WITH BOT     "] = "     CHOI VOI MAY     ";
    vietnamese["    PLAY WITH HUMAN    "] = "    CHOI VOI NGUOI    ";
    vietnamese[">>   PLAY WITH BOT   <<"] = ">>   CHOI VOI MAY   <<";
    vietnamese[">>  PLAY WITH HUMAN  <<"] = ">>  CHOI VOI NGUOI  <<";

    vietnamese["HCMUS - 24CTT3 - Group 2:"] = "HCMUS - 24CTT3 - Nhom 2:";
    vietnamese["Lecturer: Dr.Truong Toan Thinh"] = "Giang vien: Dr.Truong Toan Thinh";
    vietnamese["24120240 - Vo Lan Tuan"] = "24120240 - Vo Lan Tuan";
    vietnamese["24120267 - Tran Huynh Gia Bao"] = "24120267 - Tran Huynh Gia Bao";
    vietnamese["24120249 - Vo Nguyen Viet Hoang"] = "24120249 - Vo Nguyen Viet Hoang";
    vietnamese["24120270 - Do Chi Cao"] = "24120270 - Do Chi Cao";
    vietnamese["24120238 - Pham Anh Tuan"] = "24120238 - Pham Anh Tuan";
    vietnamese["<< Press ESC to exit >>"] = "<< Nhan ESC de thoat >>";

    vietnamese["KEYBOARD GUIDE"] = "HUONG DAN BAN PHIM";
    vietnamese["HOW TO PLAY"] = "CAC BUOC CHOI";
    
    vietnamese["Other"] = "Khac";
    vietnamese["Undo: U    Save: I    Exit: Esc"] = "Quay Lai: U    Luu: I    Thoat: Esc";

    vietnamese["CaroBoard:"] = "Ban Co:";
    vietnamese["Players:"] = "Nguoi Choi:";
    vietnamese["Turn:"] = "Luot di:";
    vietnamese["Target:"] = "Muc Tieu:";
    vietnamese["Tie:"] = "Hoa:";
    vietnamese["Square grid of 15x15 cells (225 cells)."] = "Bang 15x15 o (225 o).";
    vietnamese["Two players, using two types of symbols (usually X and O)."] = "Hai nguoi choi, su dung hai loai ky tu (thuong la X va O).";
    vietnamese["Players take turns marking an empty square on the board with their symbol."] = "Nguoi choi luan phien danh dau mot o trong bang bang ky tu cua ho.";
    vietnamese["The winner is the first person to get 5 consecutive symbols in one of"] = "Nguoi thang la nguoi dau tien co 5 ky tu lien tiep trong mot.";
    vietnamese["the directions: horizontal, vertical, or diagonal."] = "huong: theo ngang, doc, hoac cheo.";
    vietnamese["The game is a draw if the board is full and no one wins."] = "Tro choi ket thuc hoa neu bang day va khong ai thang.";
	vietnamese["Language"] = "Ngon Ngu";
    // Generated entries where the key and value are both the translated string  

    vietnamese["       TIENG ANH     "] = "       TIENG ANH     ";
    vietnamese["      TIENG VIET      "] = "      TIENG VIET      ";
    vietnamese[">>     TIENG ANH    <<"] = ">>     TIENG ANH    <<";
    vietnamese[">>    TIENG VIET    <<"] = ">>    TIENG VIET    <<";
    vietnamese["    TRO CHOI MOI  "] = "    TRO CHOI MOI  ";
    vietnamese["    TAI TRO CHOI  "] = "    TAI TRO CHOI  ";
    vietnamese["     THONG TIN    "] = "     THONG TIN    ";
    vietnamese["     TRO GIUP     "] = "     TRO GIUP     ";
    vietnamese["     NGON NGU     "] = "     NGON NGU     ";
    vietnamese["       THOAT      "] = "       THOAT      ";

    vietnamese[">> TRO CHOI MOI <<"] = ">> TRO CHOI MOI <<";
    vietnamese[">> TAI TRO CHOI <<"] = ">> TAI TRO CHOI <<";
    vietnamese[">>   THONG TIN  <<"] = ">>   THONG TIN  <<";
    vietnamese[">>   TRO GIUP   <<"] = ">>   TRO GIUP   <<";
    vietnamese[">>  NGON NGU  <<"] = ">>  NGON NGU  <<";
    vietnamese[">>    THOAT    <<"] = ">>    THOAT    <<";

    vietnamese[" << Nhan Y de tiep tuc hoac N de thoat >> "] = " << Nhan Y de tiep tuc hoac N de thoat >> ";

    vietnamese[" LOADING  "] = " LOADING  ";
    vietnamese["     Nhan ENTER de bat dau tro choi...      "] = "     Nhan ENTER de bat dau tro choi...      ";
    vietnamese["Ten Ban Co: "] = "Ten Ban Co: ";
    vietnamese["[NULL]"] = "[NULL]";
    vietnamese["|  'I'- Luu  |  'U'- Quay Lai  |  'Esc'- Thoat  |"] = "|  'I'- Luu  |  'U'- Quay Lai  |  'Esc'- Thoat  |";
    vietnamese[">> Ten Tap Tin:"] = ">> Ten Tap Tin:";
    vietnamese[">> Tap tin da ton tai, ban co muon thay the no? Nhan Y/N"] = ">> Tap tin da ton tai, ban co muon thay the no? Nhan Y/N";
    vietnamese[">> Ban co muon thoat? Nhan Y/N (Nho luu tro choi)"] = ">> Ban co muon thoat? Nhan Y/N (Nho luu tro choi)";

    vietnamese["      RONG       "] = "      RONG       ";
    vietnamese["     CHOI     "] = "     CHOI     ";
    vietnamese["    XOA    "] = "    XOA    ";
    vietnamese["    DONG TEN    "] = "    DONG TEN    ";
    vietnamese[">>   CHOI   <<"] = ">>   CHOI   <<";
    vietnamese[">>  XOA  <<"] = ">>  XOA  <<";
    vietnamese[">>  DONG TEN  <<"] = ">>  DONG TEN  <<";
    vietnamese[" Lua Chon: "] = " Lua Chon: ";
    vietnamese[" Ten Moi:                                                         "] = " Ten Moi:                                                         ";
    vietnamese[">> Da ton tai, ban co muon thay doi ten khac? Nhan Y/N"] = ">> Da ton tai, ban co muon thay doi ten khac? Nhan Y/N";

    vietnamese["TEN NGUOI CHOI: "] = "TEN NGUOI CHOI: ";
    vietnamese["[TEN BAN]"] = "[TEN BAN]";
    vietnamese["May"] = "May";
    vietnamese["TEN NGUOI CHOI 1: "] = "TEN NGUOI CHOI 1: ";
    vietnamese["    [TEN]"] = "    [TEN]";
    vietnamese["TEN NGUOI CHOI 2: "] = "TEN NGUOI CHOI 2: ";
    vietnamese["[nguoiChoi2]"] = "    [TEN]";
    vietnamese["     CHOI VOI MAY     "] = "     CHOI VOI MAY     ";
    vietnamese["    CHOI VOI NGUOI    "] = "    CHOI VOI NGUOI    ";
    vietnamese[">>   CHOI VOI MAY   <<"] = ">>   CHOI VOI MAY   <<";
    vietnamese[">>  CHOI VOI NGUOI  <<"] = ">>  CHOI VOI NGUOI  <<";

    vietnamese["HCMUS - 24CTT3 - Nhom 2:"] = "HCMUS - 24CTT3 - Nhom 2:";
    vietnamese["Giang vien: Dr.Truong Toan Thinh"] = "Giang vien: Dr.Truong Toan Thinh";
    vietnamese["24120240 - Vo Lan Tuan"] = "24120240 - Vo Lan Tuan";
    vietnamese["24120267 - Tran Huynh Gia Bao"] = "24120267 - Tran Huynh Gia Bao";
    vietnamese["24120249 - Vo Nguyen Viet Hoang"] = "24120249 - Vo Nguyen Viet Hoang";
    vietnamese["24120270 - Do Chi Cao"] = "24120270 - Do Chi Cao";
    vietnamese["24120238 - Pham Anh Tuan"] = "24120238 - Pham Anh Tuan";
    vietnamese["<< Nhan ESC de thoat >>"] = "<< Nhan ESC de thoat >>";

    vietnamese["HUONG DAN BAN PHIM"] = "HUONG DAN BAN PHIM";
    vietnamese["CAC BUOC CHOI"] = "CAC BUOC CHOI";
    
    vietnamese["Khac"] = "Khac";
    vietnamese["Quay Lai: U    Luu: I    Thoat: Esc"] = "Quay Lai: U    Luu: I    Thoat: Esc";

    vietnamese["Ban Co:"] = "Ban Co:";
    vietnamese["Nguoi Choi:"] = "Nguoi Choi:";
    vietnamese["Luu Luong:"] = "Luu Luong:";
    vietnamese["Muc Tieu:"] = "Muc Tieu:";
    vietnamese["Hoa:"] = "Hoa:";
    vietnamese["Ngon Ngu"] = "Ngon Ngu";

    vietnamese["PLAYER NAME: "] = "TEN CUA BAN:";
    english["TEN CUA BAN:"] = "PLAYER NAME: ";
    vietnamese["TEN CUA BAN:"] = "TEN CUA BAN:";
}



void language(int Xi, int Yi) {
    dict();
    system("cls");
    int XX = Xi - 6, YY = Yi + 1;
    string language;

    setColor(gameTheme);
    setPos(XX, YY + 5); cout << (*selectedLanguage)["Language"];

    struct languageMenu {
        int xxx, yyy, sizeee, bg_colorrr;
        string strr;

        void draw() {
            drawMenu2(xxx, yyy, sizeee, bg_colorrr, strr);
        }
        void draw2() {
            drawMenu3(xxx, yyy, sizeee, bg_colorrr, strr);
        }
    };

    languageMenu a1[2], a2[2];
    a1[0] = { XX + 3, YY + 10, 25, 15,  (*selectedLanguage)["        ENGLISH       "] };
    a1[1] = { XX + 3, YY + 15, 25, 15,  (*selectedLanguage)["       VIETNAMESE      "] };

    a2[0] = { XX + 4, YY + 11, 25, 15,  (*selectedLanguage)[">>      ENGLISH     <<"] };
    a2[1] = { XX + 4, YY + 16, 25, 15,  (*selectedLanguage)[">>     VIETNAMESE    <<"] };

    system("cls");
    int S = 0;

    while (true) {
        drawWord("Language", XX - 20, YY - 5, 15, 0);
        for (int i = 0; i < 2; ++i)
            a1[i].draw();
        a2[S].draw2();

        int inputNewGame = isNextMove();
        if (inputNewGame == 1 || inputNewGame == 3) S ^= 1;
        else if (inputNewGame == 0) {
			selectedLanguage = (S == 0) ? &english : &vietnamese;
            break;
        }
        else if (inputNewGame == 5) break;
    }

    /*setColor(11, 0);
    setPos(XX + 5, YY + 20); cout << (*selectedLanguage)["<< Press ESC to exit >>"];
    setColor(gameTheme);
    while (isNextMove() != 5);*/
}