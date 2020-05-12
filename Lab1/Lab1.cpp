// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
#include <sstream>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		return usage_message(argv[name_program]);
	}

	vector<string> v;
	if (parse(v, argv[name_input]) != 0) {
		return parse(v, argv[name_input]);
	}

	vector<int> vint;
	for (int i = 0; i < size(v); ++i) {
		istringstream iss(v[i]);
		char character;
		int count = 0;
		while (iss >> character) {
			if (isdigit(character) == false) {
				cout << v[i] << endl;
				break;
			}
			else {
				count += 1;
			}
		}
		if (count == size(v[i])) {
			istringstream issfinal(v[i]);
			while (issfinal >> character) {
				//cout << character << endl;
				vint.push_back(character);
			}
		}
	}

	for (size_t s = 0; s < vint.size(); ++s) {
		cout << vint[s]-48 << endl;
	}

	return success;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
