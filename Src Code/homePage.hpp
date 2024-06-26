#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

extern HANDLE hConsole;

void gotoxy(short x, short y);
void Delayer_menu(string S);
void homePage();

#endif

