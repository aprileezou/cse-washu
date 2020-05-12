/*
Author: Yixuan Cheng
Purpose: CSE 332 lab 5
*/

#include "CatCommand.h"
#include<iostream>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int CatCommand::execute(std::string& CWD, std::string options) {
	string filename;
	if (options.find_first_of(' ') != string::npos) {
		// create file with filename only, allows for creating files with directories not currently the working directory
		filename = options.substr(0,options.find_first_of(' '));
	}
	else {
		filename = options;
	}	
	string fullPath = CWD;
	fullPath += '/';
	fullPath += filename;
	AbstractFile* f = fs->openFile(fullPath);
	if (f == nullptr) {
		cout << "current directory doesn't exist" << endl;
		return CWDdoesnotexist;
	}
	else {
		if (options.substr(options.find_last_of(' ') + 1, string::npos) == "-a") { // append input in the current contents of file
			cout << fullPath << endl;  //show current directory
			vector<char> con = f->read();
			string cs = "";
			for (size_t i = 0; i < con.size(); ++i) {
				cs = cs + con[i];
			}
			cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving" << endl;
			string input;
			vector <char> temp;

			while (getline(cin, input)) {
				if (input == ":q") {
					fs->closeFile(f);
					return success;
				}
				else if (input == ":wq") {
					f->append(temp);
					fs->closeFile(f);
					return success;
				}
				else {
					vector<char> ta;
					ta.resize(input.size());
					ta.assign(input.begin(), input.end());
					temp.insert(temp.end(), ta.begin(), ta.end());
					temp.push_back('\n');
				}
			}
			fs->closeFile(f);
		}
		else {
			cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving" << endl;
			string input;
			vector <char> temp;

			while (getline(cin, input)) {
				if (input == ":q") {
					fs->closeFile(f);
					return success;
				}
				else if (input == ":wq") {
					f->write(temp);
					fs->closeFile(f);
					return success;
				}
				else {
					vector<char> ta;
					ta.resize(input.size());
					ta.assign(input.begin(), input.end());
					temp.insert(temp.end(), ta.begin(), ta.end());
					temp.push_back('\n');
				}
			}
			fs->closeFile(f);
		}
	}
	return success;
}


void CatCommand::displayInfo() {
	cout << "concatenating files" << endl;
	cout << "Usage: cat <file name> or cat .." << endl;
}