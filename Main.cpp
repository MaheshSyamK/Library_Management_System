#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <mysql.h>
#include <ctime>
#include <mysqld_error.h>

using namespace std;

char HOST[] = "localhost";
char USER[] = "root";
char PASS[] =  "Mahesh@1527";  

string user_email;
string user_password;

struct USER{
  string first_name;
  string last_name;
  string gender;
  string username;
  string email;
  string password;
  string  birthdate;
  string grade;
};

struct BOOK{
    string title;
    string author;
    string publication_date;
    string department;
};


// function prototype
//----------------
bool registerStudent(MYSQL* conn, const string& firstName, const string& lastName, const string& birthdate,
const string& gender, const string& grade, const string& username, const string& email, const string& password);
void registerAdmin(MYSQL* conn, const string& firstName, const string& lastName, const string& gender,
                   const string& username, const string& email, const string& password);
void displayBookStatus(MYSQL* conn);
void displayBooksByDepartment(MYSQL* conn, const string& department);
bool studentLogin(MYSQL* conn, const string& email, const string& password);
bool checkCredentials(MYSQL* conn, const string& email, const string& password);
void homePage();
void login_reg_page();
void student_menu();
void admin_menu();
void loginadmin(MYSQL* conn);
void registeradmin(MYSQL* conn);
void loginstudent(MYSQL* conn);
void registerstudent(MYSQL* conn);
void addbook(MYSQL* conn);
void displaybyDep(MYSQL* conn);
void Delete(MYSQL* conn);
void search(MYSQL* conn);
void displayAllBooks(MYSQL* conn);
void Takebook(MYSQL* conn);
void updatedbook(MYSQL* conn);
void countdown(string str,int color,int x,int y);
void accountSetting_admin(MYSQL* conn);
void accountSetting_stu(MYSQL* conn);
void aboutUs();
void  welcome_page();
//------------------------------------


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Delayer(string str) {
	for(int i = 0; i < str.size(); i++) {
		cout<<str[i];
		Sleep(65);
	}
	cout<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}
void Delayer_menu(string S) {
	for(int i = 0; i < S.size(); i++) {
		cout<<S[i];
		Sleep(0);
	}
	cout<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}


int main(){
    MYSQL* conn;        // MySQL connection object
    MYSQL_RES* res;     // MySQL result object
    MYSQL_ROW row;      // MySQL row object

    conn = mysql_init(NULL);    // Initialize the MySQL connection

    // Connect to the MySQL database
    if (!mysql_real_connect(conn, HOST,USER , PASS, "library_database", 0, NULL, 0)) {
        cout << "Error connecting to the database: " << endl;
        return 1;
    }

    //---------------------------------
    welcome_page();
    //----------------------------------

do{

   int c1,c2,c3;

   home_page:
   homePage();

        gotoxy(65,29);
        SetConsoleTextAttribute(hConsole, 9);
        cin >> c1;

   switch (c1)   {
 //-------------------------------------

      case 1:
      log_re_pa:
      login_reg_page();

      gotoxy(65,23);
    SetConsoleTextAttribute(hConsole, 13);
      cin >> c2;

    switch (c2)
    {
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
    cout << "Invalid inpute!" <<endl;
    system("pause");
    system("CLS");
     goto log_re_pa;
        break;
    }

    break;
 //-------------------------------------
   case 2:
login_reg_page :
    login_reg_page();
     SetConsoleTextAttribute(hConsole, 13);
       gotoxy(65,23);
      cin >> c3;
    switch (c3)
    {
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
    cout << "Invalid inpute!" <<endl;
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
    cout << "Invalid inpute!" <<endl;
    system("pause");
    system("CLS");
     goto home_page;
    break;

   }

}while(true);


 // Close the MySQL connection
    mysql_close(conn);

    return 0;
}

//function definations
//---------------------------



void homePage(){


       string L1 = "-----------------------------\n";
       string L2 = "|                           |\n";
       string L3 = "|1.ADMIN\\STAFF PAGE         |\n";
       string L4 = "|2.STUDENT                  |\n";
       string L5 = "|3.ABOUT US                 |\n";
       string L6 = "|4.EXIT PROGRAMM            |\n";
       string L7 = "|CHOICE -                   |\n";
       string L0 =  "MAIN  PAGE                     ";
       string L01 = "-----------------------------------------------";
       //************************************************************
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

    //--------------------------------------
      //************************************************************
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

    //--------------------------------------
      //************************************************************
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

    //--------------------------------------
      //************************************************************
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

    //--------------------------------------
       gotoxy(55,28);
    SetConsoleTextAttribute(hConsole, 9);
    Delayer_menu(L1);
        gotoxy(55,29);
    SetConsoleTextAttribute(hConsole, 9);
    Delayer_menu(L7);
        gotoxy(55,30);
    SetConsoleTextAttribute(hConsole, 9);
    Delayer_menu(L1);

}

void login_reg_page(){
	system("CLS");
       string L1 = "-----------------------------\n";
       string L2 = "|                           |\n";
       string L3 = "|1. LOGIN                   |\n";
       string L4 = "|2. REGISTER                |\n";
       string L5 = "|3. BACK                    |\n";
       string L7 = "|CHOICE -                   |\n";

       //************************************************************
    gotoxy(55,4);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);
        gotoxy(55,5);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
        gotoxy(55,6);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L3);
        gotoxy(55,7);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
         gotoxy(55,8);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);

    //--------------------------------------
      //************************************************************
    gotoxy(55,10);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L1);
        gotoxy(55,11);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L2);
        gotoxy(55,12);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L4);
        gotoxy(55,13);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L2);
         gotoxy(55,14);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L1);

    //--------------------------------------
      //************************************************************
    gotoxy(55,16);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L1);
        gotoxy(55,17);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L2);
        gotoxy(55,18);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L5);
        gotoxy(55,19);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L2);
         gotoxy(55,20);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L1);


    //**************************
          gotoxy(55,22);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L1);
        gotoxy(55,23);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L7);
        gotoxy(55,24);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L1);
}
// Function to insert student registration data into the database
bool registerStudent(MYSQL* conn, const string& firstName, const string& lastName, const string& birthdate, const string& gender, const string& grade, const string& username, const string& email, const string& password) {
    // Construct the SQL query to insert student data
    string query = "INSERT INTO student (first_name, last_name, birthdate, gender, grade, username, email, password) VALUES ('" + firstName + "', '" + lastName + "', '" + birthdate + "', '" + gender + "', '" + grade + "', '" + username + "', '" + email + "', '" + password + "')";

    // Execute the SQL query
    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: " << endl;
        return false;
    }

    return true;
}
// Function to insert admin registration details into the database
void registerAdmin(MYSQL* conn, const string& firstName, const string& lastName, const string& gender,
                   const string& username, const string& email, const string& password) {
    // Construct the SQL query to insert the admin details
    string query = "INSERT INTO admin (first_name, last_name, gender, username, email, password) VALUES ('" +
                   firstName + "', '" + lastName + "', '" + gender + "', '" + username + "', '" +
                   email + "', '" + password + "')";

       string admin_reg_succ = "Admin registration successful! \n";
      string admin_reg_not_succ = " Error Admin registration! \n";
    // Execute the SQL query
    if (mysql_query(conn, query.c_str())) {
       gotoxy(50,26);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer(admin_reg_not_succ);

    }
    else{
    	gotoxy(50,26);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer(admin_reg_succ);
	}



}
// Function to display book status
void displayBookStatus(MYSQL* conn) {
    // Construct the SQL query to retrieve the book status
    string query = "SELECT Title, Department, IF(Status = 'available', 'O', 'X') AS Status FROM books";
system("CLS");
    // Execute the SQL query
    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: " << endl;
        return;
    }

    // Get the result set
    MYSQL_RES* result = mysql_store_result(conn);

    // Check if the result set is empty
    if (mysql_num_rows(result) == 0) {
        cout << "No books found in the library." << endl;
        mysql_free_result(result);
        return;
    }

    // Display the book status
    cout << "Book Status:" << endl;
    cout <<  "Available book = O" << endl;;
    cout <<  "Not available book = X"<<endl << endl;


    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        cout << "Title: " << row[0] << endl;
        cout << "Department: " << row[1] << endl;
        cout << "Status: " << row[2] << endl;
        cout << "-----------------------" <<endl << endl;
    }

    // Free the result set
    mysql_free_result(result);
}
// Function to display books by department
void displayBooksByDepartment(MYSQL* conn, const string& department) {

system("CLS");
    // Construct the SQL query to retrieve books by department
    string query = "SELECT * FROM books WHERE Department = '" + department + "'";

    // Execute the SQL query
    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: "  << endl;

    }
   else{

    // Get the result set
    MYSQL_RES* result = mysql_store_result(conn);

    // Check if the result set is empty
    if (mysql_num_rows(result) == 0) {
        cout << "No books found in this department." << endl;
        mysql_free_result(result);
        return;
    }

    // Display the book details
    cout << "\t Books in the selected department:" << endl;
    cout << "------------------------------------------------"<< endl;
    MYSQL_ROW row;


    while ((row = mysql_fetch_row(result))) {
        cout << "\tBook ID: " << row[0] << endl;
        cout << "\tTitle: " << row[1] << endl;
        cout << "\tAuthor: " << row[2] << endl;
        cout << "\tDepartment: " << row[3] << endl;
        cout << "\tStatus: " << row[4] << endl;
        cout << "------------------------------------------------"<<endl << endl;
    }
     // Free the result set
    mysql_free_result(result);
}

}

// Function to check if the student login credentials are valid
bool studentLogin(MYSQL* conn, const string& email, const string& password) {
    // Construct the SQL query to check the existence of the student's email and password
    string query = "SELECT * FROM student WHERE email='" + email + "' AND password='" + password + "'";

    // Execute the SQL query
    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: " << endl;
        return false;
    }

    // Get the result set from the executed query
    MYSQL_RES* result = mysql_store_result(conn);

    // Check if the result set is empty
    if (mysql_num_rows(result) == 0) {
        mysql_free_result(result);
        return false;
    }

    mysql_free_result(result);
    return true;
}

bool checkCredentials(MYSQL* conn, const string& email, const string& password) {
    // Construct the SQL query to check the admin credentials
    string query = "SELECT * FROM admin WHERE email = '" + email + "' AND password = '" + password + "'";

    // Execute the SQL query
    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: " << endl;
        return false;
    }

    MYSQL_RES* result = mysql_store_result(conn); // Get the result set

    // Check if any rows are returned (credentials are valid)
    bool isValid = (mysql_num_rows(result) == 1);

    mysql_free_result(result); // Free the result set

    return isValid;
}


void loginstudent(MYSQL* conn){

system("CLS");
 string email, password;
   string correct_email_password = "Logged in successfully!" ;
   string incorrect_email_password = "Invalid email or password." ;
    cin.ignore();

    gotoxy(33,4);
    cout << "Enter Email :\n";
    gotoxy(55,3);
    cout << "--------------------\n";
    gotoxy(55,4);
    cout << "|                  |\n";
    gotoxy(55,5);
    cout << "--------------------\n";


    gotoxy(33,8);
    cout << "Enter Password: ";
    gotoxy(55,7);
    cout << "--------------------\n";
    gotoxy(55,8);
    cout << "|                  |\n";
    gotoxy(55,9);
    cout << "--------------------\n";


    gotoxy(56,4);
    getline(cin, email);
     user_email = email;
    gotoxy(56,8);
    getline(cin, password);
      user_password = password;

    // Check the admin login credentials
    if (studentLogin(conn, email, password)) {

      gotoxy(50,10);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer(correct_email_password);
         system("pause");
            system("CLS");

          int studentchoice;
          stu_page:
         student_menu();
                    gotoxy(23,17);
    SetConsoleTextAttribute(hConsole, 13);
         cin >> studentchoice;

        switch(studentchoice){

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
            cout << "invalid inpute" << endl;
               system("pause");
             system("CLS");
              goto stu_page;
            break;
        }


    } else {
     gotoxy(50,10);
    SetConsoleTextAttribute(hConsole, 12);
    Delayer(incorrect_email_password);

            system("pause");
             system("CLS");
              goto stu_page;
    }

}
void registeradmin(MYSQL* conn){

system("CLS");
    // Get admin registration details from the user
    string firstName, lastName, gender, username, email, password;
    cin.ignore();

   // --------------------------------------------
     gotoxy(33,4);
    cout << "Enter First Name: ";
    gotoxy(55,3);
    cout << "-----------------------------\n";
    gotoxy(55,4);
    cout << "|                           |\n";
    gotoxy(55,5);
    cout << "-----------------------------\n";
    // --------------------------------------------
     gotoxy(33,8);
    cout << "Enter Last Name: ";
    gotoxy(55,7);
    cout << "-----------------------------\n";
    gotoxy(55,8);
    cout << "|                           |\n";
    gotoxy(55,9);
    cout << "-----------------------------\n";
    // --------------------------------------------
     gotoxy(33,12);
    cout << "Enter Gender: ";
    gotoxy(55,11);
    cout << "-----------------------------\n";
    gotoxy(55,12);
    cout << "|                           |\n";
    gotoxy(55,13);
    cout << "-----------------------------\n";
    // --------------------------------------------
     gotoxy(33,16);
    cout << "Enter Username: ";
    gotoxy(55,15);
    cout << "-----------------------------\n";
    gotoxy(55,16);
    cout << "|                           |\n";
    gotoxy(55,17);
    cout << "-----------------------------\n";
    // --------------------------------------------
       gotoxy(55,19);
     cout << "forexample@gmail.com";
     gotoxy(33,21);
   cout << "Enter Email: ";
    gotoxy(55,10);
    cout << "-----------------------------\n";
    gotoxy(55,21);
    cout << "|                           |\n";
    gotoxy(55,22);
    cout << "-----------------------------\n";
    // --------------------------------------------
     gotoxy(33,25);
     cout << "Enter Password: ";
    gotoxy(55,24);
    cout << "-----------------------------\n";
    gotoxy(55,25);
    cout << "|                           |\n";
    gotoxy(55,26);
    cout << "-----------------------------\n";


    //-----------------------------------

    gotoxy(56,4);
    getline(cin, firstName);
    gotoxy(56,8);
    getline(cin, lastName);
    gotoxy(56,12);
    getline(cin, gender);
    gotoxy(56,16);
    getline(cin, username);
    gotoxy(56,21);
    getline(cin, email);
      user_email = email;
    gotoxy(56,25);
    getline(cin, password);
     user_password = password;

         if(sizeof(password) > 8){
     	gotoxy(56,27);
     	cout << "strong password" << endl;
	 }
	 else{
	 	gotoxy(56,27);
	 	cout << "weak password" << endl;
	 }

    // Register the admin
    registerAdmin(conn, firstName, lastName, gender, username, email, password);

        system("pause");
        system("CLS");


}
void loginadmin(MYSQL* conn){

	system("CLS");
    MYSQL_RES* res;     // MySQL result object
    MYSQL_ROW row;

    string email, password;
   string correct_email_password = "Logged in successfully!" ;
   string incorrect_email_password = "Invalid email or password." ;
    cin.ignore();

    gotoxy(33,4);
    cout << "Enter Email :\n";
    gotoxy(55,3);
    cout << "--------------------\n";
    gotoxy(55,4);
    cout << "|                  |\n";
    gotoxy(55,5);
    cout << "--------------------\n";


    gotoxy(33,8);
    cout << "Enter Password: ";
    gotoxy(55,7);
    cout << "--------------------\n";
    gotoxy(55,8);
    cout << "|                  |\n";
    gotoxy(55,9);
    cout << "--------------------\n";


    gotoxy(56,4);
    getline(cin, email);
     user_email = email;

    gotoxy(56,8);
    getline(cin, password);
    user_password = password;




    // Check if the student's login credentials are valid
    if (checkCredentials(conn, email, password)) {

    gotoxy(50,10);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer(correct_email_password);

           system("pause");
            system("CLS");

       int AC;
       admin_page:
           admin_menu();

            gotoxy(23,22);
              cin >> AC;

        switch(AC){

            case 1:
            addbook(conn);
             system("pause");
             system("CLS");
              goto admin_page;
            break;

            case 2:
            Delete(conn);
             system("pause");
              system("CLS");
               goto admin_page;
            break;

            case 3:
            search(conn);
             system("pause");
             system("CLS");
              goto admin_page;
            break;

            case 4:
            updatedbook(conn);
             system("pause");
             system("CLS");
              goto admin_page;
            break;

            case 5:
            displayAllBooks(conn);
             system("pause");
             system("CLS");
              goto admin_page;
            break;

            case 6:
       		accountSetting_admin(conn);
           	 system("pause");
            	system("CLS");
              goto admin_page;
            break;

              case 7:
            	system("CLS");
            break;

            default:
            cout << "invalid inpute" << endl;
             system("pause");
             system("CLS");
            goto admin_page;
            break;
        }


    } else {
       gotoxy(50,10);
    SetConsoleTextAttribute(hConsole, 12);
    Delayer(incorrect_email_password);

     system("pause");
             system("CLS");

    }



}
void registerstudent(MYSQL* conn){
	system("CLS");
	 string stu_reg_succ = "Student registration successful! \n";
	  string stu_reg_err = "Error registering student. \n";


    // Get student registration data from the user
    string firstName, lastName, birthdate, gender, grade, username, email, password;
    cin.ignore();
        gotoxy(33,4);
    cout << "Enter First Name: ";
    gotoxy(55,3);
    cout << "-----------------------------\n";
    gotoxy(55,4);
    cout << "|                           |\n";
    gotoxy(55,5);
    cout << "-----------------------------\n";
    // --------------------------------------------
     gotoxy(33,8);
    cout << "Enter Last Name: ";
    gotoxy(55,7);
    cout << "-----------------------------\n";
    gotoxy(55,8);
    cout << "|                           |\n";
    gotoxy(55,9);
    cout << "-----------------------------\n";
    // --------------------------------------------
     gotoxy(33,12);
    cout << "Enter Gender: ";
    gotoxy(55,11);
    cout << "-----------------------------\n";
    gotoxy(55,12);
    cout << "|                           |\n";
    gotoxy(55,13);
    cout << "-----------------------------\n";

    // --------------------------------------------
     gotoxy(33,16);
    cout << "Enter birth date(YYYY-DD-MM): ";
    gotoxy(62,15);
    cout << "-----------------------------\n";
    gotoxy(62,16);
    cout << "|                           |\n";
    gotoxy(62,17);
    cout << "-----------------------------\n";
    // --------------------------------------------
     gotoxy(33,20);
    cout << "Enter grade: ";
     gotoxy(55,19);
    cout << "-----------------------------\n";
    gotoxy(55,20);
    cout << "|                           |\n";
    gotoxy(55,21);
    cout << "-----------------------------\n";
    // --------------------------------------------
     gotoxy(33,24);
    cout << "Enter Username: ";
    gotoxy(55,23);
    cout << "-----------------------------\n";
    gotoxy(55,24);
    cout << "|                           |\n";
    gotoxy(55,25);
    cout << "-----------------------------\n";
    // --------------------------------------------
      gotoxy(55,27);
         cout << "forexample@gmail.com.";
     gotoxy(33,29);
   cout << "Enter Email: ";
   gotoxy(55,28);
    cout << "-----------------------------\n";
    gotoxy(55,29);
    cout << "|                           |\n";
    gotoxy(55,30);
    cout << "-----------------------------\n";
    // --------------------------------------------
     gotoxy(33,33);
     cout << "Enter Password: ";
    gotoxy(55,32);
    cout << "-----------------------------\n";
    gotoxy(55,33);
    cout << "|                           |\n";
    gotoxy(55,34);
    cout << "-----------------------------\n";


    //-----------------------------------

    gotoxy(56,4);
    getline(cin, firstName);
    gotoxy(56,8);
    getline(cin, lastName);
    gotoxy(56,12);
    getline(cin, gender);
    gotoxy(63,16);
    getline(cin, birthdate);
    gotoxy(56,20);
    getline(cin, grade);
    gotoxy(56,24);
    getline(cin, username);
    gotoxy(56,29);
    getline(cin, email);
    gotoxy(56,33);
    getline(cin, password);

    //-----------------------------------------
     if(sizeof(password) > 8){
     	gotoxy(56,34);
     	cout << "strong password" << endl;
	 }
	 else{
	 	gotoxy(56,34);
	 	cout << "weak password" << endl;
	 }

    // Register the student by inserting their data into the database
    if (registerStudent(conn, firstName, lastName, birthdate, gender, grade, username, email, password)) {
         gotoxy(50,34);
    SetConsoleTextAttribute(hConsole, 1);
    Delayer(stu_reg_succ);

            system("pause");
             system("CLS");

    } else {
         gotoxy(50,34);
    SetConsoleTextAttribute(hConsole, 1);
    Delayer(stu_reg_err);

        system("pause");
             system("CLS");

    }


}

void addbook(MYSQL* conn){

  system("CLS");
    string title, author, publicationDate, department, status;
     cin.ignore();
	// Accept book details from the user
	 gotoxy(15,4);
    cout << "Enter book details: " ;
    	 gotoxy(15,5);
        cout << "Title: ";
    	 gotoxy(23,6);
    	 cout << "-----------------------------------------";

    	 gotoxy(15,7);
       cout << "Author: ";
    	 gotoxy(23,8);
    	 cout << "-----------------------------------------";

     	 gotoxy(15,9);
    cout << "Publication Date (YYYY-MM-DD): ";
    	 gotoxy(46,10);
    	 cout << "-----------------------------------------";

    	 gotoxy(15,11);
    cout <<"Department: ";
    	 gotoxy(46,12);
    	 cout << "-----------------------------------------";

    	 gotoxy(15,13);
    cout << " Status (Available not Available) : ";
    	 gotoxy(50,14);
    	 cout << "-----------------------------------------";

   	gotoxy(23,5);
    getline(cin, title);
    	  gotoxy(23,7);
    getline(cin, author);
    	  gotoxy(46,9);
    getline(cin, publicationDate);
    	  gotoxy(46,11);
    getline(cin, department);
    	  gotoxy(46,13);
    getline(cin, status);


    string query = "INSERT INTO books (title, author, publication_date, department, status) VALUES ('" + title + "', '" + author + "', '" + publicationDate + "', '" + department + "', '" + status + "')";

    string str = "\nAdding  ...";
    int color = 13;


    countdown(str,color,15,15);

    // Execute the SQL query
    if (mysql_query(conn, query.c_str()) != 0) {
        cout << "Error executing SQL query: "  << endl;

    }
     else
    cout << "Book added successfully!" << endl;

}


void displaybyDep(MYSQL* conn){

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

void Delete(MYSQL* conn){
system("CLS");
 MYSQL_RES* res;
    MYSQL_ROW row;

     string check_delete = "Are you sure you want to delete this book(y/n) ?";
    string bookTitle;
    cin.ignore();
    // Ask the user for the book title to delete
    gotoxy(15,4);
    cout << "Enter the book title to delete: ";
    	 gotoxy(47,5);
    	 cout << "-----------------------------------------";
    	 	 gotoxy(47,4);
    getline(cin, bookTitle);

     	 gotoxy(15,7);
     	 Delayer(check_delete);
     char check_d;
     cout << "\t\t\t\t\t\t";
     cin >> check_d;
     if(check_d == 'y' ||check_d == 'Y'){

    // Construct the SQL query to delete the book
     string query = "DELETE FROM books WHERE title = '" + bookTitle + "'";
     string str = "Deleting...  ";
     int color = 12;

      countdown(str,color,15,9);
   if (mysql_query(conn, query.c_str())) {
        cout << "ERROR EXECUTING SQL QUERY: "  << endl;

    }

    res = mysql_use_result(conn);

    if ((row = mysql_fetch_row(res))) {
        string deleteQuery = "DELETE FROM books WHERE title = '" + bookTitle + "'";

        if (mysql_query(conn, deleteQuery.c_str())) {
            cout << "ERROR DELETING BOOK: " << endl;

        }

        cout << "BOOK DELETED SUCCESSFULLY!" << endl;
    } else {
        cout << "BOOK NOT FOUND. PLEASE CHECK THE TITLE." << endl;
    }

    mysql_free_result(res);
}

}
void search(MYSQL* conn){
	system("CLS");

 MYSQL_RES* res;     // MySQL result object
    MYSQL_ROW row;
    string str = "Searching... " ;
    int color = 10;
    string searchBy;
    string keyword;
    cin.ignore();
    // Ask the user how they want to search (by title or author)
    gotoxy(15,4);
    cout << "Search by (title/author): ";
    	 gotoxy(42,5);
    	 cout << "-----------------------------------------";
    	 	 gotoxy(42,4);
    cin >> searchBy;

    cin.ignore(); // Ignore the newline character left in the input buffer

    // Ask the user for the search keyword
    gotoxy(15,7);
    cout << "Enter the " << searchBy << " to search: ";
    	 gotoxy(42,8);
    	 cout << "-----------------------------------------";
    	 gotoxy(42,7);
    getline(cin, keyword);


    // Construct the SQL query based on the search criteria
    string query;
    if (searchBy == "title") {
        query = "SELECT * FROM books WHERE title LIKE '%" + keyword + "%'";
    } else if (searchBy == "author") {
        query = "SELECT * FROM books WHERE author LIKE '%" + keyword + "%'";
    } else {
        cout << "Invalid search criteria." << endl;

    }

       countdown(str,color,15,9);
      cout << endl << endl;
    // Execute the SQL query
    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: "  << endl;
           return;
    }

else{


    res = mysql_use_result(conn);

    // Check if any books are found
    if ((row = mysql_fetch_row(res))) {
        cout << "Matching books found:" << endl;
        while (row) {
        	cout << "\n\n\n\n";
            // Print book details
            cout << "\t\tTitle: " << row[1] << endl;
            cout << "\t\tAuthor: " << row[2] << endl;
            cout << "\t\tPublication Date: " << row[3] << endl;
            cout << "\t\tDepartment: " << row[4] << endl;
            cout << "\t\tStatus: " << row[5] << endl;
            cout << "\t\t---------------------" << endl;

            row = mysql_fetch_row(res); // Fetch the next row
        }
    } else {
        cout << "\t\tNo matching books found." << endl;
    }
}
    // Free the result set memory
    mysql_free_result(res);



}

void displayAllBooks(MYSQL* conn){
	system("CLS");
    MYSQL_RES* res;     // MySQL result object
    MYSQL_ROW row;
    // Execute the SQL query to retrieve all books
    string query = "SELECT * FROM books";
    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: "  << endl;

    }

	else{

    res = mysql_use_result(conn);

    // Print the books
    	int book_id = 1;
   while ((row = mysql_fetch_row(res))) {

    	cout <<endl;
        cout << "\t" <<book_id<<"."<<"Title: " << row[1] << endl ;
        cout << "\t    Author: " << row[2] << endl;
        cout << "\t    Publication Date: " << row[3]  << endl;
        cout << "\t    Department: " << row[4] << endl ;
        cout << "\t    Status: " << row[5] << endl ;
        cout << "--------------------------------------------------"<< endl;
     book_id++;
 }
    // Free the result set memory
    mysql_free_result(res);

}


}

void Takebook(MYSQL* conn){

system("CLS");

    string bookTitle;
    cin.ignore();    // Ask the user for the book title to borrow
    gotoxy(15,4);
    cout << "Enter the book title to borrow: ";
    	 gotoxy(44,6);
    	 cout << "-----------------------------------------";
    	  gotoxy(44,5);
    getline(cin, bookTitle);

    // Construct the SQL query to update the book status
    string query = "UPDATE books SET status = 'not available' WHERE title = '" + bookTitle + "'";

    // Execute the SQL query
    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: "  << endl;

    }
else{
	cout << endl;
    cout << "Book borrowed successfully!" << endl;
    cout << "Wishing you success ! May your reading time be engaging and fruitful." <<endl;
}


}
void updatedbook(MYSQL* conn){

	system("CLS");
    MYSQL_RES* res;     // MySQL result object
    MYSQL_ROW row;
    string title, author, publicationDate, department, status;
    cin.ignore();
    // Accept the title of the book to be updated from the user
    gotoxy(15,4);
    cout << "Enter the title of the book to update: ";
    	 gotoxy(47,6);
    	 cout << "-----------------------------------------";
    	 	 gotoxy(47,5);
    getline(cin, title);

    // Check if the book exists in the database
    string query = "SELECT * FROM books WHERE title = '" + title + "'";

    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: " << endl;
        return ;
    }
   else{

    res = mysql_use_result(conn);


    // If the book is found, prompt the user to enter new book details

    if ((row = mysql_fetch_row(res))) {
    	cout << "\n\n\n\n";
        cout << "\t\tEnter new book details:" << endl;
        cout << "\t\tAuthor: ";
        getline(cin, author);
        cout << "\t\tPublication Date (YYYY-MM-DD): ";
        getline(cin, publicationDate);
        cout << "\t\tDepartment: ";
        getline(cin, department);
        cout << "\t\tStatus: ";
        getline(cin, status);

        // Free the result set memory
        mysql_free_result(res);

        // Construct the SQL query to update the book details
        query = "UPDATE books SET author = '" + author + "', publication_date = '" + publicationDate + "', department = '" + department + "', status = '" + status + "' WHERE title = '" + title + "'";

        string str = "Updating  ...";
        int color = 14;
        countdown(str,color,14,16);

        // Execute the SQL query to update the book details
        if (mysql_query(conn, query.c_str())) {
            cout << "Error executing SQL query: "<< endl;
            return ;
        }

        cout << "Book details updated successfully!" << endl;
    } else {
        cout << "Book not found in the database." << endl;
    }

}

}
void countdown(string str, int color,int x , int y){

    int seconds = 5;
    SetConsoleTextAttribute(hConsole, color);
    Delayer_menu(str);


    while (seconds > 0) {
        gotoxy(x,y);
        cout << "\r" ;
        gotoxy(x,y);
        cout << seconds;
          gotoxy(x,y);
        cout.flush();

        Sleep(1000); // Sleep for 1 second (1000 milliseconds)

        seconds--;
    }

cout << endl;

}

void accountSetting_admin(MYSQL* conn){
	 MYSQL_RES* res;     // MySQL result object
    MYSQL_ROW row;      // MySQL row object

       system("CLS");
	 string email, password;

    email = user_email;
    password = user_password;


    // Check if the admin profile exists in the database
    string query = "SELECT * FROM admin WHERE email = '" + email + "' AND password = '" + password + "'";

    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: "  << endl;
        return ;
    }

    res = mysql_use_result(conn);
   //  SetConsoleTextAttribute(hConsole,7)
    // If the admin profile is found, display and prompt for edit
    if ((row = mysql_fetch_row(res))) {
    	cout <<"\n\n";
        cout << "\tYour profile :  " << endl;
        cout << "\t--------------------------------------------------" << endl<< endl;
        cout << "\tFirst Name: " << row[1] << endl << endl;
        cout << "\tLast Name: " << row[2] << endl<< endl;
        cout << "\tGender: " << row[3] << endl<< endl;
        cout << "\tUsername: " << row[4] << endl<< endl;
        cout << "\tEmail: " << row[5] << endl << endl;
        cout << "\tPassword: " << row[6] << endl  << endl;

        char choice;
        cout << "Do you want to edit your profile? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cin.ignore(); // Ignore the newline character in the input buffer

            // Prompt for new admin details
            string firstName, lastName, gender, username, newPassword,newEmail;
            cout << endl<< endl;
            cout << "\tEnter  first name: ";
            getline(cin, firstName);

            cout << "\tEnter last name: ";
            getline(cin, lastName);

            cout << "\tEnter gender: ";
            getline(cin, gender);

            cout << "\tEnter  username: ";
            getline(cin, username);

             cout << "\tEnter  email: ";
            getline(cin, newEmail);

            cout << "\tEnter  password: ";
            getline(cin, newPassword);

            // Construct the SQL query to update the admin profile
            query = "UPDATE admin SET first_name = '" + firstName + "', last_name = '" + lastName + "', gender = '" + gender + "', username = '" + username + "', email = '" + newEmail + "', password = '" + newPassword + "' WHERE email = '" + email + + "' AND password = '" + password + "'";

            // Execute the SQL query to update the admin profile
            if (mysql_query(conn, query.c_str())) {
                cout << "Error executing SQL query: " << endl;

            }

            cout << "Profile updated successfully!" << endl;
        }
    } else {
        cout << "Profile not found. Invalid email or password." << endl;
    }

    // Free the result set memory
    mysql_free_result(res);
}

void student_menu(){

       string L1 = "--------------------------------\n";
       string L2 = "|                              |\n";
       string L3 = "|1. TAKE BOOK                  |\n";
       string L4 = "|3. DISPLAY MY DEPARTMENT BOOKS|\n";
       string L5 = "|2. DISPLAY AVAILABLE BOOKS    |\n";
       string L6 = "|4. ACCOUNT SETTING            |\n";
       string L9 = "|5. BACK                       |\n";
       string L7 = "|CHOICE -                      |\n";
       string L0 =  "STUDENT PAGE              ";
       string L01 = "---------------------------------------------------------------------------------------------------------------------------------------------------------";
       //************************************************************
        gotoxy(5,1);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L0);

     gotoxy(5,2);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L01);

    gotoxy(5,4);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L1);
        gotoxy(5,5);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L2);
        gotoxy(5,6);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L3);
        gotoxy(5,7);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L2);
         gotoxy(5,8);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L1);

    //--------------------------------------
      //************************************************************
    gotoxy(45,4);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L1);
        gotoxy(45,5);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L2);
        gotoxy(45,6);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L5);
        gotoxy(45,7);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L2);
         gotoxy(45,8);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L1);

    //--------------------------------------
      //************************************************************
    gotoxy(85,4);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L1);
        gotoxy(85,5);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L2);
        gotoxy(85,6);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L4);
        gotoxy(85,7);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L2);
         gotoxy(85,8);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L1);

         gotoxy(5,10);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);
        gotoxy(5,11);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
        gotoxy(5,12);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L6);
        gotoxy(5,13);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
         gotoxy(5,14);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);
    //--------------------------------------
      //************************************************************
    gotoxy(45,10);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L1);
        gotoxy(45,11);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L2);
        gotoxy(45,12);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L9);
        gotoxy(45,13);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L2);
         gotoxy(45,14);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L1);

    //--------------------------------------


        gotoxy(10,16);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L1);
        gotoxy(10,17);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L7);
        gotoxy(10,18);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L1);


}
void admin_menu(){

       string L1 = "-----------------------------\n";
       string L2 = "|                           |\n";
       string L3 = "|1. ADD BOOK                |\n";
       string L4 = "|2. DELETE BOOK             |\n";
       string L5 = "|3. SEARCH                  |\n";
       string L6 = "|4. UPDATE BOOK             |\n";
       string L8 = "|5. DISPLAY ALL BOOKS       |\n";
       string L10 = "|6. ACCOUNT SETTING         |\n";
       string L9 = "|7. BACK                    |\n";
       string L7 = "|CHOICE -                   |\n";
       string L0 = "ADMIN(STAFF) PAGE              ";
       string L01 = "---------------------------------------------------------------------------------------------------------------------------------------------------------";
       //************************************************************

    gotoxy(5,1);
    SetConsoleTextAttribute(hConsole, 7);
    Delayer_menu(L0);

    gotoxy(5,2);
    SetConsoleTextAttribute(hConsole, 7);
    Delayer_menu(L01);

    gotoxy(5,4);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L1);
        gotoxy(5,5);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L2);
        gotoxy(5,6);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L3);
        gotoxy(5,7);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L2);
         gotoxy(5,8);
    SetConsoleTextAttribute(hConsole, 10);
    Delayer_menu(L1);

    //--------------------------------------
      //************************************************************
    gotoxy(35,4);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L1);
        gotoxy(35,5);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L2);
        gotoxy(35,6);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L4);
        gotoxy(35,7);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L2);
         gotoxy(35,8);
    SetConsoleTextAttribute(hConsole, 8);
    Delayer_menu(L1);

    //--------------------------------------
      //************************************************************
    gotoxy(65,4);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L1);
        gotoxy(65,5);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L2);
        gotoxy(65,6);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L5);
        gotoxy(65,7);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L2);
         gotoxy(65,8);
    SetConsoleTextAttribute(hConsole, 11);
    Delayer_menu(L1);


         gotoxy(5,10);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);
        gotoxy(5,11);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
        gotoxy(5,12);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L6);
        gotoxy(5,13);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L2);
         gotoxy(5,14);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer_menu(L1);

    //--------------------------------------
      //************************************************************
    gotoxy(35,10);
    SetConsoleTextAttribute(hConsole, 3);
    Delayer_menu(L1);
        gotoxy(35,11);
    SetConsoleTextAttribute(hConsole, 3);
    Delayer_menu(L2);
        gotoxy(35,12);
    SetConsoleTextAttribute(hConsole, 3);
    Delayer_menu(L8);
        gotoxy(35,13);
    SetConsoleTextAttribute(hConsole, 3);
    Delayer_menu(L2);
         gotoxy(35,14);
    SetConsoleTextAttribute(hConsole, 3);
    Delayer_menu(L1);

    //--------------------------------------
      //************************************************************
    gotoxy(65,10);
    SetConsoleTextAttribute(hConsole, 4);
    Delayer_menu(L1);
        gotoxy(65,11);
    SetConsoleTextAttribute(hConsole, 4);
    Delayer_menu(L2);
        gotoxy(65,12);
    SetConsoleTextAttribute(hConsole, 4);
    Delayer_menu(L10);
        gotoxy(65,13);
    SetConsoleTextAttribute(hConsole, 4);
    Delayer_menu(L2);
         gotoxy(65,14);
    SetConsoleTextAttribute(hConsole, 4);
    Delayer_menu(L1);
//---------------------------------------------------------------
       gotoxy(5,16);
    SetConsoleTextAttribute(hConsole, 6);
    Delayer_menu(L1);
     gotoxy(5,17);
    SetConsoleTextAttribute(hConsole, 6);
    Delayer_menu(L2);
        gotoxy(5,18);
    SetConsoleTextAttribute(hConsole, 6);
    Delayer_menu(L9);
        gotoxy(5,19);
    SetConsoleTextAttribute(hConsole, 6);
    Delayer_menu(L2);
         gotoxy(5,20);
    SetConsoleTextAttribute(hConsole, 6);
    Delayer_menu(L1);
    //------------------------------------------
          gotoxy(10,21);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L1);
        gotoxy(10,22);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L7);
        gotoxy(10,23);
    SetConsoleTextAttribute(hConsole, 13);
    Delayer_menu(L1);


}

void accountSetting_stu(MYSQL* conn){

system("CLS");

	string email , password;
    	 MYSQL_RES* res;
      MYSQL_ROW row;
      email = user_email;
      password = user_password;


        string query = "SELECT * FROM student WHERE email = '" + email + "' AND password = '" + password + "'";

    if (mysql_query(conn, query.c_str())) {
        cout << "Error executing SQL query: " << endl;

    }
  else{

    res = mysql_use_result(conn);

    if ((row = mysql_fetch_row(res))) {
        	cout <<"\n\n";
        cout << "\tYour profile :  " << endl;
        cout << "\t--------------------------------------------------" << endl<< endl;

        cout << "\tFirst Name: " << row[1] << endl<< endl;
        cout << "\tLast Name: " << row[2] << endl<< endl;
        cout << "\tBirthdate: " << row[3] << endl<< endl;
        cout << "\tGender: " << row[4] << endl<< endl;
        cout << "\tGrade: " << row[5] << endl<< endl;
        cout << "\tUsername: " << row[6] << endl<< endl;
        cout << "\tEmail: " << row[7] << endl<< endl;
        cout << "\tPassword: " << row[8] << endl << endl;
        cout << "\t--------------------------------------------------" << endl<< endl;

        char choice;
        cout << "Do you want to edit your profile? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {

            cin.ignore();

            string firstName, lastName, birthdate, gender, grade, newUsername, newEmail, newPassword;
            cout <<"\n\n";
            cout << "\tEnter first name: ";
            getline(cin, firstName);

            cout << "\tEnter last name: ";
            getline(cin, lastName);

            cout << "\tEnter birthdate: ";
            getline(cin, birthdate);

            cout << "\tEnter gender: ";
            getline(cin, gender);

            cout << "\tEnter  grade: ";
            getline(cin, grade);

            cout << "\tEnter  username: ";
            getline(cin, newUsername);

            cout << "\tEnter  email: ";
            getline(cin, newEmail);

            cout << "\tEnter password: ";
            getline(cin, newPassword);

            query = "UPDATE student SET first_name = '" + firstName + "', last_name = '" + lastName + "', birthdate = '" + 	birthdate + "', gender = '" + gender + "', grade = '" + grade + "', username = '" + newUsername + "', email = '" + 	newEmail + "', password = '" + newPassword + "' WHERE email = '" + email + + "' AND password = '" + password + "'";

            if (mysql_query(conn, query.c_str())) {
                cout << "Error executing SQL query: " << endl;

            }
            else{

            cout << "Profile updated successfully!" << endl;
        }
    } else {
        cout << "Profile not found. Invalid username or password." << endl;
    }
}

}
    mysql_free_result(res);
}
void aboutUs(){
	system("CLS");
	 string str1 = " ADDIS ABABA SCIENCE AND TECHNOLOGY UNIVERSITY ";
        string str2 = " COLLAGE OF ENGINEERING";
        string str3 = " DEPARTMENT OF SOFTWARE ENGINEERING";
        string str4 = " FUNDAMENTALS OF PROGRAMMING II";
        string str5 = " SECTION - D";
        string str6 = " Name                             ID_Number                 Telegram_username";
        string str7 = " Mihret Desalegn                 ETS 1074/14                   @MIHRETD";
        string str8 = " Mikias Goitom                   ETS 1080/14                   @MG790";
        string str9 = " Mikiyas Alemayehu Mekonen       ETS 1086/14                   @mikiyalemyehu12";
        string str10 = " Mikiyas Alemayehu Gebrewold     ETS 1087/14                   @zemike48";
        string str11 = " Milkias Yeheyis                 ETS 1101/14                   @jaminux";
        string str12 = "                                       SUBMITTED TO: INST. ELENI TESHOME";
        string str13 = "";
        string str14 = " ABOUT US";
        string str15 = " HAPPY NEW YEAR";

        //*************************************
    gotoxy(33,4);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str14);

     gotoxy(33,5);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str13);

     gotoxy(43,7);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str1);

     gotoxy(59,9);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str2);

     gotoxy(53,11);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str3);

     gotoxy(54,13);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str4);

     gotoxy(62,15);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str5);

     gotoxy(33,17);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str6);

     gotoxy(33,18);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str7);

     gotoxy(33,19);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str8);

     gotoxy(33,20);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str9);

     gotoxy(33,21);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str10);

     gotoxy(33,22);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str11);

     gotoxy(33,23);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str12);

     gotoxy(33,25);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str13);

     gotoxy(33,26);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str15);

    gotoxy(33,27);
    SetConsoleTextAttribute(hConsole, 14);
    Delayer(str13);

}
void  welcome_page(){

	 //---------------------------------------------------------------------------------------------------------------
    gotoxy(33,6);
    cout << "######################################################################" << endl;
      gotoxy(33,7);
    cout << "#                                                                    #" << endl;
      gotoxy(33,8);
    cout << "#                                                                    #" << endl;
      gotoxy(33,9);
    cout << "#                              LIBRARY                               #" << endl;
      gotoxy(33,10);
    cout << "#                             MANAGEMENT                             #" << endl;
      gotoxy(33,11);
    cout << "#                               SYSTEM                               #" << endl;
      gotoxy(33,12);
    cout << "#                                                                    #" << endl;
     gotoxy(33,13);
    cout << "#                                                                    #" << endl;
      gotoxy(33,14);
    cout << "######################################################################" << endl;

      gotoxy(33,16);
     system("pause");
     system("CLS");
     //-----------------------------------------------------------------------------------------------------------------------
}

