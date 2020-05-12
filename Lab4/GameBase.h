#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "CommonFunctions.h"

using namespace std;

enum resulProm { prompsuc, quitGame, invalidForm, invalidSquare };
enum finalResult { suc, playerX, playerO, draw, quit };

class GameBase {
	//friend ostream& operator<<(ostream& out, const TicTacToeGame& tic);
	//friend ostream& operator<<(ostream& out, const GomokuGame& go);
public:
	GameBase();
	GameBase(int width, int height, string piece1, string piece2, string play1, string play2);
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int prompt(unsigned int& x, unsigned int& y);
	virtual int turn() = 0;
	int play();
	static GameBase* check(int argc, char** argv);
	virtual void print() = 0;
protected:
	int width;
	int height;
	vector<string> playerX;//contains all the moves (coordinates) playerX has made
	vector<string> playerO;//contains all the moves (coordinates) playerY has made
	string piece1;
	string piece2;
	int maxlen;//will track the longest string len on all pieces on the board
	           //the longest string within playerX and playerO
	int boardSize;
	vector<string> gameBoard;
	void setmaxLen(vector<string> playerX, vector<string> playerO) {};
	string playerOne;
	string playerTwo;
};

