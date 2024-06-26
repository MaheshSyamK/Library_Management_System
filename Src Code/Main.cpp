#include <ctime>
#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <sstream>
#include <string>
#include <windows.h>

#include "aboutUs.hpp"
#include "admin_functions.hpp"
#include "console_functions.hpp"
#include "homePage.hpp"
#include "login_reg_page.hpp"
#include "student_functions.hpp"
#include "welcome_page.hpp"

using namespace std;

char HOST[] = "localhost";
char USER[] = "root";
char PASS[] = "Mahesh@1527";

struct USER {
    string first_name;
    string last_name;
    string gender;
    string username;
    string email;
    string password;
    string birthdate;
    string grade;
};

struct BOOK {
    string title;
    string author;
    string publication_date;
    string department;
};


/*        function prototype        */
/*----------------------------------*/


bool registerStudent(MYSQL *conn, const string &firstName, const string &lastName, const string &birthdate, const string &gender, const string &grade, const string &username, const string &email,
                     const string &password);
void registerAdmin(MYSQL *conn, const string &firstName, const string &lastName, const string &gender, const string &username, const string &email, const string &password);

void loginadmin(MYSQL *conn);
void registeradmin(MYSQL *conn);
void loginstudent(MYSQL *conn);
void registerstudent(MYSQL *conn);


/*------------------------------------*/





int main() {
    MYSQL *conn;    // MySQL connection object
    MYSQL_RES *res; // MySQL result object
    MYSQL_ROW row;  // MySQL row object

    conn = mysql_init(NULL); // Initialize the MySQL connection

    // Connect to the MySQL database
    if (!mysql_real_connect(conn, HOST, USER, PASS, "library_database", 0, NULL, 0)) {
        cout << "Error connecting to the database: " << endl;
        return 1;
    }
    
    

    /*---------------------------------*/
    
    welcome_page();
    
    /*---------------------------------*/



    do {

        int c1, c2, c3;

    	home_page:homePage();

        gotoxy(76, 29);
        SetConsoleTextAttribute(hConsole, 7);
        cin >> c1;

        switch (c1) {
            //-------------------------------------

        case 1:
        	log_re_pa:login_reg_page();

            gotoxy(74, 23);
            SetConsoleTextAttribute(hConsole, 13);
            cin >> c2;

            switch (c2) {
            case 1:
                loginadmin(conn);
                break;
            case 2:
                registeradmin(conn);
                break;
            case 3:
                system("CLS");
                break;

            default:
                cout << "Invalid inpute!" << endl;
                system("pause");
                system("CLS");
                goto log_re_pa;
                break;
            }

            break;
            //-------------------------------------
        case 2:
            login_reg_page:login_reg_page();
            SetConsoleTextAttribute(hConsole, 13);
            gotoxy(74, 23);
            cin >> c3;
            switch (c3) {
            case 1:
                loginstudent(conn);
                break;
            case 2:
                registerstudent(conn);
                break;
            case 3:
                system("CLS");
                goto home_page;
                break;
            default:
                cout << "\n\t\t\t\t\tInvalid inpute!" << endl;
                system("pause");
                system("CLS");
                goto login_reg_page;
                break;
            }
            break;

            //------------------------------------
        case 3:
            aboutUs();
            system("pause");
            system("CLS");
            goto home_page;
            break;
            //------------------------------------
            //------------------------------------
        case 4:
            return 0;
            break;
            //------------------------------------

        default:
            cout << "\n\t\t\t\t\tInvalid inpute!" << endl;
            system("pause");
            system("CLS");
            goto home_page;
            break;
        }

    } while (true);

    // Close the MySQL connection
    mysql_close(conn);

    return 0;
    
}






// function definations
//---------------------------



void registeradmin(MYSQL *conn) {

    system("CLS");
    // Get admin registration details from the user
    string firstName, lastName, gender, username, email, password;
    cin.ignore();

    // --------------------------------------------
    gotoxy(33, 4);
    cout << "Enter First Name : ";
    gotoxy(55, 3);
    cout << " --------------------------- \n";
    gotoxy(55, 4);
    cout << "|                           |\n";
    gotoxy(55, 5);
    cout << " --------------------------- \n";
    // --------------------------------------------
    gotoxy(33, 8);
    cout << "Enter Last Name  : ";
    gotoxy(55, 7);
    cout << " --------------------------- \n";
    gotoxy(55, 8);
    cout << "|                           |\n";
    gotoxy(55, 9);
    cout << " --------------------------- \n";
    // --------------------------------------------
    gotoxy(33, 12);
    cout << "Enter Gender    : ";
    gotoxy(55, 11);
    cout << " --------------------------- \n";
    gotoxy(55, 12);
    cout << "|                           |\n";
    gotoxy(55, 13);
    cout << " --------------------------- \n";
    // --------------------------------------------
    gotoxy(33, 16);
    cout << "Enter Username  : ";
    gotoxy(55, 15);
    cout << " --------------------------- \n";
    gotoxy(55, 16);
    cout << "|                           |\n";
    gotoxy(55, 17);
    cout << " --------------------------- \n";
    // --------------------------------------------
    gotoxy(55, 19);
    cout << "Format : @gmail.com";
    gotoxy(33, 21);
    cout << "Enter Email    : ";
    gotoxy(55, 20);
    cout << " --------------------------- \n";
    gotoxy(55, 21);
    cout << "|                           |\n";
    gotoxy(55, 22);
    cout << " --------------------------- \n";
    // --------------------------------------------
    gotoxy(33, 25);
    cout << "Enter Password : ";
    gotoxy(55, 24);
    cout << " --------------------------- \n";
    gotoxy(55, 25);
    cout << "|                           |\n";
    gotoxy(55, 26);
    cout << " --------------------------- \n";

    //-----------------------------------

    gotoxy(56, 4);
    getline(cin, firstName);
    gotoxy(56, 8);
    getline(cin, lastName);
    gotoxy(56, 12);
    getline(cin, gender);
    gotoxy(56, 16);
    getline(cin, username);
    gotoxy(56, 21);
    getline(cin, email);
    user_email = email;
    gotoxy(56, 25);
    getline(cin, password);
    user_password = password;

    if (sizeof(password) > 8) {
        gotoxy(56, 27);
        cout << "strong password" << endl;
    } else {
        gotoxy(56, 27);
        cout << "weak password" << endl;
    }

    // Register the admin
    registerAdmin(conn, firstName, lastName, gender, username, email, password);

    system("pause");
    system("CLS");
}


void registerstudent(MYSQL* conn) {
    system("CLS");
    string stu_reg_succ = "Student registration successful! \n";
    string stu_reg_err = "Error registering student. \n";

    // Get student registration data from the user
    string firstName, lastName, birthdate, gender, grade, username, email, password;
    cin.ignore();
    gotoxy(23, 4);
    cout << "Enter First Name     : ";
    gotoxy(45, 3);
    cout << " -------------------------------- \n";
    gotoxy(45, 4);
    cout << "|                                |\n";
    gotoxy(45, 5);
    cout << " -------------------------------- \n";
    // --------------------------------------------
    gotoxy(23, 8);
    cout << "Enter Last Name      : ";
    gotoxy(45, 7);
    cout << " -------------------------------- \n";
    gotoxy(45, 8);
    cout << "|                                |\n";
    gotoxy(45, 9);
    cout << " -------------------------------- \n";
    // --------------------------------------------
    gotoxy(23, 12);
    cout << "Enter Gender         : ";
    gotoxy(45, 11);
    cout << " -------------------------------- \n";
    gotoxy(45, 12);
    cout << "|                                |\n";
    gotoxy(45, 13);
    cout << " -------------------------------- \n";

    // --------------------------------------------
    gotoxy(23, 16);
    cout << "Enter BOD(YYYY-DD-MM): ";
    gotoxy(45, 15);
    cout << " -------------------------------- \n";
    gotoxy(45, 16);
    cout << "|                                |\n";
    gotoxy(45, 17);
    cout << " -------------------------------- \n";
    // --------------------------------------------
    gotoxy(23, 20);
    cout << "Enter grade          : ";
    gotoxy(45, 19);
    cout << " -------------------------------- \n";
    gotoxy(45, 20);
    cout << "|                                |\n";
    gotoxy(45, 21);
    cout << " -------------------------------- \n";
    // --------------------------------------------
    gotoxy(23, 24);
    cout << "Enter Username       : ";
    gotoxy(45, 23);
    cout << " -------------------------------- \n";
    gotoxy(45, 24);
    cout << "|                                |\n";
    gotoxy(45, 25);
    cout << " -------------------------------- \n";
    // --------------------------------------------
    gotoxy(45, 27);
    cout << "Format: @gmail.com.";
    gotoxy(23, 29);
    cout << "Enter Email          : ";
    gotoxy(45, 28);
    cout << " -------------------------------- \n";
    gotoxy(45, 29);
    cout << "|                                |\n";
    gotoxy(45, 30);
    cout << " -------------------------------- \n";
    // --------------------------------------------
    gotoxy(23, 33);
    cout << "Enter Password       : ";
    gotoxy(45, 32);
    cout << " -------------------------------- \n";
    gotoxy(45, 33);
    cout << "|                                |\n";
    gotoxy(45, 34);
    cout << " -------------------------------- \n";

    //-----------------------------------

    gotoxy(46, 4);
    getline(cin, firstName);
    gotoxy(46, 8);
    getline(cin, lastName);
    gotoxy(46, 12);
    getline(cin, gender);
    gotoxy(46, 16);
    getline(cin, birthdate);
    gotoxy(46, 20);
    getline(cin, grade);
    gotoxy(46, 24);
    getline(cin, username);
    gotoxy(46, 29);
    getline(cin, email);
    gotoxy(46, 33);
    getline(cin, password);

    //-----------------------------------------
    if (password.length() > 8) {
        gotoxy(46, 35);
        cout << "strong password" << endl;
    } else {
        gotoxy(46, 35);
        cout << "weak password" << endl;
    }

    // Register the student by inserting their data into the database
    if (registerStudent(conn, firstName, lastName, birthdate, gender, grade, username, email, password)) {
        gotoxy(40, 37);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        Delayer(stu_reg_succ);

        system("pause");
        system("CLS");

    } else {
        gotoxy(0, 37);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        Delayer(stu_reg_err);

        system("pause");
        system("CLS");
    }
}
