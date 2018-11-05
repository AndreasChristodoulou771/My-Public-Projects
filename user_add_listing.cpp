#include "splashkit.h"
#include "functions_listing.h"
#include "struct_enum_listing.h"

using namespace std;

// DEBUG - Shows all users in the Program SQL Database - SHOULD SHOW DATA ENCRYPTED
void SHOW_COMPILED_UDATABASE(database selected_database, string table_name)
{
    selected_database = open_database("PM_DATA", "Database_V1");

    write_line("|||||||||||||||SQL__TEST|||||||||||||||");
    // Test to see if it works
    query_result cursor;

    cursor = run_sql(selected_database, "select * from " + table_name + ";");
    // write_line("select * from " + table_name + ";");
    for (reset_query_result(cursor); has_row(cursor); get_next_row(cursor))
    {
        write_line(query_column_for_int(cursor, 0));
        write_line(query_column_for_string(cursor, 1));
        write_line(query_column_for_int(cursor, 2));
        write_line(query_column_for_string(cursor, 3));
        write_line(query_column_for_string(cursor, 4));
    }
    write_line("|||||||||||||||SQL__TEST|||||||||||||||");

    free_all_query_results();
    free_database("PM_DATA");
}

// Shows user-relevant Password information in the User Program SQL Database
void SHOW_COMPILED_PDATABASE(int account_no)
{
    database selected_database;
    selected_database = open_database("PM_DATA", "Database_V1");

    string table_name = "pass_data";

    write_line("|||||||||||||||PASSWORDS|||||||||||||||");
    // Test to see if it works
    query_result cursor;

    cursor = run_sql(selected_database, "select * from " + table_name + " where account_no = " + to_string(account_no) + ";");
    // write_line("select * from " + table_name + " where account_no = " + to_string(account_no) + ";");
    for (reset_query_result(cursor); has_row(cursor); get_next_row(cursor))
    {
        string p1, p2;
        p1 = query_column_for_string(cursor, 1);
        p2 = query_column_for_string(cursor, 2);

        p1 = ENCRYPTION_TO_SYS(p1, "key2");
        p2 = ENCRYPTION_TO_SYS(p2, "key2");

        write_line();
        write_line("Password: " + p1);
        write_line("Purpose: " + p2);
        write_line();
    }
    write_line("|||||||||||||||PASSWORDS|||||||||||||||");
}

// DEBUG - Displays user details for debbugging purposes
void DISPLAY_USERS(const user_account_data &user)
{
    write_line("Account No: " + to_string(user.account_numb));
    write_line("Name: " + user.name);
    write_line("Age: " + to_string(user.age));
    write_line("Username: " + user.user_name);
    write_line("MastPASS: " + user.mast_password);
}

//Displays user accounts in system
void DISPLAY_USERS_LIM(const user_account_data &user)
{
    write_line("Account No: " + to_string(user.account_numb));
    write_line("Name: " + user.name);
    write_line("Username: " + user.user_name);
}

void DISPLAY(PM_database &data)
{
    write_line("|||||||||||||||USER ACCOUNTS|||||||||||||");
    for (int i = 0; i < data.accounts.size(); i++)
    {
        data.accounts[i].account_numb = i;
        DISPLAY_USERS_LIM(data.accounts[i]);
    }
    write_line("|||||||||||||||USER ACCOUNTS|||||||||||||||");
}

void PULL_FROM_UDATABASE(PM_database &data, database selected_database, string table_name)
{
    selected_database = open_database("PM_DATA", "Database_V1");

    query_result cursor;

    cursor = run_sql(selected_database, "select * from " + table_name + ";");
    for (reset_query_result(cursor); has_row(cursor); get_next_row(cursor))
    {
        //Pulls User Data from the SQL Database
        user_account_data result;
        result.account_numb = query_column_for_int(cursor, 0);
        result.name = query_column_for_string(cursor, 1);
        result.age = query_column_for_int(cursor, 2);
        result.user_name = query_column_for_string(cursor, 3);
        result.mast_password = query_column_for_string(cursor, 4);

        //Decryption Method
        result.name = ENCRYPTION_TO_SYS(result.name, "key1");
        result.user_name = ENCRYPTION_TO_SYS(result.user_name, "key1");
        result.mast_password = ENCRYPTION_TO_SYS(result.mast_password, "key1");

        data.accounts.push_back(result);
    }

    free_all_query_results();
    free_database("PM_DATA");

    // SHOW_COMPILED_UDATABASE(selected_database, table_name);
    // DISPLAY(data);
}

void PULL_FROM_PDATABASE(PM_database &data, database selected_database, string table_name)
{
    selected_database = open_database("PM_DATA", "Database_V1");

    query_result cursor;

    // write_line("start");
    cursor = run_sql(selected_database, "select * from " + table_name + ";");
    for (reset_query_result(cursor); has_row(cursor); get_next_row(cursor))
    {
        //Pulls Password Data from the SQL Database
        password_information result;
        result.account_numb = query_column_for_int(cursor, 0);
        result.user_password = query_column_for_string(cursor, 1);
        result.reason_password = query_column_for_int(cursor, 2);

        //Decryption Method
        result.user_password = ENCRYPTION_TO_SYS(result.user_password, "key2");
        result.reason_password = ENCRYPTION_TO_SYS(result.reason_password, "key2");

        data.passwords.push_back(result);
    }

    free_all_query_results();
    free_database("PM_DATA");
}

void CREATE_UTABLE(database selected_database) // CHECK TABLE CASCADE DELETE
{
    selected_database = open_database("PM_DATA", "Database_V1");
    bool x = READ_BOOLEAN("Is this the first time the program has been opened? ");
    if (x == true)
    {
        // Creates User Table in Database
        run_sql(selected_database, "CREATE TABLE accounts (account_no INTEGER ,name TEXT, age INTEGER, user_name VARCHAR(20), mast_pass VARCHAR(30), PRIMARY KEY(account_no));");
        // write_line("CREATE TABLE accounts (account_no INTEGER ,name TEXT, age INTEGER, user_name VARCHAR(20), mast_pass VARCHAR(30), PRIMARY KEY(account_no));");

        // Creates Password Table in Database
        run_sql(selected_database, "CREATE TABLE pass_data (account_no INTEGER, paswrd_userpass VARCHAR(30), paswrd_purpose VARCHAR(30), FOREIGN KEY(account_no) REFERENCES accounts (account_no) ON DELETE CASCADE);");
        // write_line("CREATE TABLE pass_data (account_no INTEGER, paswrd_userpass VARCHAR(30), paswrd_purpose VARCHAR(30), FOREIGN KEY(account_no) REFERENCES accounts (account_no) ON DELETE CASCADE);");
    }
    free_database("PM_DATA");
}

void ADD_USER_ACCOUNT(PM_database &data)
{
    user_account_data new_account;
    new_account = READ_ULOGIN_DATA();

    data.accounts.push_back(new_account);
}

void DELETE_USER_ACCOUNT(PM_database &data, int index)
{
    if (index >= 0 and index < data.accounts.size())
    {
        int rmv_index;
        rmv_index = data.accounts.size() - 1;
        data.accounts[index] = data.accounts[rmv_index];
        data.accounts.pop_back();
    }
}

void REMOVE_ACCOUNT(PM_database &data)
{
    //Shows User Accounts In the System
    DISPLAY(data);

    string un_selection, n_selection;
    int del_selection;
    database compiled_db;
    compiled_db = open_database("PM_DATA", "Database_V1");

    // Reads user input
    un_selection = READ_STRING("Enter User_Name of Account you want to remove: ");
    n_selection = READ_STRING("Enter Name of Account you want to remove: ");

    // Converts Plain-Text to Encrypted-Text for the SQL Database
    un_selection = ENCRYPTION_TO_SYS(un_selection, "key1");
    n_selection = ENCRYPTION_TO_SYS(n_selection, "key1");

    query_result cursor;

    cursor = run_sql(compiled_db, "select * from accounts where user_name = '" + un_selection + "' and name = '" + n_selection + "';");
    if (has_row(cursor))
    {
        write_line("Deleting Now...");
        del_selection = query_column_for_int(cursor, 0);

        cursor = run_sql(compiled_db, "delete from accounts where user_name = '" + un_selection + "' and name = '" + n_selection + "';");

        DELETE_USER_ACCOUNT(data, (del_selection - 1));

        data.accounts.clear();
        PULL_FROM_UDATABASE(data, compiled_db, "accounts");
    }
    else
    {
        write_line("Account Does Not Exist");
    }

    free_all_query_results();
    free_database("PM_DATA");
}

void COMPILE_DATABASE_V2(PM_database &data)
{
    database compiled_db = open_database("PM_DATA", "Database_V1");

    //Compile the most recent user created to SQL Database
    int i;
    i = data.accounts.size() - 1;

    run_sql(compiled_db, "INSERT INTO accounts VALUES (" + to_string(i) + ",'" + data.accounts[i].name + "'," + to_string(data.accounts[i].age) + ",'" + data.accounts[i].user_name + "','" + data.accounts[i].mast_password + "');");

    free_all_query_results();
    free_database("PM_DATA");

    // DEBUG:
    // SHOW_COMPILED_UDATABASE(compiled_db, "accounts");
    // DISPLAY(data);
}

void COMPILE_PASSDATABASE(PM_database &data, int account_no)
{
    database compiled_db = open_database("PM_DATA", "Database_V1");

    //Compile the most recent user created to SQL Database
    int i = 0;
    i = data.passwords.size() - 1;

    query_result result = run_sql(compiled_db, "INSERT into pass_data VALUES(" + to_string(account_no) + ",'" + data.passwords[i].user_password + "','" + data.passwords[i].reason_password + "');");
    // write_line(rows_changed(compiled_db));

    free_all_query_results();
    free_database("PM_DATA");
}

int LOGIN_PROCESS_V1(PM_database &data)
{
    string challenge_u, challenge_mp;
    int authentication;
    int account_no;
    bool success;

    // Reads user input
    challenge_u = READ_STRING("Username: ");
    challenge_mp = READ_STRING("Master Password: ");

    // Converts Plain-Text to Encrypted-Text for the SQL Database
    challenge_u = ENCRYPTION_TO_SYS(challenge_u, "key1");
    challenge_mp = ENCRYPTION_TO_SYS(challenge_mp, "key1");

    database compiled_db = open_database("PM_DATA", "Database_V1");

    query_result cursor;
    cursor = run_sql(compiled_db, "select * from accounts where user_name = '" + challenge_u + "' and mast_pass = '" + challenge_mp + "';");
    if (has_row(cursor))
    {
        write_line("Success!");
        write_line("Entering account: " + query_column_for_string(cursor, 1));
        account_no = query_column_for_int(cursor, 0);
        success = true;

        free_all_query_results();
        free_database("PM_DATA");
    }
    else
    {
        success = false;

        free_all_query_results();
        free_database("PM_DATA");
    }

    if (success == true)
    {
        return account_no;
    }

    else if (success == false)
    {
        return (-1);
    }
    return (-1);
}

//Passwords Segment

void ADD_PASSWORD(PM_database &database, int account_no)
{
    password_information new_pass;
    new_pass = READ_PDATA();

    database.passwords.push_back(new_pass);
}

void DELETE_PASSWORD(PM_database data, int index)
{

    if (index >= 0 and index < data.passwords.size())
    {
        int rmv_index;
        rmv_index = data.passwords.size() - 1;
        data.passwords[index] = data.passwords[rmv_index];
        data.passwords.pop_back();
    }
}

void REMOVE_PASSWORD(PM_database &data, int account_no)
{
    int del_selection;
    string p_selection;
    database compiled_db;
    compiled_db = open_database("PM_DATA", "Database_V1");

    // Reads user input
    p_selection = READ_STRING("Enter the name of the Password that you want to remove: ");

    // Converts Plain-Text to Encrypted-Text for the SQL Database
    p_selection = ENCRYPTION_TO_SYS(p_selection, "key2");

    query_result cursor;

    cursor = run_sql(compiled_db, "select * from pass_data where paswrd_userpass = '" + p_selection + "';");
    if (has_row(cursor))
    {
        write_line("Deleting Now...");
        del_selection = query_column_for_int(cursor, 0);

        cursor = run_sql(compiled_db, "delete from pass_data where paswrd_userpass = '" + p_selection + "';");
        DELETE_PASSWORD(data, (del_selection - 1));

        data.passwords.clear();
        PULL_FROM_PDATABASE(data, compiled_db, "pass_data");
    }
    else
    {
        write_line("Password Does Not Exist");
    }

    free_all_query_results();
    free_database("PM_DATA");
}
