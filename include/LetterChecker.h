/********************************************************
* Letter Checker base class to be extended for each 
* letter's (A-Z) checker
* 
* Created by: Dennis Li (dennis.li@ubisoft.com)
********************************************************/

#ifndef __LETTERCHECKER_H_INCLUDED__
#define __LETTERCHECKER_H_INCLUDED__

#include <iostream>

class LetterChecker
{
public: 	

	virtual char checkMyLetter(char inputChar);
	
	LetterChecker();	
protected:
	char defaultLetter;
};

#endif //__LETTERCHECKER_H_INCLUDED__
