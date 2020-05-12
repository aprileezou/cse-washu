#include "DisplayCommand.h"
#include<iostream>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int DisplayCommand::execute(string& CWD, string options) {
	if (options.find_first_of('-') == string::npos) {
		string fullPath = CWD + "/" + options;
		AbstractFile* f = fs->openFile(fullPath);
		ReadFileVisitor reader;
		f->accept(&reader);
		fs->closeFile(f);
	}
	else {
		size_t eIndex = options.find_first_of(' ');
		string fileName = options.substr(0, eIndex);
		string fullPath = CWD + "/" + fileName;
		AbstractFile* f = fs->openFile(fullPath);

		size_t sIndex = fileName.find_first_of('.');
		string type = fileName.substr(sIndex + 1, string::npos);
		if (type == "img") {
			vector<char> contents = f->read();
			for (size_t i = 0; i < contents.size(); ++i) {
				if (i == contents.size() - 1) {
					cout << contents[i] << endl;
				}
				else {
					cout << contents[i];
				}
			}
		}
		else {
			ReadFileVisitor reader;
			f->accept(&reader);
			fs->closeFile(f);
		}
	}
	return success;
}


void DisplayCommand::displayInfo() {
	cout << "display file contetns formatted or unformatted" << endl;
	cout << "Usage: ds <directory name> or ds .." << endl;
}