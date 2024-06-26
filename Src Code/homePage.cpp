#include "homePage.hpp"

void homePage(){
	
	
    string L1 = " ---------------------------\n";
    string L2 = "|                           |\n";
    string L3 = "|    1.ADMIN\\STAFF PAGE     |\n";
    string L4 = "|         2.STUDENT         |\n";
    string L5 = "|      3.ABOUT MYSELF       |\n";
    string L6 = "|      4.EXIT PROGRAM       |\n";
    string L7 = "        CHOICE -            \n";
    string L0 =  "         MAIN  PAGE         ";
    string L01 = " -------------------------- ";
    
    
    /******************************************/
    
       
	gotoxy(55,1);
    SetConsoleTextAttribute(hConsole, 7);
    Delayer_menu(L0);

    gotoxy(55,2);
    SetConsoleTextAttribute(hConsole, 7);
    Delayer_menu(L01);

    gotoxy(55,4);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L1);
    
	gotoxy(55,5);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L2);
    
	gotoxy(55,6);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L3);
    
	gotoxy(55,7);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L2);
    
	gotoxy(55,8);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L1);

    /************************************/
    
    gotoxy(55,10);
    SetConsoleTextAttribute(hConsole, 12);
    Delayer_menu(L1);
    
	gotoxy(55,11);
    SetConsoleTextAttribute(hConsole, 12);
    Delayer_menu(L2);
    
	gotoxy(55,12);
    SetConsoleTextAttribute(hConsole, 12);
    Delayer_menu(L4);
    
	gotoxy(55,13);
    SetConsoleTextAttribute(hConsole, 12);
    Delayer_menu(L2);
    
	gotoxy(55,14);
    SetConsoleTextAttribute(hConsole, 12);
    Delayer_menu(L1);

    /************************************/
    
    gotoxy(55,16);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);
    
	gotoxy(55,17);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
    
	gotoxy(55,18);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L5);
    
	gotoxy(55,19);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
    
	gotoxy(55,20);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);

    /*************************************/
    
    gotoxy(55,22);
    SetConsoleTextAttribute(hConsole, 9);
    Delayer_menu(L1);
    
	gotoxy(55,23);
    SetConsoleTextAttribute(hConsole, 9);
    Delayer_menu(L2);
    
	gotoxy(55,24);
    SetConsoleTextAttribute(hConsole, 9);
    Delayer_menu(L6);
    
	gotoxy(55,25);
    SetConsoleTextAttribute(hConsole, 9);
    Delayer_menu(L2);
    
	gotoxy(55,26);
    SetConsoleTextAttribute(hConsole, 9);
    Delayer_menu(L1);

    /*------------------------------------*/
    
	gotoxy(55,29);
    SetConsoleTextAttribute(hConsole, 7);
    Delayer_menu(L7);
    
    
}

