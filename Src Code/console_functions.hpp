#ifndef CONSOLE_FUNCTIONS_HPP
#define CONSOLE_FUNCTIONS_HPP

#include <iostream>
#include <windows.h>
#include <string>
#include <mysql.h>

using namespace std;

extern HANDLE hConsole;
extern string user_email;
extern string user_password;


void gotoxy(short x, short y);
void Delayer(string str);
void Delayer_menu(string S);

#endif /* CONSOLE_FUNCTIONS_HPP */

