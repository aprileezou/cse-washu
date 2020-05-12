#include "CopyCommand.h"
#include <iostream>
#include <string>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* fileSys) : fs(fileSys) {};

int CopyCommand::execute(std::string& CWD, std::string options) {
	string filename;
	filename = options.substr(0, options.find_first_of(' '));
	AbstractFile* f = fs->openFile(CWD + '/' + filename);
	AbstractFile* cf = f->clone();
	if (cf == nullptr) {
		delete cf;
		cout << "directory is not copable" << endl;
		return directorynotcopable;
	}
	fs->closeFile(f);
	string newpath = options.substr(options.find_first_of(' ') + 1, string::npos);
	if (fs->addFile(newpath + '/' + filename, cf) != 0) {
		delete cf;
		cout << "adding file fails" << endl;
		return failedtoadd;
	}
	return success;
}

void CopyCommand::displayInfo() {
	cout << "copy the file to the system in a different location" << endl;
	cout << "Usage:cp <file_to_copy> <full_path_to_destination>" << endl;
}