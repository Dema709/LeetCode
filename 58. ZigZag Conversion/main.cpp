#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	string convert(string & s, int numRows){
		//Период получившейся функции равен numRows*2-2
		//В первый ряд попадают все символы, для которых i%period == 0
		//Для последнего ряда (i-numRows+1+period)%period == 0
		
		//Runtime: 8 ms, faster than 99.59% of C++ online submissions for ZigZag Conversion.
		//Memory Usage: 8.1 MB, less than 73.50% of C++ online submissions for ZigZag Conversion.
		
		if (numRows == 1) return s;
		
		string answer; answer.reserve(s.size());
		for (int i=0; i<s.size(); i+=numRows*2-2){
			answer.push_back(s[i]);
		}
		//answer.push_back(' ');
		if (numRows>2){
			for (int j=0; j<numRows-2; j++){
				int i = j+1, delta = (numRows-j-2)*2, secondDelta = (numRows*2-2) - delta;
				while (i<s.size()){
					answer.push_back(s[i]);
					i += delta;
					if (i<s.size()){
						answer.push_back(s[i]);
					} else {
						break;
					}
					i += secondDelta;
				}
			}
		}
		//answer.push_back(' ');
		for (int i=numRows-1; i<s.size(); i+=numRows*2-2){
			answer.push_back(s[i]);
		}
		return answer;
	}
};

int main() {
	
	{
		string s = "PAYPALISHIRING";
		int numRows = 3;
		string answer = "PAHNAPLSIIGYIR";
		auto real_answer = Solution().convert(s, numRows);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string s = "PAYPALISHIRING";
		int numRows = 4;
		string answer = "PINALSIGYAHRPI";
		auto real_answer = Solution().convert(s, numRows);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string s = "A";
		int numRows = 1;
		string answer = "A";
		auto real_answer = Solution().convert(s, numRows);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string s = "ABA";
		int numRows = 2;
		string answer = "AAB";
		auto real_answer = Solution().convert(s, numRows);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
ZigZag Conversion

The string PAYPALISHIRING is written in a zigzag pattern on a given number of rows like this (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1
Input s = PAYPALISHIRING, numRows = 3
Output PAHNAPLSIIGYIR

Example 2

Input s = PAYPALISHIRING, numRows = 4
Output PINALSIGYAHRPI
Explanation

P     I    N
A   L S  I G
Y A   H R
P     I
*/