#include "LetterChecker.h"

//always returns defaultLetter :P
char LetterChecker::checkMyLetter(char inputChar) 
{
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if(  inputChar == defaultLetter )
	{		
		return defaultLetter;
	}
	else
		return defaultLetter;
}

//sets defaultLetter to '*'
LetterChecker::LetterChecker() : defaultLetter{'*'}
{	
}

