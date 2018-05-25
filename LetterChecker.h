#include <iostream>

class LetterChecker
{
public: 
	virtual char toLower();
	LetterChecker();
	LetterChecker(char c);	
protected:
	char myLetter;
};

