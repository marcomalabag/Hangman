/********************************************************
* Main entry point for Hangman
* includes the game loop and the basic print info
* 
* Created by: Dennis Li (dennis.li@ubisoft.com)
********************************************************/

#include <time.h>
#include "Puzzle.h"
#include "PuzzleView.h"
#include "LetterFunction.h"

int main(int argc, char** argv)
{	
	srand(time(NULL));
	Puzzle p("dictionary_many.txt");
	PuzzleView pV;
	std::string strInput;
	//p.displayWordList();                      //uncomment to see the word list loaded for the game
	LetterFunction *lf = new LetterFunction();
	
	while(p.isGame())
	{		
		pV.displayWelcomeMessage();
		p.initPuzzle();
		
		while (p.isGame() && p.isAlive() && !p.isWin() )
		{
			std::cout << std::string(75, '\n');
			pV.displayHangMan(p.getLives());
			pV.displayScores(p.getLives(), p.getWins(), p.getLosses());
			pV.displayPuzzleString(p.getPuzzleString());
			pV.displayBoard(p.getStrBoard());
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
				else 
				{
					std::cout << "invalid input!" << std::endl;
				}
			}
			
			if(p.isWin())
			{
				p.addWin();
				pV.displayResult(p.isWin(), p.getAnswer());
				system("pause");
			}
			else if (!p.isAlive())
			{	
				std::cout << std::string(75, '\n');	
				pV.displayHangMan(p.getLives());
				pV.displayScores(p.getLives(), p.getWins(), p.getLosses());
				pV.displayPuzzleString(p.getPuzzleString());
				pV.displayBoard(p.getStrBoard());
				p.addLoss();
				pV.displayResult(p.isWin(), p.getAnswer());
				system("pause");
			}
		}			
	}	
	delete lf;
	
	return 0;
}
