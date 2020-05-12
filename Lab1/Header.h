#pragma once
enum indices { name_program, name_input, num_arg };
enum results { success, filenotopen, wrongnumarg };

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int parse(vector<string>& v, char* c) {
	ifstream ifs;
	ifs.open(c);
	if (ifs.is_open()) {
		string word;
		while (ifs >> word) {
			v.push_back(word);
		}
		ifs.close();
		return success;
	}
	else {
		cout << "The file is not open." << endl;
		ifs.close();
		return filenotopen;
	}
	
}

int usage_message(char* c) {
	cout << "usage:lab1<" << c << ">" << endl;
	return wrongnumarg;
}

