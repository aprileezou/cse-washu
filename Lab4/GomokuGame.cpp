#include "GomokuGame.h"

GomokuGame::GomokuGame()
	:GameBase(19,19,"B","W","Black Stone", "White Stone"), winNum(5){
	string ini = "";
	while (ini.size() < maxlen) {
		//such code makes sure that every sring we input to gameBoard has the same length as of
		//the longest string on gameBoard
		ini = ini + " ";
	}
	for (int i = 0; i < boardSize; ++i) {
		gameBoard.push_back(ini);
	}
	print();
}

GomokuGame::GomokuGame(int w, int h, int winN) 
	: GameBase(w, h, "B", "W", "Black Stone", "White Stone"), winNum(winN){
	string ini = "";
	while (ini.size() < maxlen) {
		//such code makes sure that every sring we input to gameBoard has the same length as of
		//the longest string on gameBoard
		ini = ini + " ";
	}
	for (int i = 0; i < boardSize; ++i) {
		gameBoard.push_back(ini);
	}
	print();
}

/*This function is used to detect whether there is a completion of winning*/
bool GomokuGame::done() {
	bool result = false;
	//check horizontally
	for (int j = 0; j < height; ++j) {
		for (int i = 0; i < width - winNum+1; ++i) {
			int countBlack = 0;
			int countWhite = 0;
			for (int k = 0; k < winNum; ++k) {
				int index = width * j + i + k;
				if (gameBoard[index] == piece1) {
					countBlack++;
				}
				else if (gameBoard[index] == piece2) {
					countWhite++;
				}
			}
			if (countBlack == winNum) {
				return true;
			}
			else if (countWhite == winNum) {
				return true;
			}
		}
	}

	//check vertically
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height-winNum+1; ++j) {
			int countBlack = 0;
			int countWhite = 0;
			for (int k = 0; k < winNum; ++k) {
				int index = width * (j + k) + i;
				if (gameBoard[index] == piece1) {
					countBlack++;
				}
				else if (gameBoard[index] == piece2) {
					countWhite++;
				}
			}
			if (countBlack == winNum) {
				return true;
			}
			else if (countWhite == winNum) {
				return true;
			}
		}
	}

	//check dianogally
	//start from top left to lower right
	for (int k = height - 1; k >= winNum-1; --k) {
		for (int j = k; j >= winNum-1; --j) {
			int i = width - 1 - j;
			int countBlack = 0;
			int countWhite = 0;
			for (int k = 0; k < winNum; ++k) {
				int index = width * (j - k) + (i + k);
				if (gameBoard[index] == piece1) {
					countBlack++;
				}
				else if (gameBoard[index] == piece2) {
					countWhite++;
				}
			}
			if (countBlack == winNum) {
				return true;
			}
			else if (countWhite == winNum) {
				return true;
			}
		}
		
	}

	//start from lower left to top right
	for (int k = 0; k <= height-winNum; ++k) {
		for (int j = k; j <= height-winNum; ++j) {
			int i = j;
			int countBlack = 0;
			int countWhite = 0;
			for (int k = 0; k < winNum; ++k) {
				int index = width * (j + k) + (i + k);
				if (gameBoard[index] == piece1) {
					countBlack++;
				}
				else if (gameBoard[index] == piece2) {
					countWhite++;
				}
			}
			if (countBlack == winNum) {
				return true;
			}
			else if (countWhite == winNum) {
				return true;
			}
		}
	}

	return result;
}

/*This function is used to detect if the game would end up in a draw. It would also detec if there is no winning move.*/
bool GomokuGame::draw() {
	bool result = false;
	bool winorlose = done();//check if there is already a winner
	vector<string> temp = gameBoard;
	int remain = 0;
	if (winorlose == false) {
		//test if there is still possibility for Black Stone to win
		for (int j = 0; j < height; ++j) {
			for (int i = 0; i < width; ++i) {
				int index = width * j + i;
				if (gameBoard[index] != piece1 && gameBoard[index] != piece2) {
					gameBoard[index] = piece1;
					remain++;
				}
			}
		}
		bool resultofDone = done();
		gameBoard = temp;
		if (resultofDone==false) {//this suggests that there is no possibility for piece1(Black Stone) to win
			remain = 0;
			for (int j = 0; j < height; ++j) {
				for (int i = 0; i < width; ++i) {
					int index = width * j + i;
					if (gameBoard[index] != piece1 && gameBoard[index] != piece2) {
						gameBoard[index] = piece2;
						remain++;
					}
				}
			}
			resultofDone = done();
			gameBoard = temp;
			if (resultofDone == false) {//this suggests that there is no possibility for piece2(White Stone) to win either
				result = true;
			}
			else if (resultofDone == true && remain < 2) {
				//This means that there is only blank square left, if White Stone can fill that square, it would win. But unfortunately,
			    //next move and the only move left is of Black Stone's.
				if (playerX.size() == playerO.size()) {
					result = true;
				}
			}
		}
		else if (resultofDone==true&&remain < 2) {
			//This means that there is only blank square left, if Black Stone can fill that square, it would win. But unfortunately,
			//next move and the only move left is of White Stone's.
			if (playerX.size() > playerO.size()) {
				result = true;
			}
		}
	}
	return result;
}

/*This function is used for players to promt the coordinates where they want to put their piece.*/
int GomokuGame::turn() {
	int result = resulProm::prompsuc;
		if (playerX.size() == playerO.size()) {//Black Stone goes next move
			unsigned int x = 0;
			unsigned int y = 0;
			cout << "Black Stone's turn: " << endl;
			int promptResult = prompt(x, y);
			if (promptResult == resulProm::quitGame) {
				result=finalResult::quit;
			}
			else {
				x = (int)x;
				y = (int)y;
				int index = width * y + x;
				if (gameBoard[index] != piece1 && gameBoard[index] != piece2) {
					gameBoard[index] = piece1;
					string coordinates = to_string(x) + "," + to_string(y);
					playerX.push_back(coordinates);
					//if need to print out the total moves Black Stone has made, could add similar codes as in lab3 below
				}
				else {
					cout << "This position has already be taken, please enter again:" << endl;
					return turn();
				}
			}
		}
		else {//White Stone goes next move
			unsigned int x = 0;
			unsigned int y = 0;
			cout << "White Stone's turn: " << endl;
			int promptResult = prompt(x, y);
			if (promptResult == resulProm::quitGame) {
				result = finalResult::quit;
			}
			else {
				x = (int)x;
				y = (int)y;
				int index = width * y + x;
				if (gameBoard[index] != piece1 && gameBoard[index] != piece2) {
					gameBoard[index] = piece2;
					string coordinates = to_string(x) + "," + to_string(y);
					playerO.push_back(coordinates);
					//if need to print out the total moves Black Stone has made, could add similar codes as in lab3 below
				}
				else {
					cout << "This position has already be taken, please enter again:" << endl;
					return turn();
				}
			}
		}
	return result;
}

void GomokuGame::print() {
	cout << *this;
}

int GomokuGame::prompt(unsigned int& x, unsigned int& y) {
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
			if (xx > (width - 1) || yy > (width - 1) || xx < 0 || yy < 0) {
				cout << "Invalid Square, the range of coordinates is only between 0,0 to "<< width-1<<","<<height-1<<", please enter again:" << endl;
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

ostream& operator<<(ostream& out, const GomokuGame& go) {
	int count = go.width - 1;
	for (int j = go.height - 1; j >= 0; --j) {
		for (int i = 0; i < go.width; ++i) {
			int index = go.width * j + i;
			string temp = go.gameBoard[index];
			while (temp.size() < go.maxlen) {
				//such code makes sure that every sring we input to gameBoard has the same length as of
				//the longest string on gameBoard
				temp = temp + " ";
			}
			string c = to_string(count);
			while (c.size() < go.maxlen) {
				c = c + " ";
			}
			if (i == 0) {
				out << c << " " << temp << " ";
				count--;
			}
			else if (i == go.width-1) {
				out << temp << endl;
			}
			else {
				out << temp << " ";
			}
		}
	}
	for (int i = 0; i < go.width; ++i) {
		string ss = to_string(i);
		while (ss.size() < go.maxlen) {
			ss = ss + " ";
		}
		if (i == 0) {
			string f = "X";
			while (f.size() < go.maxlen) {
				f = f + " ";
			}
			out << f<<" "<< ss << " ";
		}
		else if (i == go.width - 1) {
			out << ss << endl;
		}
		else {
			out << ss << " ";
		}
	}
	return out;
};