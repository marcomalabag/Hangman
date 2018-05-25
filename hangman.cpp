#include <time.h>
#include "puzzle.h"

int main(int argc, char** argv)
{	
	srand(time(NULL));
	Puzzle p("dictionary.txt");	
	std::string strInput;
	p.displayWordList();	
	
	while(p.isGame())
	{		
		p.initPuzzle();
						
		while (p.isGame() && p.isAlive() && !p.isWin() )
		{
			std::cout << std::string(100, '\n');			
			std::cout << "Hangman! Current Lives: " << p.getLives() << " | wins: "<< p.getWins() << " | losses: " << p.getLosses() << "\n\n";
			p.displayPuzzleString();			
			p.displayBoard();
			std::cout <<"Guess a letter > ";
			std::cin >> strInput;
			
			if(strInput.size() == 1)
			{
				LetterChecker* lc;				
				lc = new LetterChecker(strInput[0]);
				//char cInput = std::tolower(strInput[0]);
				
				char cInput = lc->toLower();
				
				//char cInput = LetterChecker::checkLetter(strInput[0], aChecker);
				
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
					//no longer in board
				}
				delete lc;
			}
			else
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
				std::cout << "\nCongratulations, you correctly guessed the word [" << p.getAnswer() << "]!"<< std::endl;
				system("pause");
			}
			else if (!p.isAlive())
			{
				p.addWin();
				std::cout << "\nSorry, the correct word is [" << p.getAnswer() << "]!" << std::endl;
				system("pause");
			}
		}			
	}	
	return 0;
}
