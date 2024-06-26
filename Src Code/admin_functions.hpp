#ifndef ADMIN_FUNCTIONS_HPP
#define ADMIN_FUNCTIONS_HPP

#include <string>
#include "console_functions.hpp"
#include <mysql.h>

// Function prototypes
void admin_menu();
void loginadmin(MYSQL* conn);
void registeradmin(MYSQL* conn);
bool checkCredentials(MYSQL* conn, const string& email, const string& password);
void addbook(MYSQL* conn);
void Delete(MYSQL* conn);
void search(MYSQL* conn);
void updatedbook(MYSQL* conn);
void displayAllBooks(MYSQL* conn);
void accountSetting_admin(MYSQL* conn);
void countdown(string str, int color,int x , int y);

#endif

