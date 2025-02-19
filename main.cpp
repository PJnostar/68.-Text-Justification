#include "functions/solution.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cout << "================================" << endl;
	vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."} ;
	int maxWidth = 16;
	vector<string> result = fullJustify(words, maxWidth);
	printVector(result);

	words = {"What","must","be","acknowledgment","shall","be"};
	result = fullJustify(words, maxWidth);
	printVector(result);

	words = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"} ;
	result = fullJustify(words, maxWidth);
	printVector(result);

}

