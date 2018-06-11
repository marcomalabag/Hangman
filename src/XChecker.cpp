#include "XChecker.h"

//override the function "checkMyLetter"
//create the function definition here
char XChecker::checkMyLetter(char inputChar) 
{
	if(inputChar == 'x' || inputChar == 'X')
	{		
		return 'x';
	}
	else
	{
		return defaultLetter;
	}
}

