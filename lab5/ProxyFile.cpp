#include "ProxyFile.h"
#include <iostream>

using namespace std;

ProxyFile::ProxyFile(const ProxyFile& pf)
{
	cout << "enter counstructor 2" << endl;
	this->originalFile = pf.originalFile;
	*(pf.counter) = *(pf.counter) + 1;
	cout << "*pf.counter is " << *(pf.counter) << endl;
	counter = pf.counter;
	cout << "counter is " << counter << endl;
	parent = nullptr;
};

ProxyFile::ProxyFile(AbstractFile* af) {
	cout << "enter constructor 1" << endl;
	originalFile = af;
	parent = af->getParent();
	counter = new int;
	*counter = 1;
};


AbstractFile* ProxyFile::clone() {
	return nullptr;
}

vector<char> ProxyFile::read() {
	return originalFile->read();
};

int ProxyFile::write(vector<char> v) {
	return originalFile->write(v);
};

int ProxyFile::append(vector<char> v) {
	return originalFile->append(v);
};

unsigned int ProxyFile::getSize() {
	return originalFile->getSize();
};

string ProxyFile::getName() {
	return originalFile->getName();
};

void ProxyFile::accept(AbstractFileVisitor* afv) {
	return originalFile->accept(afv);
};

int ProxyFile::getCounter() {
	return *counter;
}

ProxyFile::~ProxyFile() {
	cout << "before counter decrement " << *counter << endl;
	if (*(counter) != 0) {
		*(counter) = *(counter)-1;
		cout << "after counter decrement " << *counter << endl;
		//delete this;

	}
	else {
		delete counter;
		delete originalFile;
	}
};

int ProxyFile::addChild(AbstractFile* af) {
	return originalFile->addChild(af);
};

int ProxyFile::removeChild(std::string name) {
	return originalFile->removeChild(name);
};

void ProxyFile::setParent(AbstractFile* af) {
	parent = af;
};

AbstractFile* ProxyFile::getChild(std::string name) {
	return originalFile->getChild(name);
};

AbstractFile* ProxyFile::getParent() {
	return parent;
};