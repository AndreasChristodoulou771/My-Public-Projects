#include "splashkit.h"
using namespace std;

//String Functions
string READ_STRING(string prompt)
{
    string result;

    write(prompt);
    result = read_line();

    return result;
}

string READ_STRING(string prompt, bool x) // IN TESTING
{
    string string_result;
    string_result = READ_STRING(prompt);

    //Works, but still allows combined string and number responses like 'Dave5'
    while (x == true)
    {
        {
            for (int i = 0; i < string_result.length(); i++)
            {
                char char_pos = string_result.at(i);
                if (!((char_pos >= 'a' && char_pos <= 'z') || (char_pos >= 'A' && char_pos <= 'Z')))
                {
                    write_line("Please enter only alphabetical characters. Thank you.");
                    string_result = READ_STRING(prompt, true);
                }
                break;
            }
            break;
        }
        break;
    }

    return string_result;
}

//Boolean Functions
bool READ_BOOLEAN(string prompt)
{
    string text_result;
    string text_convert;

    text_result = READ_STRING(prompt);
    text_convert = to_lowercase(text_result);

    while (((text_convert != "yes") and (text_convert != "no") and
            (text_convert != "y") and (text_convert != "n")))
    {
        write_line("Please respond with either yes, or no");
        text_result = READ_STRING(prompt);
        text_convert = to_lowercase(text_result);
    }

    if (text_convert == "yes")
    {
        return true;
    }

    else if (text_convert == "y")
    {
        return true;
    }

    else
    {
        return false;
    }
}

//Double Functions
double READ_DOUBLE(string prompt)
{
    string age_string;
    double age;

    write(prompt);
    age_string = read_line();

    while (is_integer(age_string))
    {
        delay(500);
        write_line("Please enter a decimal number. ");
        delay(1000);
        write_line(prompt);
        age_string = read_line();
    }

    age = convert_to_double(age_string);

    return age;
}

double READ_DOUBLE(string prompt, double min, double max)
{
    double number_result;

    number_result = READ_DOUBLE(prompt);

    while (number_result < min or number_result > max)
    {
        if (number_result > max)
        {
            delay(500);
            write_line("The decimal number must be less than " + to_string(max));
            delay(1000);
            number_result = READ_DOUBLE(prompt);
        }

        else if (number_result)
        {
            delay(500);
            write_line("The decimal number must be greater than " + to_string(min));
            delay(1000);
            number_result = READ_DOUBLE(prompt);
        }
    }
    return number_result;
}

//Integer Functions
int READ_INT(string prompt)
{
    string age_string;
    int age;

    write(prompt);
    age_string = read_line();

    //This while loop ensures that the user inputs an integer
    while (not is_integer(age_string))
    {
        delay(500);
        write_line("Please enter a whole number. ");
        delay(1000);
        write_line(prompt);
        age_string = read_line();
    }
    age = convert_to_integer(age_string);

    return age;
}

int READ_INT(string prompt, int min, int max)
{
    int number_result;

    number_result = READ_INT(prompt);

    while (number_result < min or number_result > max)
    {
        if (number_result > max)
        {
            delay(500);
            write_line("Please enter a number below " + to_string(max));
            delay(1000);
            number_result = READ_INT(prompt);
        }
        else if (number_result < min)
        {
            delay(500);
            write_line("Please enter a number above " + to_string(min));
            delay(1000);
            number_result = READ_INT(prompt);
        }
    }

    return number_result;
}