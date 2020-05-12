/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "SymbolicCommand.h"
#include "DirectoryFile.h"
#include "ImageFile.h"
#include "TextFile.h"
#include "ProxyFile.h"
#include<iostream>

using namespace std;

SymbolicCommand::SymbolicCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

int SymbolicCommand::execute(std::string& CWD, std::string options) {
	int eIndex = options.find_first_of(" ");
	string fileName = options.substr(0, eIndex);
	string fullPath = options.substr(eIndex + 1, string::npos);
	int eeIndex = options.find_last_of("/");
	string lastDir = options.substr(eeIndex, string::npos);
	AbstractFile* f = fs->openFile(CWD + "/" + fileName);
	if (f == nullptr) {
		cout << "wrong file name" << endl;
		return filedoesnotexist;
	}
	else if (lastDir == CWD) {
		if (dynamic_cast<ProxyFile*>(f) != nullptr) {
			return sameCopyInSameDirectory;
		}
	}
	else {
		cout << "enter not copy a ProxyFile in the same place" << endl;
		if (dynamic_cast<DirectoryFile*>(f) != nullptr) {
			cout << "filetoSym is Directory" << endl;
			return cannotSymDir;
		}
		else if (dynamic_cast<ImageFile*>(f) != nullptr) {
			cout << "filetoSym is ImageFile" << endl;
			ImageFile copyofOriginal = *(dynamic_cast<ImageFile*>(f));
			fs->closeFile(f);
			fs->deleteFile(fileName);
			ProxyFile* proxy1 = new ProxyFile(&copyofOriginal);
			fs->addFile(CWD + "/" + proxy1->getName(), proxy1);
			ProxyFile* proxy2 = new ProxyFile(proxy1);
			fs->addFile(fullPath + "/" + proxy2->getName(), proxy2);
		}
		else if (dynamic_cast<TextFile*>(f) != nullptr) {
			TextFile* copyofOriginal = new TextFile(*(dynamic_cast<TextFile*>(f)));
			fs->closeFile(f);
			fs->deleteFile(CWD + "/" + fileName);
			ProxyFile* proxy1 = new ProxyFile(copyofOriginal);
			int result = fs->addFile(CWD + "/" + proxy1->getName(), proxy1);
			cout << "before proxy2" << endl;
			ProxyFile* proxy2 = new ProxyFile(&*proxy1);
			//ProxyFile* proxy2 = proxy1;
			cout << "after proxy2" << endl;
			cout << "proxy2 name is " << proxy2->getName() << endl;
			cout << "proxy2 parent is " << proxy2->getParent()->getName() << endl;
			int result2 = fs->addFile(fullPath + "/" + proxy2->getName(), proxy2);
			cout << "fullPath is " << fullPath << endl;
			cout << "result2 is " << result2 << endl;
		}
		else if (dynamic_cast<ProxyFile*>(f) != nullptr) {
			cout << "FiletoSym is ProxyFile" << endl;
			fs->closeFile(f);
			ProxyFile* proxy = new ProxyFile(f);
			fs->addFile(fullPath + "/" + proxy->getName(), proxy);
		}
	}
	return success;
}
void SymbolicCommand::displayInfo() {
	cout << "create a symbolic link to an existing file and add the symbolic link to the file system at a given location" << endl;
	cout << "Usage: sym <filename> <full_path_to_destination>" << endl;
}