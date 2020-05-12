#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "CommonFunctions.h"
#include "GameBase.h"

using namespace std;

class TicTacToeGame : public GameBase {
	friend ostream& operator<<(ostream& out, const TicTacToeGame& tic);
public:
	TicTacToeGame();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();
};

ostream& operator<<(ostream& out, const TicTacToeGame& tic);
