#include <iostream>
#include <vector>
#include "code.h"
using namespace std;

#ifndef MASTERMIND_H
#define MASTERMIND_H

class mastermind
{

public:
	//constructor passing default data to 'code' constructor
	mastermind();

	//constructor passing user-given data to 'code' constructor
	mastermind(int n, int m);

	//main gameplay function
	void gameplay();

private:
	//function to handle each round of guessing. Should only be called from 'gameplay()'
	void round();
	
	//private data
	code secret;
	vector<int>userGuess;
	int maxGuess = 3;
	int correctDigits = 0, incorrectDigits = 0;
	bool winner = false;

};

#endif //MASTERMIND_H