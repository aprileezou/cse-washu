#pragma once
/*
Author: Yixuan Cheng
Purpose: CSE 332 lab 5, declares the cat command class
*/

#include "AbstractCommand.h"


class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem* fileSys);
	virtual int execute(std::string& CWD, std::string options) override;
	virtual void displayInfo() override;
	virtual ~CatCommand() = default;
private:
	AbstractFileSystem* fs;
};