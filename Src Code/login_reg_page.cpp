#include "console_functions.hpp" // Include your console functions header
#include <iostream>
#include <windows.h>

using namespace std;

void login_reg_page() {
    system("CLS");
    string L1 = " --------------------------- \n";
    string L2 = "|                           |\n";
    string L3 = "|          1.LOGIN          |\n";
    string L4 = "|         2.REGISTER        |\n";
    string L5 = "|          3.BACK           |\n";
    string L7 = "|         CHOICE -          |\n";

    //************************************************************
    gotoxy(55, 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    Delayer_menu(L1);
    gotoxy(55, 5);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    Delayer_menu(L2);
    gotoxy(55, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    Delayer_menu(L3);
    gotoxy(55, 7);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    Delayer_menu(L2);
    gotoxy(55, 8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    Delayer_menu(L1);

    //--------------------------------------
    //************************************************************
    gotoxy(55, 10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    Delayer_menu(L1);
    gotoxy(55, 11);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    Delayer_menu(L2);
    gotoxy(55, 12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    Delayer_menu(L4);
    gotoxy(55, 13);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    Delayer_menu(L2);
    gotoxy(55, 14);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    Delayer_menu(L1);

    //--------------------------------------
    //************************************************************
    gotoxy(55, 16);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    Delayer_menu(L1);
    gotoxy(55, 17);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    Delayer_menu(L2);
    gotoxy(55, 18);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    Delayer_menu(L5);
    gotoxy(55, 19);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    Delayer_menu(L2);
    gotoxy(55, 20);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    Delayer_menu(L1);

    //**************************
    gotoxy(55, 22);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    Delayer_menu(L1);
    gotoxy(55, 23);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    Delayer_menu(L7);
    gotoxy(55, 24);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    Delayer_menu(L1);
}

