#include "splashkit.h"
#include "struct_enum_listing.h"
#include "functions_listing.h"

using namespace std;

string ENCRYPTION_TO_SYS(string txt_input, string key)
{
    int ki = 0;
    for (int i = 0; i < txt_input.length(); i++)
    {
        txt_input[i] = txt_input[i] ^ key[ki];

        ki++;
        if (ki >= key.length())
        {
            ki = 0;
        }
    }

    return txt_input;
}


/*
//////////MENU SECTION\\\\\\\\\\
*/

// Initial Menu Option Selection
initial_menu_op INT_MENU_SELECTIONS()
{
    int result;
    write_line("1 - Access account ");
    write_line("2 - Edit Users ");
    write_line("3 - Exit ");

    result = READ_INT("Select Option: ");
    return static_cast<initial_menu_op>(result - 1);
}

// User Creation Menu Option Selection
user_cretn_menu USER_CRETN_MENU_SELECTIONS()
{
    int result;
    write_line("1 - Make New User Account ");
    write_line("2 - Remove User");
    write_line("3 - Back ");

    result = READ_INT("Select Option: ");
    return static_cast<user_cretn_menu>(result - 1);
}

// Account Login-Menu Option Selection
account_accs_op ACC_LOGIN_MENU_SELECTIONS()
{
    int result;
    write_line("1 - Enter Login ");
    write_line("2 - Back ");

    result = READ_INT("Select Option: ");
    return static_cast<account_accs_op>(result - 1);
}

// Account Menu Option Selections
account_op ACC_MENU_SELECTIONS()
{
    int result;
    write_line("1 - View Passwords ");
    write_line("2 - Add Password ");
    write_line("3 - Delete Password ");
    write_line("4 - Exit Account ");

    result = READ_INT("Select Option: ");
    return static_cast<account_op>(result - 1);
}

/*
//////////USER ACCOUNT SECTION\\\\\\\\\\
*/

// Read new user account data
user_account_data READ_ULOGIN_DATA()
{
    user_account_data result;

    // User Personal Data
    result.name = READ_STRING("Please Enter Your Name: ");
    result.age = READ_INT("Please Enter Your Age: ", 0, 110);

    // User Login Data
    result.user_name = READ_STRING("Please Enter New Username: ");
    result.mast_password = READ_STRING("Please Enter Password: ");

    // Encryption
    result.name = ENCRYPTION_TO_SYS(result.name, "key1");
    result.user_name = ENCRYPTION_TO_SYS(result.user_name, "key1");
    result.mast_password = ENCRYPTION_TO_SYS(result.mast_password, "key1");

    return result;
}

password_information READ_PDATA()
{
    password_information result;

    // Password
    result.user_password = READ_STRING("Enter Password: ");

    // Password Purpose
    result.reason_password = READ_STRING("Enter Password Purpose: ");

    // Encryption
    result.user_password = ENCRYPTION_TO_SYS(result.user_password, "key2");
    result.reason_password = ENCRYPTION_TO_SYS(result.reason_password, "key2");

    return result;
}

