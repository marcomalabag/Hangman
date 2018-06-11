#include "BChecker.h"

//override the function "checkMyLetter"
//create the function definition here

char BChecker::checkMyLetter(char inputChar) {
	if(inputChar == 'b'||inputChar == 'B')
	{		
		return 'b';
	}
	else
		return defaultLetter;

}
