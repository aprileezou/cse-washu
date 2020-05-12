#include "commonFunctions.h"
#include "TicTacToeGame.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <algorithm>

int parseFile(vector<string>& v, char* c) {
	ifstream in(c);

	if (in.is_open()) {
		string line, word;
		cout << "the stream is open " << endl;
		int empty = 0;
		while (getline(in, line)) {
			empty = empty + 1;
			istringstream l(line);
			while (l >> word) {
				//look into using getline and >> operator with a while loop here
				v.push_back(word);
			}
		}
		if (empty == 0) {
			cout << "The file is empty." << endl;
			return inputfileempty;
		}
		return success;
	}
	else {
		cout << "cannot open file " + *c << endl;
		return unabletoopenfile;
	}
}

/*This function is to tell user the correct way to run the program when they give the wrong inputs*/
int usemsg(int argc, char** argv) {
	if (argc == 2) {
		string s1 = argv[programname];
		cout << "If you want to play TicTacToe in the default way, please enter " << s1 << " TicTacToe" << endl;
		cout << "If you want to play Gomoku in the default way, please enter " << s1 << " Gomoku" << endl;
		return game::wrongGameName;
	}
	else if (argc == 3) {
		string s1 = argv[programname];
		string s2 = argv[gamename];
		istringstream iss(argv[boardwidth]);
		int is2;
		iss >> is2;
		if (s2 != "TicTacToe" && s2 != "Gomoku") {
			cout << "If you want to play TicTacToe in the default way, please enter " << s1 << " TicTacToe" << endl;
			cout << "If you want to play Gomoku in the customized way, please enter " << s1 << " Gomoku x" << endl;
			cout << "x is the widht/height of gameboard, should be equal to or greater than 3." << endl;
			return game::wrongGameName;
		}
		else if (is2 <= 0) {
			cerr << "Width or height of a board could not be less than 0." << endl;
			return game::negativeSizeBoard;
		}
		else {
			cerr << "Board is too small." << endl;
			return game::boradtoSmall;
		}
	}
	else if (argc == 4) {
		string s1 = argv[programname];
		string s2 = argv[gamename];
		istringstream iss(argv[boardwidth]);
		istringstream iss3(argv[winNumber]);
		int is2,is3;
		iss >> is2;
		iss3 >> is3;
		if (s2 != "TicTacToe" && s2 != "Gomoku") {
			cout << "If you want to play TicTacToe in the default way, please enter " << s1 << " TicTacToe" << endl;
			cout << "If you want to play Gomoku in the customized way, please enter " << s1 << " Gomoku x y" << endl;
			cout << "x and y should both be equal or greater than 3, which is width/height of gameboard. x: width/height of gameboard. y: number of pieces in a row to win." << endl;
			return game::wrongGameName;
		}
		else if (is2 <= 0 || is3 <= 0) {
			cerr << "Width or height of a board could not be less than 0." << endl;
			cerr << "Number of connecting pieces to win could not be less than 0 either." << endl;
			return game::negativeWinNumber;
		}
		else {
			cerr << "Board is too small or number of connecting pieces to win is too small." << endl;
			return game::boradtoSmall;
		}
	}
	else {
		cerr << "Wrong number of arguments. Number of arguments should only be 2, 3 or 4, including program name." << endl;
		return sucfa::wrongnumofarguments;
	}
}

/*This function is to make all the characters of a string to become lower case if there was any capital letter before*/
void lowerCase(string& s) {
	int ascii_code_of_A = 65;
	int ascii_code_of_Z = 90;
	int diff_bw_A_and_a = 32;
	int l = (int)s.size();
	for (int i = 0; i < l; ++i) {
		int h = int(s.at(i));
		if (h >= ascii_code_of_A && h <= ascii_code_of_Z) {
			s.at(i) = char(h + diff_bw_A_and_a);
		}
	}
}