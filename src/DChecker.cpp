#include "DChecker.h"

//override the function "checkMyLetter"
//create the function definition here


char DChecker::checkMyLetter(char inputChar) 
{
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if( inputChar == 'D' || inputChar == 'd')
		return 'd';
	else
		return defaultLetter;
}


