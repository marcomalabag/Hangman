#include "ZChecker.h"

//override the function "checkMyLetter"
//create the function definition here
#include "LetterChecker.h"

//always returns defaultLetter :P
char ZChecker::checkMyLetter(char inputChar) 
{	
	//std::cout << "\nDefault letter '*' used." << std::endl;
	
	
	if (inputChar =='z' || inputChar =='Z')
	{
		return 'z';
	}
	else
		return '*';
}


