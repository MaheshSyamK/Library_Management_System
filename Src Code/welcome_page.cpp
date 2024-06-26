#include "welcome_page.hpp"
#include <iostream>

// Define the function
void welcome_page() {
    // Your existing code for displaying the welcome page
    gotoxy(33, 6);
    cout << "######################################################################" << endl;
    gotoxy(33, 7);
    cout << "#                                                                    #" << endl;
    gotoxy(33, 8);
    cout << "#                                                                    #" << endl;
    gotoxy(33, 9);
    cout << "#                              LIBRARY                               #" << endl;
    gotoxy(33, 10);
    cout << "#                             MANAGEMENT                             #" << endl;
    gotoxy(33, 11);
    cout << "#                               SYSTEM                               #" << endl;
    gotoxy(33, 12);
    cout << "#                                                                    #" << endl;
    gotoxy(33, 13);
    cout << "#                                                                    #" << endl;
    gotoxy(33, 14);
    cout << "######################################################################" << endl;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    gotoxy(33, 16);
    system("pause");
    system("CLS");
}

// You might need to define or declare the gotoxy function here if it's not provided by the standard library

