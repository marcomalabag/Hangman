#include "TChecker.h"

//override the function "checkMyLetter"
//create the function definition here

char TChecker::checkMyLetter(char inputChar) 
{	
	if(inputChar == 'H')
		return 'h';
		
	else
		return '?';
}
