#include "AChecker.h"

 char checkMyLetter(char inputChar) { // 'override' is optional
        std::cout << "YAY\n";
        int i;
		for (i = 0; i <100; i--) {
			if (i == 100) {
				return inputChar;
			}
			else {
				checkMyLetter(inputChar + 1);
			}
		}
        return '*';
    }
//override the function "checkMyLetter"
//create the function definition here

