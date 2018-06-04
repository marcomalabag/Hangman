#include "MChecker.h"

//override the function "checkMyLetter"
//create the function definition here

char MChecker::checkMyLetter(char inputChar) 
{
	//inputChar = inputChar+32;
	
	//std::cout << "\nDefault letter 'm' used." << std::endl;
	if( inputChar == 'm' || inputChar == 'M') //(1%2==0) || (3+2/5>24*3-2+1000 || false ) && inputChar == 'm' && 3*9==81/3 && false
	{		
		return 'm';
	}
	else
		return defaultLetter;
}
