// This compiler command acts as a header guard to prevent repetative code running
#ifndef FUNCTIONS_LISTING
#define FUNCTIONS_LISTING

#include <string>
using std::string;

//String Function(s)
/*
- Promopts the user for input and reads the line of text that the user enters
  at the terminal. This will read a in a line of text and return this as a string.
@param prompt       The message displayed to the user
@return             The text the user enters as a string */
string READ_STRING(string prompt);

//Boolean Function(s)
/*
- Promopts the user for a predefined input (such as 'yes' or 'no') and reads the line of text that 
  the user enters at the terminal. This will then compare the user's input as a string and return 
  a boolean expression which is either TRUE or FALSE.
@param prompt       The message displayed to the user
@return             Boolean expression ('TRUE' or 'FALSE') */
bool READ_BOOLEAN(string prompt);

//Double Function(s)
/*
- Promopts the user for input and reads the line of text that the user enters
  at the terminal. This will read a in a line of text and return this as a double.
@param prompt       The message displayed to the user
@return             The text the user enters as a double */
double READ_DOUBLE(string prompt);

/*
- Promopts the user for input and reads the line of text that the user enters
  at the terminal. This will read a in a line of text and return this as a double.
  This variation contains upper(max) and lower(min) bounds for the user to enter a 
  value inbetween.
@param prompt       The message displayed to the user
@param min          The minumum value that the user is allowed to input
@param max          The maximum value that the user is allowed to input
@return             The text the user enters as a double */
double READ_DOUBLE(string prompt, double min, double max);

//Integer Function(s)
/*
- Promopts the user for input and reads the line of text that the user enters
  at the terminal. This will read a in a line of text and return this as an integer. 
@param prompt       The message displayed to the user
@return             The text the user enters as an integer */
int READ_INT(string prompt);

/*
- Promopts the user for input and reads the line of text that the user enters
  at the terminal. This will read a in a line of text and return this as an integer.
  This variation contains upper(max) and lower(min) bounds for the user to enter a 
  value inbetween. 
@param prompt       The message displayed to the user
@param min          The minumum value that the user is allowed to input
@param maz          The maximum value that the user is allowed to input
@return             The text the user enters as an integer */
int READ_INT(string prompt, int min, int max);

#endif