#include "UChecker.h"

//override the function "checkMyLetter"
//create the function definition here
char UChecker::checkMyLetter(char inputChar) 
{
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if(inputChar == 'u' || inputChar == 'U'){
		return 'u';	
	}

	else
		return '*';
}



