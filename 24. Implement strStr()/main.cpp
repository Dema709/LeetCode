#include "test_runner.h"

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle){
		if (needle.empty()) return 0;
		//cout<<"haystack.size()-needle.size()="<<haystack.size()-needle.size()<<endl;
		for (int i=0; i<static_cast<int>(haystack.size())-static_cast<int>(needle.size())+1; i++){
			//bool answer_found = false;
			for (int j=0; j<needle.size();j++){
				cout<<"i="<<i<<" j="<<j<<endl;
				if (haystack[i+j]!=needle[j]) break;
				if (j==needle.size()-1 && haystack[i+j]==needle[j]) return i;
			}
		}
		
		return -1;
	}
};


int main() {
	
	{
		string haystack = "hello";
		string needle = "ll";
		int answer = 2;
		int real_answer = Solution().strStr(haystack, needle);
		//cout<<endl<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string haystack = "aaaaa";
		string needle = "bba";
		int answer = -1;
		int real_answer = Solution().strStr(haystack, needle);
		//cout<<endl<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string haystack = "abb";
		string needle = "abaaa";
		int answer = -1;
		int real_answer = Solution().strStr(haystack, needle);
		//cout<<endl<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Constraints:
haystack and needle consist only of lowercase English characters.
*/