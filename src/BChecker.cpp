#include "BChecker.h"

//override the function "checkMyLetter"
//create the function definition here

char BChecker::checkMyLetter(char inputChar) 
{
		//std::cout << "\nDefault letter '*' used." << std::endl;
	if( inputChar == 'b' && inputChar == 'B')
	{		
		return 'b';
	}
	else 
	    return '*';
}
