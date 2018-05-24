#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

std::vector<std::string> getDictionary(const std::string& strFileName)
{
	std::vector<std::string> vWordList;
	std::string strLine;
	std::ifstream fDictionary(strFileName);
	if(fDictionary.is_open())
	{
		while(getline(fDictionary, strLine))
		{
			vWordList.push_back(strLine);
		}
		fDictionary.close();		
	}
	return vWordList;
}

void displayWordList(std::vector<std::string>& vWordList)
{
	for (auto &s : vWordList)
	{
		std::cout << s << std::endl;
	}
}

void displayPuzzleString(std::string & puzzleString)
{
	std::cout << "     ";
	for(char &c: puzzleString)
	{	
		std::cout << c << " ";
	}
		
	std::cout << std::endl;
}

std::string pickWord(std::vector<std::string>& vWordList)
{
	std::string strWord{"default"};
	if(vWordList.size() > 0)
	{
		int nRandomIndex = std::rand() % vWordList.size();
		strWord = vWordList[nRandomIndex];
		vWordList.erase(vWordList.begin() + nRandomIndex);	
	}
	return strWord;
}

bool isInBoard(std::string& strBoard, const char c)
{
	int charIndex = strBoard.find(c);
	if(charIndex < 0) 
	{
		return false;
	}
	else 
	{
		strBoard.erase(strBoard.begin()+charIndex);
		return true;
	}
}

void displayBoard(std::string& strBoard)
{
	for(char& c : strBoard)
	{
		std::cout << "[" << c << "] ";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv)
{	
	srand(time(NULL));
	int nWins{0}, nLosses{0};	
	bool isGame = true;
		
	std::string strInput;
	std::vector<std::string> vWordList = getDictionary("dictionary.txt");		
	displayWordList(vWordList);		
	
	while(isGame)
	{
		//init
		bool isAlive = true,
		     isWin = false;
		int nLives = 6;
		std::string answerString = pickWord(vWordList);						
		std::string puzzleString{""};
		std::string strBoard = {"abcdefghijklmnopqrstuvwxyz"};
		for(char &c : answerString)
		{	
			puzzleString += '_';
		}
						
		while (isGame && isAlive && !isWin)
		{
			std::cout << std::string(100, '\n');
			std::cout << "Hangman! Current Lives: " << nLives << " | wins: "<< nWins << " | losses: " << nLosses << "\n\n";
			displayPuzzleString(puzzleString); //show puzzle				
			std::cout << std::endl;
			displayBoard(strBoard);
			
			std::cout <<"\nGuess a letter > ";
			std::cin >> strInput;
			if(strInput.size() == 1)
			{
				char cInput = std::tolower(strInput[0]);
				if(isInBoard(strBoard, cInput))
				{
					int ansIndex = answerString.find(cInput);
					if(ansIndex == std::string::npos) //wrong letter
					{
						nLives--;
						if(nLives < 1)
						{
							isAlive = false;
						}
					}
					else //right letter
					{						
						puzzleString[ansIndex] = answerString[ansIndex];
						
						for(int i=ansIndex+1; i<answerString.size(); i++) //find all same letters
						{
							if(answerString[i] == cInput)
							{
								puzzleString[i] = cInput;
							}
						}														
						
						if(puzzleString.find('_') == std::string::npos)
						{
							isWin = true;
						}
					}
				}
				else
				{					
					//no longer in board
				}
			}
			else
			{
				if(strInput == "quit" || strInput == "exit")
				{				
					isGame = false;
				}
				else 
				{
					std::cout << "invalid input!" << std::endl;
				}
			}
			
			if(isWin)
			{
				nWins++;
				std::cout << "\nCongratulations, you correctly guessed the word [" << answerString << "]!"<< std::endl;
				system("pause");
			}
			else if (!isAlive)
			{
				nLosses++;
				std::cout << "\nSorry, the correct word is [" << answerString << "]!" << std::endl;
				system("pause");
			}
		}		
	}
	
	return 0;
}
