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

class GomokuGame :public GameBase {
	friend ostream& operator<<(ostream& out, const GomokuGame& go);
public:
	GomokuGame();
	GomokuGame(int w, int h, int winN);
	virtual void print();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual int prompt(unsigned int& x, unsigned int& y);
private:
	int winNum;
};

ostream& operator<<(ostream& out, const GomokuGame& go);