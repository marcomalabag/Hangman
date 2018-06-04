#include "LChecker.h"

//override the function "checkMyLetter"
//create the function definition here
char Lchecker::checkMyLetter(char inputChar) {
	if(inputChar == 'L' || inputChar == 'l') {
		return 'l';
	}
	else {
		return '*';
	}
} 
