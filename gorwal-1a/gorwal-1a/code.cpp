#include <iostream>
#include <vector>
#include "d_random.h"
#include "code.h"
#include <string>

using namespace std;

//Initialize with a length and range
code::code(int n, int m){
	
	code_length = n;
	digit_range = m;

	//Size of secret code was not known at compile-time, so resize it here
	secret.resize(n);
	
	//initialize randomnumber object
	randomNumber random(0);
	
	//Fill vector with random numbers
	for (int i = 0; i < code_length; i++)
	{
		secret[i] = random.random(m);
	}
	
	//print for debug
	cout << "\nReal answer: ";
	
	for (int i = 0; i < code_length; i++)
	{
		cout << secret[i];
	}
	cout << "\n\n";

}//end constructor

//Check for the number of correct digit matches (same number and position)
int code::checkCorrect(const vector<int> &guess){
	
	int numCorrect = 0;

	//assume that guess is same length as secret. Enforce this in main when getting guesses
	for (int i = 0; i < code_length; i++)
	{
		if (secret[i] == guess[i])
			numCorrect++;
	}

	return numCorrect;
}

//Check for number of cases of right digit in wrong location
int code::checkIncorrect(const vector<int> &guess){
	
	int numIncorrect = 0;
	vector<bool> secretChecked, guessChecked;
	secretChecked.resize(guess.size());
	guessChecked.resize(guess.size());
	for (int i = 0; i < secretChecked.size(); i++)
	{
		secretChecked[i] = guessChecked[i] = false;
	}

	for (int k = 0; k < code_length; k++)
	{
		if (secret[k] == guess[k])
		{
			guessChecked[k] = true;
			secretChecked[k] = true;
		}
	}

	for (int i = 0; i < code_length; i++)
	{
		for (int j = 0; j < code_length; j++)
		{
			if ((secret[i] == guess[j]) && (secretChecked[i] == false) && (guessChecked[j] == false) && (i != j) )
			{
				numIncorrect++;
				secretChecked[i] = guessChecked[j] = true;
				break;
			}
		}
	}
	
	return numIncorrect;
}

//Return length of secret code
int code::getLength()
{
	return code_length;
}