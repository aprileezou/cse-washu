#include "TicTacToeGame.h"

/*Set teh default game board*/
TicTacToeGame::TicTacToeGame()
	:GameBase(5,5,"X","O", "playerX", "playerO"){
	string ini = "";
	for (int i = 0; i < maxlen; ++i) {
		ini = ini + " ";
	}
	for (int i = 0; i < boardSize; ++i) {
		gameBoard.push_back(ini);
	}
	print();
}

/*This function is used to detect whether there is a completion of winning*/
bool TicTacToeGame::done() {
	//below is horizontal
	for (int j = 1; j <= 3; ++j) {
		int countX = 0;
		int countO = 0;
		for (int i = 1; i <= 3; ++i) {
			int index = width * j + i;
			if (gameBoard[index] == "X") {
				countX++;
			}
			else if (gameBoard[index] == "O") {
				countO++;
			}
		}
		if (countX == 3 || countO == 3) {
			return true;
		}
	}
	//below is vertical
	for (int i = 1; i <= 3; ++i) {
		int countX = 0;
		int countO = 0;
		for (int j = 1; j <= 3; ++j) {
			int index = width * j + i;
			if (gameBoard[index] == "X") {
				countX++;
			}
			else if (gameBoard[index] == "O") {
				countO++;
			}
		}
		if (countX == 3 || countO == 3) {
			return true;
		}
	}
	//below is diagonal
	// situation 1: from lower left to upper right
	int index1 = width * 1 + 1;
	int index2 = width * 2 + 2;
	int index3 = width * 3 + 3;
	if (gameBoard[index1] == piece1 && gameBoard[index2] == piece1 && gameBoard[index3] == piece1) {
		return true;
	}
	else if (gameBoard[index1] == piece2 && gameBoard[index2] == piece2 && gameBoard[index3] == piece2) {
		return true;
	}

	// situation 2: from uppoer left to lower right
	index1 = width * 3 + 1;
	index2 = width * 2 + 2;
	index3 = width * 1 + 3;
	if (gameBoard[index1] == piece1 && gameBoard[index2] == piece1 && gameBoard[index3] == piece1) {
		return true;
	}
	else if (gameBoard[index1] == piece2 && gameBoard[index2] == piece2 && gameBoard[index3] == piece2) {
		return true;
	}
	// if nothing above mathces, then should return false
	return false;
};

/*This function is used to detect if the game would end up in a draw. It would also detec if there is no winning move.*/
bool TicTacToeGame::draw() {
	bool winorlose = done();//check if there is already a winner
	int remain = 0;
	vector<int> remainpositions;//contains how many empty positions still on board
	for (int j = 1; j <= 3; ++j) {
		for (int i = 1; i <= 3; ++i) {
			int index = width * j + i;
			if (gameBoard[index] == " ") {
				remainpositions.push_back(index);
				remain++;
			}
		}
	}

	if (winorlose == false || remain > 0) {
		if (remain == 1) {//when the result would be draw, even if the last player make the move, the result would not change. This part of code 
						  //would give the result one step ealier
			int last = remainpositions[0];
			gameBoard[last] = piece1;
			bool resultofDone = done();
			gameBoard[last] = " ";
			if (resultofDone != true) {
				return true;
			}
			else {
				gameBoard[last] = piece2;
				resultofDone = done();
				gameBoard[last] = " ";
				if (resultofDone != true) {
					return true;
				}
			}
		}
		return false;
	}
	else {
		return true;
	}
}

/*This function is used to keep track the current turn belongs to which player.*/
int TicTacToeGame::turn() {
	//In my design, playerX should be the first one to make move, and playerO should be the second one to make move
	//Therefore, if playerX and playerO have made same number of moves, the next turn should be playerX's. Otherwise,
	//playerO should move.
	if (playerX.size() == playerO.size()) {
		//string piece = "X";
		unsigned int x, y;
		cout << "PlayerX's turn, ";
		int promptResult = prompt(x, y);
		if (promptResult == resulProm::quitGame) {
			return finalResult::quit;
		}
		x = int(x);
		y = int(y);
		int index = width * y + x;
		if (gameBoard[index] == " ") {
			gameBoard[index] = piece1;
			string coordinates = to_string(x) + "," + to_string(y);
			playerX.push_back(coordinates);
			//cout << *this;
			cout << " PlayerX: ";
			for (unsigned int i = 0; i < playerX.size(); ++i) {
				if (i == playerX.size() - 1) {
					cout << playerX[i] << endl;
				}
				else {
					cout << playerX[i] << "; ";
				}
			}
		}
		else {
			cout << "This position has already be taken, please enter again:" << endl;
			return turn();
		}
	}
	else if (playerX.size() > playerO.size()) {
		//string piece = "O";
		unsigned int x, y;
		cout << "PlayerO's turn, ";
		int promptResult = prompt(x, y);
		if (promptResult == resulProm::quitGame) {
			return finalResult::quit;
		}
		x = int(x);
		y = int(y);
		int index = width * y + x;
		if (gameBoard[index] == " ") {
			gameBoard[index] = piece2;
			string coordinates = to_string(x) + "," + to_string(y);
			playerO.push_back(coordinates);
			//cout << *this;
			cout << " PlayerO: ";
			for (unsigned int i = 0; i < playerO.size(); ++i) {
				if (i == playerO.size() - 1) {
					cout << playerO[i] << endl;
				}
				else {
					cout << playerO[i] << "; ";
				}
			}
		}
		else {
			cout << "This position has already be taken, please enter again:" << endl;
			return turn();
		}
	}
	return resulProm::prompsuc;
}

void TicTacToeGame::print() {
	cout << *this;
}

ostream& operator<<(ostream& out, const TicTacToeGame& tic) {
	int count = tic.width-1;
	for (int j = tic.height - 1; j >= 0; --j) {
		for (int i = 0; i < tic.width; ++i) {
			int index = tic.width * j + i;
			string temp = tic.gameBoard[index];
			while (temp.size() < tic.maxlen) {
				temp = temp + " ";
			}
			if (i == 0) {
				out << count << " " << temp<<" ";
				count--;
			}
			else if (i == 4) {
				out << temp << endl;
			}
			else {
				out << temp << " ";
			}
		}
	}
	for (int i = 0; i < tic.width; ++i) {
		if (i == 0) {
			out << "  " << i<<" ";
		}
		if (i == tic.width - 1) {
			out << i << endl;
		}
		else {
			out << i << " ";
		}
	}
	return out;
}