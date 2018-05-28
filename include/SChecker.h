#include "LetterChecker.h"

class SChecker : public LetterChecker
{	
	//override the function "checkMyLetter"	
	//create the function declaration here
	public: 
		virtual char checkMyLetter(char inputChar);
		SChecker();
		
	protected:
		char defaultLetter;
};

