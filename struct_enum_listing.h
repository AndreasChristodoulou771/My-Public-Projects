// This compiler command acts as a header guard to prevent repetative code running
#ifndef STRUCT_ENUM_LISTING
#define STRUCT_ENUM_LISTING
#include "splashkit.h"

/*
//////////MENU SECTION\\\\\\\\\\
*/
// Initial Menu options
enum initial_menu_op
{
    ACCEESS_ACCOUNT,
    EDIT_USERS,
    EXIT
};

// User Creation Menu Options
enum user_cretn_menu
{
    ADD_USER,
    DELETE_USER,
    UCRE_BACK
};

// Account Login-Menu Options
enum account_accs_op
{
    ENTER_LOG_DETAILS,
    AACC_BACK
};

// Account Menu Options
enum account_op
{
    VIEW_PASSWORDS,
    ADD_PASSWORDS,
    DELETE_PASSWORDS,
    EXIT_ACCOUNT
};

// Struct Declarations Pertaining to Menu Options
initial_menu_op INT_MENU_SELECTIONS();
user_cretn_menu USER_CRETN_MENU_SELECTIONS();
account_accs_op ACC_LOGIN_MENU_SELECTIONS();
account_op ACC_MENU_SELECTIONS();

/*
//////////DATABASE_SECTION\\\\\\\\\\
*/

// Passwrd Data
struct password_information
{
    // ACCOUNT_NO LINK
    int account_numb;

    // The password the user stores
    string user_password;

    // The purpose of the password
    string reason_password;
};

// User Account Data
struct user_account_data
{
    // Personal Data
    string name;
    int age;

    // Login Data
    string user_name;
    string mast_password;

    // Account No - User doesn't see this
    int account_numb;
};

// Database
struct PM_database
{
    vector<user_account_data> accounts;
    vector<password_information> passwords;
};

// Struct Declarations

user_account_data READ_ULOGIN_DATA();

password_information READ_PDATA();

string ENCRYPTION_TO_SYS(string txt_input, string key);

#endif
