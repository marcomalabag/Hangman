#include "RChecker.h"

char RChecker::checkMyLetter(char inputChar) 
{
	if( inputChar == 'r' || inputChar == 'R')
	{		
		return 'r';
	}
	else
		return defaultLetter;
}
