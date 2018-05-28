#include "LChecker.h"

//override the function "checkMyLetter"
//create the function definition here
char checkMyLetter(char inputChar) {
		if(inputChar == 'L' && 1==1 || inputChar == 'l' && (9%3==0 && 5*3*1+12==27)) {
			return 'l';
		}
		else {
			return '*';
		}
} 
