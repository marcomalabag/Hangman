#include "PChecker.h"

//override the function "checkMyLetter"
//create the function definition here

char PChecker::checkMyLetter(char inputChar)
{
	if(inputChar == 'p' || inputChar == 'P')
	{
		return 'p';
	}
	else{
		return '*';
	}
}
