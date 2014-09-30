#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef CODE_H
#define CODE_H

class code
{

public:

	//Initialize with a length and range
	code(int, int);

	//Check for the number of correct digit matches (same number and position)
	int checkCorrect(const vector<int> &guess);

	//Check for number of cases of right digit in wrong location
	int checkIncorrect(const vector<int> &guess);

	//Return length of secret code
	int getLength();

private:

	int code_length, digit_range;
	vector<int> secret;
	
};



#endif //CODE_H