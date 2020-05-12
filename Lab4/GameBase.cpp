#include "GameBase.h"
#include "TicTacToeGame.h"
#include "GomokuGame.h"
#include "GomokuGame.h"
#include <algorithm>

using namespace std;

GameBase::GameBase() :maxlen(0), width(0), height(0), boardSize(width* height),piece1(" "), piece2(" "), playerOne(" "), playerTwo(" ") {
}

GameBase::GameBase(int w, int h, string p1, string p2, string play1, string play2)
	: width(w), height(h), boardSize(width* height), piece1(p1), piece2(p2), maxlen(0), playerOne(play1), playerTwo(play2) {
	//in the body of this contructor, we make sure that maxlen stores the lenght of the longest string of the game
	int tem = max((int)piece1.size(), (int)piece2.size());
	int maxdigit = width - 1;
	string ww = to_string(maxdigit);
	int wws = (int)ww.size();
	maxlen = max(wws, tem);
}

/*This function is used for players to promt the coordinates where they want to put their piece.*/
int GameBase::prompt(unsigned int& x, unsigned int& y) {
	string s;//used to get the coordinates.
	cout << "please enter quit to end the game or coordinates to indicate the square where you want to place your piece." << endl;
	cin >> s;
	if (s == "quit") {
		return resulProm::quitGame;
	}
	else {
		int countComma = 0;//number of commas in the input coordinates string
		for (unsigned int i = 0; i < s.size(); ++i) {
			if (s[i] == ',') {
				s[i] = ' ';
				countComma++;
			}
		}
		if (countComma == 1) {
			//if countComma is 1, then it is highly likely that the form is valid
			istringstream iss(s);
			iss >> x;
			iss >> y;
			int xx = int(x);
			int yy = int(y);
			if (xx > width-2 || yy > width-2 || xx < 1 || yy < 1) {
				cout << "Invalid Square, the range of coordinates is only between 1,1 to 3,3, please enter again:" << endl;
				return prompt(x, y);
			}
			else {
				return resulProm::prompsuc;
			}
		}
		else {
			cout << "Badly formed coordinates, the form of the correct coordinates should be x,y, please enter again:" << endl;
			return prompt(x, y);
		}
	}
}

/*This function is used to maitain the whole process during the game.*/
int GameBase::play() {
	int resultofTurn = turn();
	print();
	bool resultofDone = done();
	bool resultofDraw = draw();
	if (resultofTurn == finalResult::quit) {//If playerX at first decides to quit before make any move, it should hit this if statement.
		cout << "There are 0 turns been made, "<<playerOne<<" decided to quit." << endl;
		return finalResult::quit;
	}

	int count = 1;//keep track of how many turns has already been made.
	while ((resultofTurn != finalResult::quit) && (resultofDone != true) && (resultofDraw != true)) {
		resultofTurn = turn();
		print();
		resultofDone = done();
		resultofDraw = draw();
		if (resultofTurn == resulProm::prompsuc) {
			count++;
		}
	}
	if (resultofTurn == finalResult::quit) {
		if (count % 2 == 1) {
			if (count == 1) {//Indicate afer playerX made one move, palyerO decides to quit, hence onely one succussful move make, should use 
							 //turn instead of turns.
				cout << "There are " << count << " turn have been made, but "<<playerTwo<<" decided to quit." << endl;
			}
			else {
				cout << "There are " << count << " turns have been made, but "<<playerTwo<<" decided to quit." << endl;
			}
		}
		else {
			cout << "There are " << count << " turns have been made, but "<<playerOne<<" decided to quit." << endl;
		}
		return finalResult::quit;
	}
	else if (resultofDone == true) {
		if (count % 2 == 1) {
			cout << "There are " << count << " turns have been made, and "<<playerOne<<" wins." << endl;
		}
		else {
			cout << "There are " << count << " turns have been made, but "<<playerTwo<<" wins." << endl;
		}
		return finalResult::suc;
	}
	else {
		cout << "There are " << count << " turns have been made, but no one wins. It is a draw." << endl;
		return finalResult::draw;
	}
};

/*Check if the input arguments are valid to initialize a valid pointer*/
GameBase* GameBase::check(int argc, char** argv) {
	GameBase* ab = nullptr;
	if (argc == 2) {
		string s = argv[1];
		if (s == "TicTacToe") {
			ab = new TicTacToeGame();
		}
		else if (s == "Gomoku") {
			ab = new GomokuGame();
		}
	}
	else if (argc == 3) {
		string s1 = argv[1];
		string s2 = argv[2];
		istringstream iss(s2);
		int is2;
		iss >> is2;
		if (s1 == "Gomoku" && is2 >= 3&&is2<5) {
			//if the last input int is equal to or greater than 3 but less than 3, 
			//then we make the number of connecting pieces to win equals the length of one size of board
			ab = new GomokuGame(is2, is2,is2);
		}
		else if (s1 == "Gomoku" && is2 >= 5) {
			//if the last input int is equal to or greater than 5, then we use the default number of connecting
			//pieces to win, whihc is 5
			ab = new GomokuGame(is2, is2, 5);
		}
	}
	else if (argc == 4) {
		string s1 = argv[1];
		string s2 = argv[2];
		string s3 = argv[3];
		istringstream iss2(s2);
		istringstream iss3(s3);
		int is2, is3;
		iss2 >> is2;
		iss3 >> is3;
		if (s1 == "Gomoku" && is2 >= 3 && is3 >= 3&&is2>=is3) {
			//if both the additional input ints are equal to or greater than 3, then we use the user determined number to 
			//set our board and the number of connecting pieces to win.
			ab = new GomokuGame(is2, is2, is3);
		}
	}
	//if something wrong with the input arguments, which means that there any of the if statements above did not satisfied, then we
	//would return a singular pointer, oherwise a pointer to GameBase but initialized with TicTacToeGame or GomokuGame
	return ab;
}








