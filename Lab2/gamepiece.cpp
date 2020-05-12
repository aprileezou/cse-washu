#include "gamepiece.h"
#include "otherfunctions.h"
#include <sstream>

using namespace std;

string colortostring(piece_color cl) {
	string converted;
	if (cl == red) {
		converted = "red";
	} else if (cl == black) {
		converted = "black";
	} else if (cl == white) {
		converted = "white";
	} else if (cl == blue) {
		converted = "blue";
	} else if (cl == invalid_color) {
		converted = "invalid color";
	} else {
		converted = "no color";
	};
	return converted;
}

piece_color stringtocolor(string clstring) {
	tolowercase(clstring);

	if (clstring == "red") {
		return piece_color::red;
	}
	else if(clstring == "black"){
		return piece_color::black;
	}
	else if (clstring == "white") {
		return piece_color::white;
	}
	else if (clstring == "blue") {
		return piece_color::blue;
	}
	else if (clstring == "" || clstring == " ") {
		return piece_color::no_color;
	}
	else {
		return piece_color::invalid_color;
	}
}

game_piece::game_piece()
	: cl_(piece_color::no_color),piece_name_(""),piece_display_(""){}

game_piece::game_piece(piece_color cl, string piece_name, string piece_display)
	: cl_(cl),piece_name_(piece_name),piece_display_(piece_display){}





