#include <iostream>
#include <vector>
#include "code.h"
#include "mastermind.h"

using namespace std;

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

	//create game object and begin playing
	mastermind game(n, m);
	game.gameplay();

	system("pause");
	return 0;

} // End of Main