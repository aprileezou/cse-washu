#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

#include "gamepiece.h"

int readfiledim(ifstream& rfile, unsigned int& x, unsigned int& y);

int readfilepiece(ifstream& rfile, vector<game_piece>& pieces, unsigned int dimx, unsigned int dimy);

int printoutpiece(const vector<game_piece>& pieces, unsigned int m, unsigned int n);