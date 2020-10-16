#include "test_runner.h"

using namespace std;

class Solution  {
public:
	void reverseString(vector<char>& s){
		for (int i=0;i<s.size()/2;i++){
			swap(s[i],s[s.size()-1-i]);
		}
	}
};


int main() {
	
	{
		vector<char> s1 = {'h','e','l','l','o'};
		vector<char> s2 = {'o','l','l','e','h'};
		Solution().reverseString(s1);
		ASSERT_EQUAL(s1,s2);
	}
	
	{
		vector<char> s1 = {'H','a','n','n','a','h'};
		vector<char> s2 = {'h','a','n','n','a','H'};
		Solution().reverseString(s1);
		ASSERT_EQUAL(s1,s2);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Reverse String

Write a function that reverses a string. The input string is given as an array of characters char[].
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
You may assume all the characters consist of printable ascii characters.

Example 1:
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/