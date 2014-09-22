#include <iostream>
#include <vector>
#include "code.h"

using namespace std;

vector<int> getGuess(int length);

int main() {

	//get length and range from user
	int n, m;
	cout << "Please enter code length: ";
	cin >> n;
	
	cout << "Please enter digit range: 0-";
	cin >> m;
	if (m > 9)
	{
		cout << "range must be 9 or less!\n";
		return 0;
	}

	//Initialize code with user inputs
	code code(n, m);
	int maxGuess = 3, correctDigits = 0;
	bool winner = false;
	
	//Allow user to enter up to maxGuess guesses
	for (int i = 0; i < maxGuess; i++)
	{
		//get this round's guess from user
		cout << "Enter a guess for this round\n";
		vector<int> guess = getGuess(code.getLength());

		//check user's guess
		if (code.checkCorrect(guess) == code.getLength())
		{	
			winner = true;
			break;
		}
		cout << "Your guess was incorrect!\n\n";
	}

	//Annouce win/lose results
	if (winner)
		cout << "You win!\n\n";
	else
		cout << "You lose!\n\n";


	system("pause");
	return 0;

} // End of Main

vector<int> getGuess(int length)
{
	vector<int> guess(length);
	for (int i = 0; i < length; i++)
	{
		cout << "guess["<<i<<"] = ";
		cin >> guess[i];
	}

	return guess;
}