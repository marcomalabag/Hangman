#include "EChecker.h"

//always returns defaultLetter :P	
char EChecker::checkMyLetter(char inputChar)
{
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if(inputChar == 'E' || inputChar == 'e')
	{		
		return 'e';
	}
	else
		return defaultLetter;
}
