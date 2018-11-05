// This compiler command acts as a header guard to prevent repetative code running
#ifndef USER_ADD_LISTING
#define USER_ADD_LISTING
#include "splashkit.h"

/*
//////////USER CREATION / AUTHENTICATION SECTION\\\\\\\\\\
*/

/*
- Procedure that reads user input for the purpose of creating an account,
  then saves to the internal program storage (i.e. struct).
@struct data       Reads program data */
void ADD_USER_ACCOUNT(PM_database &data);

/*
- Procedure that reads user input for the purpose of removing an account from the program,
  then clears struct holdings and re-updates it from the SQL Database.
@struct data       Updates program data */
void REMOVE_ACCOUNT(PM_database &data);

/*
- Procedure that reads user input for the purpose of Authenticating an existing account in the program,
  upon a successful confirmation of account identity, function then returns the account number.
@struct data       Reads program data 
@return            The account number of the authenticated user */
int LOGIN_PROCESS_V1(PM_database &data);

/*
- Procedure that compiles new account data and writes it to the SQL Database. i.e. Account Compiler - to SQL DATABASE
@struct data       Reads program data */
void COMPILE_DATABASE_V2(PM_database &data);

/*
- Procedure that 'pulls' account data from the SQL Database and then updates the program structs. i.e. Account Compiler - from SQL DATABASE
@struct     data                  Updates program data
@param      selected_database     The SQL database being operated
@param      table_name            The SQL table being accessed */
void PULL_FROM_UDATABASE(PM_database &data, database selected_database, string table_name);

/*
- Procedure that runs on program startup for the purpose of creating SQL Database tables if the program
  has not been opened previously. 
@param    selected_database     The SQL database being operated */
void CREATE_UTABLE(database selected_database);

/*
//////////USER ACCOUNT / PASSWORD SECTION\\\\\\\\\\
*/

/*
- Procedure that compiles user password data and writes it to the SQL Database. i.e. Compile User Password Database - to SQL DATABASE
@struct      data       Reads program data
@param       account_no The account number (so we know which account data is being compiled from) */
void COMPILE_PASSDATABASE(PM_database &data, int account_no);

// Compile User Password Database - from SQL DATABASE

/*
- Procedure that 'pulls' user password data from the SQL Database and then updates the 
  program structs. i.e. Account Compiler - from SQL DATABASE
@struct         data                  Updates program data
@param          selected_database     The SQL database being operated
@param          table_name            The SQL table being accessed */
void PULL_FROM_PDATABASE(PM_database &data, database selected_database, string table_name);

/*
- Procedure that reads user input for the purpose of creating a new user password,
  then saves to the internal program storage (i.e. struct).
@struct data       Reads program data */
void ADD_PASSWORD(PM_database &database, int account_no);

/*
- Procedure that displays user created passwords pertaining to the user 
  account number,
@param account_no       The user account number to cross check the passwords accessable */
void SHOW_COMPILED_PDATABASE(int account_no);

/*
- Procedure that reads user input for the purpose of removing user created Passwords from the account,
  then clears struct holdings and re-updates it from the SQL Database.
@struct    data             Updates program data
@param     account_no       The user account number to cross check the passwords accessable */
void REMOVE_PASSWORD(PM_database &data, int account_no);

/*
//////////DEBUGG PROCEDURES\\\\\\\\\\
*/

/*
- DEBUG Procedure that displays all user accounts stored in the internal struct data in the program.
@struct user            Reads user data */
void DISPLAY_USERS(const user_account_data &user);

/*
- DEBUG Procedure that displays all user accounts stored in the internal struct data in the program.
@param selected_database  The SQL database being operated 
@param table_name         The SQL table being accessed */
void SHOW_COMPILED_UDATABASE(database selected_database, string table_name);

#endif