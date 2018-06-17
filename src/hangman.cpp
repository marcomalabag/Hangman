/********************************************************
* Main entry point for Hangman
* includes the game loop and the basic print info
* 
* Created by: Dennis Li (dennis.li@ubisoft.com)
********************************************************/

#include <time.h>
#include "Puzzle.h"
#include "LetterFunction.h"

int main(int argc, char** argv)
{	
	srand(time(NULL));
	Puzzle p("dictionary_many.txt");	
	std::string strInput;
	
	int hint=0; // hint on/off
	int numberOfHints=3; // number of hints left for the game
	
//	p.displayWordList();                      //uncomment to see the word list loaded for the game
	LetterFunction *lf = new LetterFunction();
	
	while(p.isGame())
	{		
		p.initPuzzle();
						
		while (p.isGame() && p.isAlive() && !p.isWin() )
		{
			std::cout << std::string(5, '\n');	
			std::cout << "Hangman! Current Lives: " << p.getLives() << " | wins: "<< p.getWins() << " | losses: " << p.getLosses() <<  " | hints: " << numberOfHints << "\n\n";
		
			p.displayPuzzleString();

			if(hint==0) //if hint is "off", display normal board
			{
				p.displayBoard();
			}	
				
			if(hint>=1) //if hint is on, display board with reduced letters
			{
				p.displayBoardHint();
			}
				
			std::cout <<"Guess a letter > ";
			std::cin >> strInput;
			
			if(strInput.size() == 1) //single char input
			{
				char cInput = lf->check(strInput[0]);
				
				if(p.isInBoard(cInput))
				{
					int ansIndex = p.findInAnswer(cInput);
					if(ansIndex == std::string::npos) //wrong letter
					{
						p.loseLife();
					}
					else //right letter
					{
						p.openPuzzle(ansIndex);
					}
				}
				else
				{
					p.loseLife();
					//no longer in board					
				}				
			}
			else //multi char input
			{
				if(strInput == "quit" || strInput == "exit")
				{				
					p.endGame();
				}
				
				else if(strInput == "hint") //toggle hint
				{
					hint=1;
					numberOfHints--; // decrease number of hints
				}	
									
				else 
				{
					std::cout << "invalid input!" << std::endl;
				}
			}
			
			if(p.isWin())
			{
				p.addWin();
				std::cout << "\nCongratulations, you correctly guessed the word [" << p.getAnswer() << "]!"<< std::endl;
				system("pause");
				hint = 0; //turn off hint for next word
			}
			else if (!p.isAlive())
			{
				p.addLoss();
				std::cout << "\nSorry, the correct word is [" << p.getAnswer() << "]!" << std::endl;
				system("pause");
				hint = 0; //turn off hint for next word
			}
		}			
	}	
	delete lf;
	
	return 0;
}
