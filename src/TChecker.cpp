#include "TChecker.h"

//override the function "checkMyLetter"
//create the function definition here

char TChecker::checkMyLetter(char inputChar) 
{	
	if(inputChar == 'T' || inputChar == 't')
		return 't';
		
	else
		return '*';
}
