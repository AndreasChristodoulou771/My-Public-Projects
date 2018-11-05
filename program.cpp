#include "splashkit.h"
#include "functions_listing.h"
#include "struct_enum_listing.h"
#include "user_add_listing.h"

// General Notes for this program (If any):
/*
- Snake Case Syntax
    Snake Case is used with some alterations:
    - Procedures, Custom Functions and Constants made within the program are CAPITALISED.

    Apart from the above change(s), the syntax of Snake Case is default lowercase, with 
    underscores ' _ ' for spaces, being used with all other statements and instructions.
- Program State (For Task 9.4)

    NOTE THIS PROGRAM IS IN PRESENTATION STATE
    BUILD DEBUG FEATURES - OFF for 9.4

    1. Can Compile and Run:                             Y
    2. Can Add Users:                                   Y
    3. Can Delete Users (basic):                        Y
    4. Can Compile Accounts Within Program:             Y
    5. Can Recognise Multiple Login Credentials:        Y
    6. Can Pass Data Through Entire Program:            Y
    7. Can Access Individual User Accounts:             Y       
    8. Can Save User Account Data to a Database:        Y       
    9. Can Save Password Data to individual accounts:   Y
    10.Has Encryption on the User accounts:             Y
    11.Has Encryption on the User Passwords Stored:     Y
- Build Notes:
    1. Implement database structure to recall info
        a. Find a way to write info into a file so data remains when program opens/closes       COMPLETE
        b. Database file records no data, find a fix                                            COMPLETE
    2. Login Access
        a. Find a way to have the Program enter separate accounts once successful login occurs  COMPLETE
- Debbug Proceedures Implemented:
    1. DISPLAY_USERS()                                                                          FUNCTIONAL
    2. SHOW_COMPILED_UDATABASE(database selected_database, string table_name)                   FUNCTIONAL

- Other Notes
    - For the Purpose of presenting this program, the encryption key is simple
        - key1 for User Accounts (anything to do with the users)
        - key2 for the data stores (i.e. passwords created by the user)
    - I'm aware that c++ splashkit is currently using sql lite, this has prevented me
      from using more advanced SQL commands such as DELETE CASCADE ON. Which removes 
      all associated rows in the child table.
*/

// As I do not have any knowledge experimenting with advanced terminal. For now, this procedure clears the termnial by creating a big gap of spaces.
void LINE_SPACES()
{
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
    write_line();
}

// User Creation Menu
void USER_CREATION_MENU(PM_database &c_database)
{
    user_cretn_menu selection;
    int del_selection;

    do
    {
        selection = USER_CRETN_MENU_SELECTIONS();
        switch (selection)
        {
        case ADD_USER:
            LINE_SPACES();

            ADD_USER_ACCOUNT(c_database);
            COMPILE_DATABASE_V2(c_database);

            break;

        case DELETE_USER:
            LINE_SPACES();

            REMOVE_ACCOUNT(c_database);

        case UCRE_BACK:
            write_line("Entering...");
            delay(1000);

            LINE_SPACES();

            break;

        default:
            write_line("Please select a valid option.");

            break;
        }
    } while (selection != UCRE_BACK);
}

// Acount Login Menu
int ACC_LOGIN_MENU(PM_database &c_database)
{

    account_accs_op selection;

    do
    {
        selection = ACC_LOGIN_MENU_SELECTIONS();
        switch (selection)
        {
        case ENTER_LOG_DETAILS:
            int account_access;
            account_access = LOGIN_PROCESS_V1(c_database);
            return account_access;
            break;

        case AACC_BACK:
            write_line("Entering...");
            delay(1000);

            LINE_SPACES();
            break;

        default:
            write_line("Please select a valid option.");
        }
    } while (selection != AACC_BACK);

    return -1;
}

// Account Menu
void ACC_MENU(PM_database &c_database, int &account_no)
{
    account_op selection;

    string account_name = c_database.accounts[account_no].user_name;

    // Double ENCRYPTION is here on purpose:
    account_name = ENCRYPTION_TO_SYS(account_name, "key1");
    account_name = ENCRYPTION_TO_SYS(account_name, "key1");

    // write_line(account_name + "'s account:");

    do
    {
        selection = ACC_MENU_SELECTIONS();

        switch (selection)
        {
        case VIEW_PASSWORDS:
            write_line("Entering... ");
            LINE_SPACES();
            SHOW_COMPILED_PDATABASE(account_no);

            break;

        case ADD_PASSWORDS:
            write_line("Entering... ");
            LINE_SPACES();
            ADD_PASSWORD(c_database, account_no);
            COMPILE_PASSDATABASE(c_database, account_no);

            break;

        case DELETE_PASSWORDS:
            write_line("Entering... ");
            LINE_SPACES();
            REMOVE_PASSWORD(c_database, account_no);

            break;

        case EXIT_ACCOUNT:
            LINE_SPACES();

            break;

        default:
            write_line("Please select a valid option.");

            break;
        }
    } while (selection != EXIT_ACCOUNT);
}

int main()
{
    // Ensures database is closed at begining of program
    free_database("PM_DATA");
    free_all_query_results();

    database origin_user_database;
    PM_database c_database;
    c_database.accounts = vector<user_account_data>();
    c_database.passwords = vector<password_information>();

    CREATE_UTABLE(origin_user_database);

    PULL_FROM_UDATABASE(c_database, origin_user_database, "accounts");
    PULL_FROM_PDATABASE(c_database, origin_user_database, "pass_data");

    write_line();
    write_line("====MAIN MENU====");
    write_line();

    initial_menu_op selection;

    do
    {
        selection = INT_MENU_SELECTIONS();

        switch (selection)
        {
        case ACCEESS_ACCOUNT:
            write_line("Entering... ");
            delay(1000);

            LINE_SPACES();
            int account_access;
            account_access = ACC_LOGIN_MENU(c_database);
            if (account_access == -1)
            {
                LINE_SPACES();
                write_line("Credentials do not match");
                delay(3000);
                LINE_SPACES();

                break;
            }
            else
            {
                LINE_SPACES();
                ACC_MENU(c_database, account_access);

                break;
            }

            break;

        case EDIT_USERS:
            write_line("Entering... ");
            delay(1000);

            LINE_SPACES();
            USER_CREATION_MENU(c_database);

            break;

        case EXIT:
            write_line("Closing...");
            delay(1000);

            break;

        default:
            write_line("Please select a valid option.");

            break;
        }
    } while (selection != EXIT);

    free_all_query_results();
    free_database("PM_DATA");

    return 0;
}