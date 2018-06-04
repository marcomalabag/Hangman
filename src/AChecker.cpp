#include "AChecker.h"

//override the function "checkMyLetter"
//create the function definition here

//always returns defaultLetter :P
char AChecker::checkMyLetter(char inputChar) {
	
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if(inputChar == 'a' || inputChar == 'A')	{	
		return 'a';
	}
	else
		return '*';
}

