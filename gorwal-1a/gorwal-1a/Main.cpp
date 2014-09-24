#include <iostream>
#include <vector>
#include "code.h"

using namespace std;

vector<int> getGuess(int length);

int main() {

	//get length and range of secret code from user
	int n, m;

	cout << "Please enter code length: ";
	cin >> n;

	if (n <= 0)
	{
		cout << endl << "Length must be at least 1!\n";
		system("pause");
		return 0;
	}

	cout << "Please enter digit range: 0-";
	cin >> m;
	
	//digit range is 0-9
	if (m > 9 || m <= 0)
	{
		cout << "Range must be between 1 and 9!\n";
		system("pause");
		return 0;
	}

	//Initialize code with user inputs
	code code(n, m);
	
	//
	int maxGuess = 3, correctDigits = 0, incorrectDigits = 0;
	bool winner = false;
	
	//Allow user to enter up to maxGuess guesses
	for (int i = 0; i < maxGuess; i++)
	{
		//get this round's guess from user
		cout << "Enter a guess for this round\n";
		vector<int> guess = getGuess(code.getLength());

		//check user's guess
		correctDigits = code.checkCorrect(guess);
		incorrectDigits = code.checkIncorrect(guess);
		cout << correctDigits << " digits were in the correct location\n";
		cout << incorrectDigits << " digits were in the incorrect location\n";

		if ( correctDigits == code.getLength())
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
	//create new vector for user's guess
	vector<int> guess(length);
	int guess_integer = 0, i = 0;

	//prompt user for the guess
	cout << "guess: ";
	cin >> guess_integer;
	
	//put guess digits into a vector
	while (guess_integer)
	{
		guess[i++] = guess_integer % 10;
		guess_integer /= 10;
	}
	//reverse the vector since the above loop puts them in reverse
	std::reverse(guess.begin(), guess.end());

	return guess;
}