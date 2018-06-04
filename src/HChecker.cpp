#include "HChecker.h"

//override the function "checkMyLetter"
//create the function definition here
char HChecker::checkMyLetter(char inputChar) 
{
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if(inputChar == 'h' || inputChar == 'H')
	{		
		return 'h';
	}

	else
	return '*';
}


