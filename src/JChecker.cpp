#include "JChecker.h"

//override the function "checkMyLetter"
//create the function definition here

char JChecker::checkMyLetter(char inputChar)
{
	if(std::tolower(inputChar) == 'j')
	{
		return 'j';
	}
	return defaultLetter;
}

