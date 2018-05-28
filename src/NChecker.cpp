#include "NChecker.h"
#include <iostream>
using namespace std;
//override the function "checkMyLetter"
//create the function definition here
 
 char NChecker::nchecker(char inputChar){
 
 if (inputChar == 'N' || inputChar == 'n')
 {
     return 'N';
 }
 else
   return '*';
}

//sets defaultLetter to '*'

