#include "IChecker.h"

//override the function "checkMyLetter"
//create the function definition here

char IChecker::checkMyLetter(char inputChar) 
{
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if(inputChar == 'i'||inputChar=='I'){
		return 'i';
	}
	else
		return '*';
}

