#include "LetterChecker.h"
#include "BChecker.h"

char LetterChecker::toLower()
{	
	switch(myLetter)
	{
		case 'A': return 'a';
		case 'B': return BChecker();			
			break;
		default:
			return myLetter;
	}	
}

LetterChecker::LetterChecker() : myLetter{'#'}
{
}

LetterChecker::LetterChecker(char c) : myLetter{c}
{
	std::cout << "Letter Checker base constructed!\n";
}
