#include "JChecker.h"

//override the function "checkMyLetter"
//create the function definition here

char JChecker::checkMyLetter(char inputChar)
{
	std::cout << "Using overriden checkMyLetter function";
	if(inputChar == defaultLetter)
	{
		return std::tolower(inputChar);
	}
	return defaultLetter;
}

