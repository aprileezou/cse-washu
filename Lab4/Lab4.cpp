// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameBase.h"
#include "TicTacToeGame.h"

int main(int argc, char** argv)
{
	GameBase* ab=GameBase::check(argc, argv);
	if (ab != nullptr) {//If ab is not a singular pointer, it means that all the arguments we input could make the program run correctly
		return ab->play();
	}
	else {//there must be something wrong with the input arguments, usemsg can help to detect the problem and give us useful information
		  //the fix the problem
		return usemsg(argc,argv);
	}
}