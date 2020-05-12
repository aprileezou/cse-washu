#include "gameboard.h"

int readfiledim(ifstream& rfile, unsigned int& x, unsigned int& y) {
	string line;
	if (getline(rfile, line)) {
		istringstream iss(line);
		if (iss >> x && iss >> y) {
			return 0; //success
		}
		else {
			return 1; //could not extract number
		}
	}
	else {
		return 2; //could not get line
	}
}

int readfilepiece(ifstream& rfile, vector<game_piece>& pieces, unsigned int dimx, unsigned int dimy) {
	string line,clstring,piecename,piecedisplay;
	int x, y, index;
	int c = 0;
	game_piece temp;
	dimx = int(dimx);
	dimy = int(dimy);
	while (getline(rfile, line)) {
		istringstream iss(line);
		if (iss >> clstring && iss >> piecename
			&& iss >> piecedisplay && iss >> x && iss >> y) {
			//cout << clstring << endl;
			//cout << piecename << endl;
			//cout << stringtocolor(clstring) << endl;
			if (stringtocolor(clstring) != invalid_color && x < dimx && y < dimy) {
				index = dimx * y + x;
				//pieces[index].cl_ = stringtocolor(clstring);
				//pieces[index].piece_name_ = piecename;
				//pieces[index].piece_display_ = piecedisplay;
				temp.cl_ = stringtocolor(clstring);
				temp.piece_name_ = piecename;
				temp.piece_display_ = piecedisplay;
				pieces[index] = temp;
				c = c + 1;
			}
		}
	}

	if (c > 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int printoutpiece(const vector<game_piece>& pieces, unsigned int m, unsigned int n) {
	string line;
	int index;
	m = int(m);
	n = int(n);
	int size = m*n;
	if (size != pieces.size()) {
		return 1;
	}
	/*for (int i = m-1; i>=0 ; --i) {
		line = "";
		for (int j = 0; j < int(n); ++j) {
			index = m * j + i;
			if (pieces[index].piece_display_ != "") {
				line = line + pieces[index].piece_display_ + " ";
			}
			else {
				line = line + "  ";
			}
		}
		cout << line << endl;
	}*/

	for (int i = n - 1; i >= 0; --i) {
		line = "";
		for (int j = 0; j < m; ++j) {
			index = m * i + j;
			if (pieces[index].piece_display_ != "") {
				line = line + pieces[index].piece_display_ + " ";
			}
			else {
				line = line + "  ";
			}
		}
		cout << line << endl;
	}
	
	return 0;
}