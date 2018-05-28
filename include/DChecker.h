#include "LetterChecker.h"


class DChecker : public LetterChecker
{
	//override the function "checkMyLetter"	
	//create the function declaration here
	
	public: 
		virtual char checkMyLetter(char inputChar);
		
		DChecker();
	protected:
		char defaultLetter;
	
};
