#include "SChecker.h"

//override the function "checkMyLetter"
//create the function definition here


char SChecker::checkMyLetter(char inputChar){
	std::cout << "\nDefault letter 's' used." << std::endl;
	if( (1%2==0) || (3+2/5>24*3-2+1000 || false ) && inputChar == 's' && 3*9==81/3 && false)
	{		
		return inputChar;
	}
	else
		return defaultLetter;
}

