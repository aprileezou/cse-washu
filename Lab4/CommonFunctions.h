#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

enum sucfa { success, unabletoopenfile, inputfileempty, wrongnumofarguments };
enum input { programname, gamename, boardwidth, winNumber };
enum game {succ,negativeSizeBoard, negativeWinNumber,wrongGameName,boradtoSmall};

int parseFile(vector<string>& v, char* c);

int usemsg(int argc, char** argv);

void lowerCase(string& s);

