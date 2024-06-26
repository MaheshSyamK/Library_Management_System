#ifndef STUDENT_FUNCTIONS_HPP
#define STUDENT_FUNCTIONS_HPP

#include <mysql.h>
#include "console_functions.hpp"
#include <string>

using namespace std;

void student_menu();
void login_student(MYSQL* conn);
bool register_student(MYSQL* conn, const string& firstName, const string& lastName, const string& birthdate, const string& gender, const string& grade, const string& username, const string& email, const string& password);
bool studentLogin(MYSQL* conn, const string& email, const string& password);
void displayBookStatus(MYSQL* conn);
void accountSetting_stu(MYSQL* conn);
void displaybyDep(MYSQL* conn);
void displayBooksByDepartment(MYSQL* conn, const string& department);
void Takebook(MYSQL* conn);

#endif

