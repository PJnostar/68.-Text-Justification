/* https://leetcode.com/problems/permutations/description/ */

#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void hello_world();

vector<string> fullJustify(vector<string>& words, int maxWidth);
void addLine(vector<string>& words, vector<string>& currLine, int currLineLength, int maxWidth, bool isLastLine);

void printVector(vector<int> nums) ;
void printVector(vector<string> s) ;
void printVector(vector<vector<int>> nums);
void printVector(vector<vector<bool>> nums);
void printVector(vector<vector<char>>& board) ;
void printTriangle(vector<vector<int>> triangle);

#endif