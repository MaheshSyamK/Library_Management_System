#include "student_functions.hpp"
#include <iostream>
#include <windows.h>

using namespace std;

void student_menu() {

    string L1 = " -------------------------------\n";
    string L2 = "|                               |\n";
    string L3 = "|		 1.TAKE BOOK         |\n";
    string L4 = "| 3.DISPLAY MY DEPARTMENT BOOKS |\n";
    string L5 = "|   2.DISPLAY AVAILABLE BOOKS   |\n";
    string L6 = "|      4.ACCOUNT SETTING        |\n";
    string L9 = "|           5.BACK              |\n";
    string L7 = "|         CHOICE -              |\n";
    string L0 = "                                                   STUDENT PAGE              ";
    string L01 = "-----------------------------------------------------------------------------------------------------------------";
    //************************************************************
    gotoxy(5, 1);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L0);

    gotoxy(5, 2);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L01);

    gotoxy(5, 4);
    SetConsoleTextAttribute(hConsole, 14);	
    Delayer_menu(L1);
    gotoxy(5, 5);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
    gotoxy(5, 6);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L3);
    gotoxy(5, 7);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
    gotoxy(5, 8);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);

    //--------------------------------------
    //************************************************************
    gotoxy(45, 4);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L1);
    gotoxy(45, 5);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L2);
    gotoxy(45, 6);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L5);
    gotoxy(45, 7);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L2);
    gotoxy(45, 8);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L1);

    //--------------------------------------
    //************************************************************
    gotoxy(85, 4);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L1);
    gotoxy(85, 5);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L2);
    gotoxy(85, 6);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L4);
    gotoxy(85, 7);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L2);
    gotoxy(85, 8);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L1);

    gotoxy(5, 10);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);
    gotoxy(5, 11);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
    gotoxy(5, 12);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L6);
    gotoxy(5, 13);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
    gotoxy(5, 14);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);
    //--------------------------------------
    //************************************************************
    gotoxy(45, 10);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L1);
    gotoxy(45, 11);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L2);
    gotoxy(45, 12);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L9);
    gotoxy(45, 13);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L2);
    gotoxy(45, 14);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L1);

    //--------------------------------------

    gotoxy(5, 16);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L1);
    gotoxy(5, 17);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L7);
    gotoxy(5, 18);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L1);
}

void loginstudent(MYSQL *conn) {
    system("CLS");
    string email, password;
    string correct_email_password = "Logged in successfully!";
    string incorrect_email_password = "Invalid email or password.";
    cin.ignore();

    gotoxy(33, 4);
    cout << "Enter Email :\n";
    gotoxy(55, 3);
    cout << " ---------------------------- \n";
    gotoxy(55, 4);
    cout << "|                            |\n";
    gotoxy(55, 5);
    cout << " ---------------------------- \n";

    gotoxy(33, 8);
    cout << "Enter Password: ";
    gotoxy(55, 7);
    cout << " ---------------------------- \n";
    gotoxy(55, 8);
    cout << "|                            |\n";
    gotoxy(55, 9);
    cout << " ---------------------------- \n";

    gotoxy(56, 4);
    getline(cin, email);
    user_email = email;
    gotoxy(56, 8);
    getline(cin, password);
    user_password = password;

    // Check the student login credentials
    if (studentLogin(conn, email, password)) {
        // Successful login
        gotoxy(42, 11);
        SetConsoleTextAttribute(hConsole, 10);
        Delayer(correct_email_password);
        system("pause");
        system("CLS");

        // Show student menu
        int studentchoice;
        stu_page:student_menu();
        gotoxy(24, 17);
        SetConsoleTextAttribute(hConsole, 13);
        cin >> studentchoice;

        switch (studentchoice) {
            case 1:
                Takebook(conn);
                system("pause");
                system("CLS");
                goto stu_page;
                break;

            case 2:
                displayBookStatus(conn);
                system("pause");
                system("CLS");
                goto stu_page;
                break;

            case 3:
                displaybyDep(conn);
                system("pause");
                system("CLS");
                goto stu_page;
                break;

            case 4:
                accountSetting_stu(conn);
                system("pause");
                system("CLS");
                goto stu_page;
                break;

            case 5:
                system("CLS");
                break;

            default:
                cout << "Invalid input" << endl;
                system("pause");
                system("CLS");
                goto stu_page;
                break;
        }

    } else {
        // Failed login
        gotoxy(42, 11);
        SetConsoleTextAttribute(hConsole, 12);
        Delayer(incorrect_email_password);
        cout << "\n";
        system("pause");
        system("CLS");
    }
}



// Function to register a student in the database
bool registerStudent(MYSQL* conn, const string& firstName, const string& lastName, const string& birthdate, const string& gender, const string& grade, const string& username, const string& email, const string& password) {
    // Create the SQL query
    string query = "INSERT INTO student (first_name, last_name, birthdate, gender, grade, username, email, password) VALUES ('" +
                    firstName + "', '" + lastName + "', '" + birthdate + "', '" + gender + "', '" + grade + "', '" + username + "', '" + email + "', '" + password + "')";

    // Execute the query
    if (mysql_query(conn, query.c_str())) {
        // If there is an error, print it and return false
        cerr << "Error: " << mysql_error(conn) << endl;
        return false;
    }

    // If the query was successful, return true
    return true;
}


// Function to check student login credentials
bool studentLogin(MYSQL* conn, const string& email, const string& password) {
    string query = "SELECT * FROM student WHERE email = '" + email + "' AND password = '" + password + "'";
    if (mysql_query(conn, query.c_str())) {
        cerr << "Error: " << mysql_error(conn) << endl;
        return false;
    }

    MYSQL_RES* res = mysql_store_result(conn);
    int num_rows = mysql_num_rows(res);
    mysql_free_result(res);

    return num_rows > 0;
}



// Function to display book status
void displayBookStatus(MYSQL *conn) {
	
    // Construct the SQL query to retrieve the book status
    string query = "SELECT Title, Department, IF(Status = 'available', 'O', 'X') AS Status FROM books";
    system("CLS");
    // Execute the SQL query
    if (mysql_query(conn, query.c_str())) {
        cout << "\n\t\tError executing SQL query: " << endl;
        return;
    }

    // Get the result set
    MYSQL_RES *result = mysql_store_result(conn);

    // Check if the result set is empty
    if (mysql_num_rows(result) == 0) {
        cout << "\n\t\tNo books found in the library." << endl;
        mysql_free_result(result);
        return;
    }

    // Display the book status
    cout << "\t\tBook Status:" << endl;
    cout << "\t\tAvailable book = O" << endl;
    ;
    cout << "\t\tNot available book = X" << endl ;
    cout << "\n               -------------------------------------------------------------------" << endl << endl;

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        cout << "\t\tTitle: " << row[0] << endl;
        cout << "\t\tDepartment: " << row[1] << endl;
        cout << "\t\tStatus: " << row[2] << endl;
        cout << "\n               -------------------------------------------------------------------" << endl << endl;
    }

    // Free the result set
    mysql_free_result(result);
}


void accountSetting_stu(MYSQL* conn) {
    MYSQL_RES* res; // MySQL result object
    MYSQL_ROW row;  // MySQL row object

    system("CLS");
    string email = user_email;
    string password = user_password;

    // Construct the query to fetch the student's profile
    string query = "SELECT * FROM student WHERE email = '" + email + "' AND password = '" + password + "'";

    // Execute the query to fetch the student's profile
    if (mysql_query(conn, query.c_str())) {
        cout << "\n\tError executing SQL query\n " << mysql_error(conn) << endl;
        return;
    }

    // Get the result set from the executed query
    res = mysql_store_result(conn);
    if (res == NULL) {
        cout << "\n\tError storing result\n " << mysql_error(conn) << endl;
        return;
    }

    // If the student profile is found, display and prompt for edit
    if ((row = mysql_fetch_row(res))) {
        cout << "\n\n";
        cout << "\t\t\tYour Profile  " << endl;
        cout << "\t-----------------------------------------" << endl << endl;
        cout << "\tFirst Name : " << row[1] << endl << endl;
        cout << "\tLast Name  : " << row[2] << endl << endl;
        cout << "\tBirthdate  : " << row[3] << endl << endl;
        cout << "\tGender     : " << row[4] << endl << endl;
        cout << "\tGrade      : " << row[5] << endl << endl;
        cout << "\tUsername   : " << row[6] << endl << endl;
        cout << "\tEmail      : " << row[7] << endl << endl;
        cout << "\tPassword   : " << row[8] << endl << endl;

        char choice;
        cout << "\n\tDo you want to edit your profile? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cin.ignore(); // Ignore the newline character in the input buffer

            // Prompt for new student details
            string firstName, lastName, birthdate, gender, grade, newUsername, newEmail, newPassword;
            cout << endl << endl;
            cout << "\tEnter first name : ";
            cin.ignore();
            getline(cin, firstName);

            cout << "\tEnter last name   : ";
            getline(cin, lastName);

            cout << "\tEnter birthdate   : ";
            getline(cin, birthdate);

            cout << "\tEnter gender      : ";
            getline(cin, gender);

            cout << "\tEnter grade       : ";
            getline(cin, grade);

            cout << "\tEnter username    : ";
            getline(cin, newUsername);

            cout << "\tEnter email       : ";
            getline(cin, newEmail);

            cout << "\tEnter password    : ";
            getline(cin, newPassword);

            // Construct the SQL query to update the student profile
            query = "UPDATE student SET first_name = '" + firstName + "', last_name = '" + lastName + "', birthdate = '" + birthdate + "', gender = '" + gender + "', grade = '" + grade +
                    "', username = '" + newUsername + "', email = '" + newEmail + "', password = '" + newPassword + "' WHERE email = '" + email + "' AND password = '" + password + "'";

            // Execute the SQL query to update the student profile
            if (mysql_query(conn, query.c_str())) {
                cout << "\n\tError executing SQL query\n " << mysql_error(conn) << endl;
            } else {
                cout << "\n\tProfile updated successfully!\n" << endl;
            }
        }
    } else {
        cout << "\n\tProfile not found. Invalid email or password.\n" << endl;
    }

    // Free the result set memory
    mysql_free_result(res);
}



void displaybyDep(MYSQL *conn) {

    system("CLS");
    int departmentChoice;
    cout << "\n\n\n";
    // Display the department menu
    cout << "\t--------------------------------------------" << endl;
    cout << "\tSelect the department:" << endl;
    cout << "\t1. Software Engineering" << endl;
    cout << "\t2. Electrical Engineering" << endl;
    cout << "\t3. Mechanical Engineering" << endl;
    cout << "\t4. Electromechanical Engineering" << endl;
    cout << "\t5. Civil Engineering" << endl;
    cout << "\t6. Architecture" << endl;
    cout << "\t7. Mining Engineering" << endl;
    cout << "\t8. Environmental Engineering" << endl;
    cout << "\t9. Industrial Chemistry" << endl;
    cout << "\t10. Geology" << endl;
    cout << "\t11. Food Science" << endl;
    cout << "\t12. Biotechnology" << endl;
    cout << "\t--------------------------------------------" << endl;
    cout << "\tEnter your choice: ";
    cin.ignore();
    cin >> departmentChoice;

    string selectedDepartment;

    // Convert the department choice to the corresponding department string
    switch (departmentChoice) {
    case 1:
        selectedDepartment = "Software_Engineering";
        break;
    case 2:
        selectedDepartment = "Electrical_Engineering";
        break;
    case 3:
        selectedDepartment = "Mechanical_Engineering";
        break;
    case 4:
        selectedDepartment = "Electromechanical_Engineering";
        break;
    case 5:
        selectedDepartment = "Civil_Engineering";
        break;
    case 6:
        selectedDepartment = "Architecture";
        break;
    case 7:
        selectedDepartment = "Mining_Engineering";
        break;
    case 8:
        selectedDepartment = "Environmental_Engineering";
        break;
    case 9:
        selectedDepartment = "Industrial_Chemistry";
        break;
    case 10:
        selectedDepartment = "Geology";
        break;
    case 11:
        selectedDepartment = "Food_Science";
        break;
    case 12:
        selectedDepartment = "Biotechnology";
        break;
    default:
        cout << "Invalid department choice." << endl;
        mysql_close(conn);
        break;
    }

    // Display books by the selected department
    displayBooksByDepartment(conn, selectedDepartment);
}

void displayBooksByDepartment(MYSQL *conn, const string &department) {

    system("CLS");
    // Construct the SQL query to retrieve books by department
    string query = "SELECT * FROM books WHERE Department = '" + department + "'";

    // Execute the SQL query
    if (mysql_query(conn, query.c_str())) {
        cout << "\n\t\tError executing SQL query: " << endl;

    } else {

        // Get the result set
        MYSQL_RES *result = mysql_store_result(conn);

        // Check if the result set is empty
        if (mysql_num_rows(result) == 0) {
            cout << "\n\t\tNo books found in this department." << endl;
            mysql_free_result(result);
            return;
        }

        // Display the book details
        cout << "\tBooks in the department: "<< department << endl;
        cout << "      ------------------------------------------------" << endl;
        MYSQL_ROW row;

        while ((row = mysql_fetch_row(result))) {
            cout << "\tBook ID   : " << row[0] << endl;
            cout << "\tTitle     : " << row[1] << endl;
            cout << "\tAuthor    : " << row[2] << endl;
            cout << "\tDepartment: " << row[3] << endl;
            cout << "\tStatus    : " << row[4] << endl;
            cout << "      ----------------------------------------------------------" << endl << endl;
        }
        // Free the result set
        mysql_free_result(result);
    }
}

void Takebook(MYSQL *conn) {
    system("CLS");

    string bookTitle;
    cin.ignore(); // Ignore any leftover characters in the input buffer

    // Ask the user for the book title to borrow
    gotoxy(15, 4);
    cout << "Enter the book title to borrow: ";
    gotoxy(47, 5);
    cout << "-----------------------------------------";
    gotoxy(47, 4);
    getline(cin, bookTitle);

    // Construct the SQL query to check if the book exists and is available
    string checkQuery = "SELECT status FROM books WHERE title = '" + bookTitle + "'";
    if (mysql_query(conn, checkQuery.c_str())) {
        cout << "\n\t\tError executing SQL query\n " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES *res = mysql_store_result(conn);
    if (res == NULL) {
        cout << "\n\t\tError storing result\n " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_ROW row = mysql_fetch_row(res);
    if (row) {
        // Book exists, check its status
        string status = row[0];
        if (status == "available") {
            // Construct the SQL query to update the book status
            string updateQuery = "UPDATE books SET status = 'not available' WHERE title = '" + bookTitle + "'";
            
            // Execute the SQL query
            if (mysql_query(conn, updateQuery.c_str())) {
                cout << "\n\t\tError executing SQL query \n" << mysql_error(conn) << endl;
            } else {
                cout << endl;
                cout << "\n\t\tBook borrowed successfully!" << endl;
                cout << "\n\t\tWishing you success! May your reading time be engaging and fruitful.\n" << endl;
            }
        } else {
            cout << "\n\t\tThe book is already borrowed by someone else.\n" << endl;
        }
    } else {
        cout << "\n\t\tBook not found. Please check the title and try again.\n" << endl;
    }

    mysql_free_result(res);
}

