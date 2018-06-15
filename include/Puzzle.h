/********************************************************
* Puzzle class for Hangman's game functions
* includes initialization, display, and most game logic
* 
* Created by: Dennis Li (dennis.li@ubisoft.com)
********************************************************/

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Puzzle
{
private:
	int nWins, nLosses, nLives;
	bool _isGame, _isAlive, _isWin;
	std::vector<std::string> vWordList;
	std::string answerString, puzzleString, strBoard;
	std::string fileName = "scoreboard.txt";
	
public:
	bool initDictionary(const std::string& strFileName);	
	void displayBoard();
	std::string pickWord();
	bool isInBoard(const char c);
	int findInAnswer(const char c);	
	void openPuzzle(const int ansIndex);
	
	void initGame(const std::string& strDict);   //get puzzle from dictionary
	void initPuzzle(); 							//reset lives, get a new word
	void displayWordList();
	void displayPuzzleString();
	
	bool isWin() { return _isWin; }	
	bool isAlive() { return _isAlive; }
	bool isGame() { return _isGame; }
	
	std::string getAnswer() {return answerString; }
	int getWins() {return nWins; }
	int getLosses() {return nLosses; }
	int getLives() {return nLives; }
	
	void addWin() { nWins++; }
	void addLoss() { nLosses++; }
	void endGame() {  _isGame = false; }	

	void createScoreboard() {
		if (FILE *file = fopen(fileName.c_str(), "r")) {
			fclose(file);
		} else {
			std::ofstream scoreBoardFile("scoreboard.txt");

			if (!scoreBoardFile.is_open()) {
				std::cout << "Something went wrong with opening the file!";
				endGame();
			}
		}
	}
	void appendToScoreBoard(const std::string name, int nWins) {
		std::ofstream scoreBoardFile;

		scoreBoardFile.open(fileName, std::ios_base::app);
		scoreBoardFile << name << " " << nWins << "\n";
	}
	void displayScoreboard() {
		if (FILE *file = fopen(fileName.c_str(), "r")) {
			fclose(file);
		} else {
			std::cout << "Something went wrong with opening the file!";
		}
	}

	void loseLife();
		
	Puzzle();
	Puzzle(std::string strDict);
	~Puzzle();
};
