#include "LChecker.h"

//override the function "checkMyLetter"
//create the function definition here
char LChecker::checkMyLetter(char inputChar) {
	if(inputChar == 'L' || inputChar == 'l') {
		return 'l';
	}
	else {
		return '*';
	}
} 
