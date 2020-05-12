#pragma once
#include <string>
using namespace std;

enum piece_color {red,black,white,blue,invalid_color,no_color};

string colortostring(piece_color cl);

piece_color stringtocolor(string clstring);

struct game_piece {
	game_piece();
	game_piece(piece_color cl, string piece_name, string piece_display);
	piece_color cl_;
	string piece_name_;
	string piece_display_;
};
