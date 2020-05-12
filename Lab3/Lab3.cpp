// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab3.h"

TicTacToeGame::TicTacToeGame(int w, int h) {
	w_ = w;
	h_ = h;
	vector<string> boardgame;
	for (int i = 0; i < w * h; ++i) {
		boardgame.push_back(" ");
	}
	boardgame_ = boardgame;
	count_ = 0;
	playero_ = "Player O: ";
	playerx_ = "Player X: ";
}

ostream& operator<<(ostream& out, const TicTacToeGame& game) {
	int w = game.w_;
	int h = game.h_;
	vector<string> boardgame = game.boardgame_;
	int index;
	for (int i = h; i > 0; --i) {
		out << i - 1 << " ";
		for (int j = 0; j < w; ++j) {
			index = j + w * (i - 1);
			out << boardgame[index] << " ";
		}
		out << "\n";
	}
	out << " ";
	for (int j = 0; j < w; ++j) {
		out << " " << j;
	}

	return out;
}

bool TicTacToeGame::done() {
	int c = 0;
	int index = 0;

	//horizontal identical
	for (int i = 1; i < this->h_- 1; ++i) {
		c = 0;
		for (int j = 1; j < w_-2; ++j) {
			index = j + w_ * i;
			if (boardgame_[index]!= " " && boardgame_[index] == boardgame_[index + 1]) {
				c += 1;
			}
		}
		if (c == w_ - 3) {
			return true;
		}
	}
	
	//vertical identical
	for (int i = 1; i < w_ - 1; ++i) {
		c = 0;
		for (int j = 1; j < h_ - 2; ++j) {
			index = i + w_ * j;
			if (boardgame_[index] != " " && boardgame_[index] == boardgame_[index + w_]) {
				c += 1;
			}
		}
		if (c == h_ - 3) {
			return true;
		}
	}

	//diagonal identical +45
	c = 0;
	for (int i = 1; i < h_ - 2; ++i) {
		index = i + w_ * i;
		if (boardgame_[index] != " " && boardgame_[index] == boardgame_[index + 1 + w_]) {
			c += 1;
		}
	}
	if (c == h_ - 3) {
		return true;
	}

	//diagonal identical -45
	c = 0;
	for (int i = 1; i < h_ - 2; ++i) {
		index = i + w_ * (w_ - 1 - i);
		if (boardgame_[index] != " " && boardgame_[index] == boardgame_[index + 1 - w_]) {
			c += 1;
		}
	}
	if (c == h_ - 3) {
		return true;
	}

	return false;
}

bool TicTacToeGame::draw() {
	if (this->done() == true || this->count_ != 9) {
		return false;
	}

	return true;
}

int TicTacToeGame::prompt(unsigned int& x, unsigned int& y) {

	string order;
	cout << "Please input the position coordinate or 'quit':";
	cin >> order;

	if (order == "quit") {
		return 1; //user asked to quit
	}

	replace(order.begin(), order.end(), ',', ' ');
	istringstream isorder(order);
	if (isorder >> x && isorder >> y) {
		int index = x + this->w_ * y;
		if (x > 0 && x < this->w_ - 1 && y>0 && y < this->h_ - 1 
			&& this->boardgame_[index] == " ") {
			return 0;
		}
	}

	return this->prompt(x,y);

	/*x = int(x);
	y = int(y);
	int index = x + this->w_ * y;
	while (x > this->w_ - 2 || x < 1 || y < 1 || y > this->h_ - 2
		|| this->boardgame_[index] != " ") {

		string order;
		cout << "Please input the position coordinate or 'quit':";
		cin >> order;

		if (order == "quit") {
			return 1; //user asked to quit
		}

		//if the string has no comma???
		replace(order.begin(), order.end(), ',', ' '); 
		istringstream isorder(order);
		//if the extraction fails???
		isorder >> x;
		isorder >> y;
	}
	return 0;*/ //success
}

int TicTacToeGame::turn() {
	unsigned int tempx = 0;
	unsigned int tempy = 0;
	unsigned int& x = tempx;
	unsigned int& y = tempy;
	if (this->prompt(x, y) == 1) {
		return 1; //user choose to quit
	}
	x = int(x);
	y = int(y);
	this->count_ += 1;
	int index = x + y * this->w_;

	if (this->count_ % 2 == 0) {
		this->boardgame_[index] = "O";
		if (this->count_ == 2) {
			this->playero_ = this->playero_+ to_string(x) + "," + to_string(y);
		}
		else {
			this->playero_ = this->playero_ + ";" + to_string(x) + "," + to_string(y);
		}
		cout << *this << "\n\n" << this->playero_ << endl;
	}
	else {
		this->boardgame_[index] = "X";
		if (this->count_ == 1) {
			this->playerx_ = this->playerx_ + to_string(x) + "," + to_string(y);
		}
		else {
			this->playerx_ = this->playerx_ + ";" + to_string(x) + "," + to_string(y);
		}
		cout << *this << "\n\n" << this->playerx_ << endl;
	}

	return 0; //success
}

int TicTacToeGame::play() {
	//while(true){
		if (this->turn() == 1) {
			cout << this->count_ << " turns were played. The user quit." << endl;
			return 2; //user quit
		}
		if (this->done()) {
			if (this->count_ % 2 == 0) {
				cout << "Player O wins the game." << endl;
			}
			else {
				cout << "Player X wins the game." << endl;
			}
			return 0; //success
		}
		if (this->draw()) {
			cout << this->count_ << " turns were played. There are no winning moves remain." << endl;
			return 1; //draw
		}
		return this->play();
	//}
}

int usage_message(char* c) {
	cout << "usage:lab3<" << c << ">: The command line should be only 'TicTacToe'." << endl;
	return 3; //wrong argument number/statment
}

int main(int argc, char *argv[])
{
	if (argc != 2 || strcmp(argv[1],"TicTacToe") != 0) {
		return usage_message(argv[0]);
	}

	TicTacToeGame& game = TicTacToeGame(5, 5);
	return game.play();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
