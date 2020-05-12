/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "LSCommand.h"
#include "ReadFileVisitor.h"
#include "ReadMetadataFileVisitor.h"
#include<iostream>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem * fileSys) : fs(fileSys) {}

int LSCommand::execute(std::string& CWD, std::string options) {
	//cout << "options is: " << options << endl;
	AbstractFile* f = fs->openFile(CWD);
	if (f == nullptr) { // file creation failed
		cout << "failed to open directory" << endl;
		return directorydoesnotexist;
	}
	else {
		if (options != "-1") {
			ReadFileVisitor reader;
			f->accept(&reader);
			fs->closeFile(f);
		}
		else {
			vector<char> contents = f->read();
			string cs = "";
			for (size_t i = 0; i < contents.size(); ++i) {
				if (contents[i] != '\n') {
					cs = cs + contents[i];
				}
				else {
					string path = CWD + "/" + cs;
					AbstractFile* cf = fs->openFile(path);
					ReadMetadataFileVisitor mreader;
					cf->accept(&mreader);
					fs->closeFile(cf);
					cs = "";
				}
			}
			fs->closeFile(f);
		}
	}
	return success;
}

void LSCommand::displayInfo() {
	cout << "lists the contents of the current directory" << endl;
	cout << "Usage: ls" << endl;
}