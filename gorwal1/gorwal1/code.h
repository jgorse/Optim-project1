#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <vector>
using namespace std;

class code
{
public:
	code(int, int);
	int checkCorrect(const vector<int> &guess);
	int getLength();
private:
	int code_length, digit_range;
	vector<int> secret;
	
};

#endif //CODE_H