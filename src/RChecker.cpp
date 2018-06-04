#include "RChecker.h"
//override the function "checkMyLetter"
//create the function definition here
char RChecker::checkMyLetter(char inputChar) 
{
	//std::cout << "\nDefault letter '*' used." << std::endl;
	if( inputChar == 'r' || inputChar == 'R')//(1%2==0) || (3+2/5>24*3-2+1000 || false ) && inputChar == defaultLetter && 3*9==81/3 && false)
	{		
		return 'r';
	}
	else
		return defaultLetter;
}

//sets defaultLetter to '*'
RChecker::RChecker() : defaultLetter{'*'}
{	
}
