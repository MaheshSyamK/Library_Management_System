#include "console_functions.hpp"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
string user_email;
string user_password;

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Delayer(string str) {
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
        Sleep(65);
    }
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

// Define Delayer_menu only once
void Delayer_menu(string S) {
    for (int i = 0; i < S.size(); i++) {
        cout << S[i];
        Sleep(0);
    }
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

