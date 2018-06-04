#include "FChecker.h"

//always returns defaultLetter :P
char FChecker::checkMyLetter(char inputChar)
{
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if(inputChar == 'F' || inputChar == 'f')
	{
		return 'f';
	}
	else
		return defaultLetter;
}
