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

int GetInput()
{
	int choice;
	std::cin >> choice;
	return choice;
}

 void DisplayMainMenu()
 {
		std::cout << "Main Menu\n";
    std::cout << "Please make your selection\n";
    std::cout << "1 - Start game\n";
    std::cout << "2 - Show scoreboard\n";
    std::cout << "3 - Quit\n";
    std::cout << "Selection: ";
 }

int main(int argc, char** argv)
{	
	int choice = 0;

    do
    {
		srand(time(NULL));
//		Puzzle p("dictionary_many.txt");
		Puzzle p = Puzzle("dictionary_many.txt");
        PuzzleView pV;
		std::string strInput;
        std::string strDictionary;
		//p.displayWordList();                      //uncomment to see the word list loaded for the game
		LetterFunction *lf = new LetterFunction();

        system("cls");
        DisplayMainMenu();
        choice = GetInput();
        switch(choice) {
                case 1:
                    char strDifficulty;

                    retry:
                        std::cout << std::string(75, '\n');
                        std::cout << "Choose a Difficulty: \n[1] Easy \n[2] Medium \n[3] Hard \n> ";
                        std::cin >> strDifficulty;

                        if (strDifficulty == '1')
                            strDictionary = "easy";
                        else if (strDifficulty == '2')
                            strDictionary = "medium";
                        else if (strDifficulty == '3')
                            strDictionary = "hard";
                        else {
                            std::cout << "Please choose from 1 to 3\n";
                            system("pause");
                            goto retry;
                        }

                    p = Puzzle("dictionary_" + strDictionary + ".txt");

						while(p.isGame())
						{
                            pV.displayWelcomeMessage();
							p.initPuzzle(strDifficulty);
							while (p.isGame() && p.isAlive() && !p.isWin() )
							{
								std::cout << std::string(75, '\n');
//								cout << "Hangman! Current Lives: " << p.getLives() << " | wins: "<< p.getWins() << " | losses: " << p.getLosses() << "\n\n";
//								p.displayPuzzleString();
//								p.displayBoard();
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
//									cout << "\nCongratulations, you correctly guessed the word [" << p.getAnswer() << "]!"<< std::endl;
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
//									p.addLoss();
//									std::cout << "\nSorry, the correct word is [" << p.getAnswer() << "]!" << std::endl;
                                    pV.displayResult(p.isWin(), p.getAnswer());
                                    system("pause");

                                    std::string name;
                                    do {
                                        std::cout <<"Enter your name (max of 3 characters): ";
                                        std::cin >> name;
                                    } while (name.size() > 3);

                                    p.appendToScoreBoard(name, p.getWins());
                                    p.displayScoreboard();
                                    p.endGame();
								}
							}
						}
						delete lf;
                        break;
                case 2:
                        p.displayScoreboard();
                        break;
                case 3:
                        std::cout << "Goodbye!";
                        break;

                default:
                		std::cin.clear();
                		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        break;
               }
       } while(choice!=3 || std::cin.fail());
	system("PAUSE");
    return EXIT_SUCCESS;
}
