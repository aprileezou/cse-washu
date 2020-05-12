#pragma once

#include "AbstractCommand.h"

class SymbolicCommand :public AbstractCommand {
public:
	SymbolicCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~SymbolicCommand() = default;
private:
	AbstractFileSystem* fs;
};