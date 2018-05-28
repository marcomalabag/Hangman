#include "QChecker.h"

//override the function "checkMyLetter"
//create the function definition here

char QChecker::checkMyLetter(char inputChar){
	
		if(inputChar=='q'||inputChar=='Q'){
			return 'q';
		}
		else
			return defaultLetter;
}
