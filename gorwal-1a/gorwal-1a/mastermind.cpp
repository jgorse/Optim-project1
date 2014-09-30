#include <iostream>
#include <vector>
#include <algorithm>
#include "code.h"
#include "mastermind.h"

using namespace std;

//overload << to print vector
ostream& operator << (ostream& os, const vector<int>& c)
{
	for (unsigned int i = 0; i < c.size(); i++)
	{
		os << c[i];
	}

	return os;
}

//overload >> to read vector
istream& operator >> (istream& is, vector<int>& c)
{
	//first empty existing vector to overwrite contents
	c.clear();
	
	//read vector as an integer to be parsed
	int temp;
	is >> temp;	

	while (temp > 9 )
	{
		//get last digit with modulus, remove it with integer division
		c.push_back(temp % 10);
		temp = temp / 10;
	}

	//push last remaining digit to vector
	c.push_back(temp);

	//vector is now in reverse order of user guess, so reverse it
	reverse(c.begin(), c.end());
	return is;
}

//constructor passing user-given data to 'code' constructor
mastermind::mastermind(int n, int m):secret(n, m)
{

}

//constructor passing default data to 'code' constructor
mastermind::mastermind(): secret(5, 5)
{

}

//main gameplay function
void mastermind::gameplay()
{
	//Allow up to maxGuess rounds to be played
	for (int i = 0; i < maxGuess; i++)
	{
		round();
		if (winner)
			break;
	}

	if (winner)
		cout << "You win!\n";
	else
		cout << "You lose!\n";

}

//function to handle each round of guessing
void mastermind::round()
{

	//get this round's guess from user
	cout << "Enter a guess for this round: ";
	cin >> userGuess;


	while (userGuess.size() != secret.getLength())
	{
		cout << "Guess must be same length as secret code!\n";
		cout << "Enter a guess for this round: ";
		cin >> userGuess;
	}

	//check guess
	correctDigits = secret.checkCorrect(userGuess);
	incorrectDigits = secret.checkIncorrect(userGuess);

	//print results to player
	cout << "\nRight digit, right location: " << correctDigits << "\n";
	cout << "Right digit, wrong location: " << incorrectDigits << "\n\n";

	//if every guess is correct, they win
	if (secret.getLength() == correctDigits)
		winner = true;
}