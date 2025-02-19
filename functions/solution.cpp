#include "solution.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;


void hello_world(){
    cout << "nabla" << endl;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result = {};
    vector<string> currLine = {};
    int currLineLength = 0;

    for (int i=0; i<words.size(); i++) {
        // Add word to current Line and increment current Line Length if the sum of:
        // currLineLength 
        // next word length
        // minumum number of spaces in between words (which is the number of words in current Line)
        // is smaller than maxwidth
        if ( currLine.empty() || currLineLength + words[i].length() + currLine.size() <= maxWidth ) {
            currLine.push_back(words[i]);
            currLineLength += words[i].length();
        }
        // Add current Line to the result, reset currLine and Length and put the word[i] there 
        else {
            addLine(result, currLine, currLineLength, maxWidth, false);
            currLine.clear();
            currLine.push_back(words[i]);
            currLineLength = words[i].length();
        }
    }
    if ( !currLine.empty() ) {
        addLine(result, currLine, currLineLength, maxWidth, true);
    }
    return result;
}
void addLine(vector<string>& result, vector<string>& currLine, int currLineLength, int maxWidth, bool isLastLine) {
    // Add spaces to words in currLine using round robin. 
    // If isLastLine - justify LEFT
    // For edge case = single word in currLine: add however many spaces is needed.
    if ( currLine.size() == 1 ) {
        currLine[0].append(maxWidth - currLineLength, ' ');
    } 
    // Last line aka justify LEFT
    else if (isLastLine) {
        string lastLine = {};
        for (auto cl : currLine) {
            lastLine += cl + ' ';
        }
        if (!lastLine.empty() && lastLine.back() == ' ') {
            lastLine.pop_back(); // Remove the trailing space
        }
        lastLine.append( maxWidth - lastLine.length(), ' ' );
        result.push_back(lastLine);
        return;
    }
    // Round robin style of adding spaces
    else {
        int counter = 0;
        while (counter < maxWidth - currLineLength) {
            currLine[counter % (currLine.size()-1)] += ' ';
            counter++;
        }
    }
    result.push_back( std::accumulate(currLine.begin(), currLine.end(), string("")) );
}

void printVector(vector<int> nums) {
    for (auto n:nums) {
        cout << n << "|";
    }
    cout << endl;
}
void printVector(vector<string> s) {
    for (auto n:s) {
        cout << "|" << n << "|" << endl;
    }
    cout << endl;
}
void printVector(vector<vector<int>> nums) {
    for (auto num:nums) {
        for (auto n:num) {
            cout << n << "|";
        }
        cout << endl;
    }
}
void printVector(vector<vector<bool>> nums){
    for (auto num:nums) {
        for (auto n:num) {
            cout << n << "|";
        }
        cout << endl;
    }
}
void printVector(vector<vector<char>>& nums) {
    for (auto num:nums) {
        for (auto n:num) {
            cout << n << "|";
        }
        cout << endl;
    }
}
void printTriangle(vector<vector<int>> triangle) {
    for (int i=0; i<triangle.size(); i++) {
        string spaces = string((triangle.size()-i+1), ' ');
        cout << spaces << "|";
        for (int j=0; j<triangle[i].size(); j++) {
            cout << triangle[i][j] << "|";
        }
        cout << endl;
    }
}