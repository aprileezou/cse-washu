#pragma once
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

class TicTacToeGame{
	friend ostream& operator<<(ostream& out, const TicTacToeGame& game);
	public:
		TicTacToeGame(int w, int h);
		bool done();
		bool draw();
		int prompt(unsigned int&, unsigned int&);
		int turn();
		int play();
	private:
		int w_;
		int h_;
		vector<string> boardgame_;
		int count_;
		string playero_;
		string playerx_;
};

ostream& operator<<(ostream& out, const TicTacToeGame& game);

int usage_message(char* c);