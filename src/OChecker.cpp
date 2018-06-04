#include "OChecker.h"

//override the function "checkMyLetter"
//create the function definition here
char OChecker::checkMyLetter(char inputChar) 
{
	//std::cout << "\nDefault letter '*' used." << std::endl;

	if( inputChar == 'o' || inputChar == 'O')

	{		
		return '*';
	}
	else
		return 'o';
}
