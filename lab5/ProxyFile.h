#pragma once
#include "AbstractFile.h"

using namespace std;

class ProxyFile :public AbstractFile {
	// friends
	friend class ReadFileVisitor;
	friend class SimpleFileSystem;
	friend class HierarchicalFileSystem;
public:
	ProxyFile(const ProxyFile&);
	ProxyFile(AbstractFile*);

	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual AbstractFile* clone() override;
	virtual AbstractFile* getParent() override;

	int getCounter();

	virtual ~ProxyFile();

	virtual void accept(AbstractFileVisitor*) override;

protected:
	virtual int addChild(AbstractFile*) override;
	virtual int removeChild(std::string name) override;
	virtual void setParent(AbstractFile*) override;
	virtual AbstractFile* getChild(std::string name) override;
	//virtual AbstractFile* getParent() override;

private:
	int* counter;
	AbstractFile* originalFile;
	AbstractFile* parent;
};
