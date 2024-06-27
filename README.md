﻿# Library_Management_System


Steps for compiling and running the project 

1. Copy the source code provided. Open the Dev-C++ IDE and create a new file (.dev) in project and add the parameters and directories to the project.Paste the copied source code into this .dev file.

2. Insert Database Server Password. Locate the line in the code: char pass[] = "password". Replace "password" with your actual MySQL database server password.

3. Set Up Database:
    Open MySQL Workbench and Import the library_database.sql file provided. Execute the queries to create the necessary tables (student, admin, books) and dont forget to execute all the queries. Once done, refresh      the schema to ensure the library_database is displayed with the three tables.

4. Finally, Go back to the Dev-C++ IDE. Compile and run the code.
