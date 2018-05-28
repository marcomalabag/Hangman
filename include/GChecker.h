#include "LetterChecker.h"
#include <iostream>

class GChecker : public LetterChecker
{	
	//override the function "checkMyLetter"	
	public:
		char checkMyLetter(char inputChar) override;
	//create the function declaration here
};
