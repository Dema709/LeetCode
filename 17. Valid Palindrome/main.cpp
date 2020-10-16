#include "test_runner.h"
#include <cctype>

using namespace std;

class Solution  {
public:
	bool isPalindrome(string s){
		vector<char> s_short;
		for (int i=0;i<s.size();i++){
			if (((s[i]-'A')>=0 && (s[i]-'A')<=25) || ((s[i]-'0')>=0 && (s[i]-'0')<=9) || ((s[i]-'a')>=0 && (s[i]-'a')<=25)){
				s_short.push_back(tolower(s[i]));
			}
				
		}
		for (int i=0;i<s_short.size()/2;i++){
			if (s_short[i]!=s_short[s_short.size()-1-i]){
				return false;
			}
		}
		
		return true;
	}
};


int main() {
	
	{
		string s = "A man, a plan, a canal: Panama";
		//cout<<Solution().isPalindrome(s)<<endl;
		ASSERT(Solution().isPalindrome(s));
	}
	
	{
		string s = "race a car";
		//cout<<Solution().isPalindrome(s)<<endl;
		ASSERT(!Solution().isPalindrome(s));
	}
	
	{
		string s = "0P";
		//cout<<Solution().isPalindrome(s)<<endl;
		ASSERT(!Solution().isPalindrome(s));
	}
	
	{
		string s = "ab_a";
		//cout<<Solution().isPalindrome(s)<<endl;
		ASSERT(Solution().isPalindrome(s));
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false
 

Constraints:
s consists only of printable ASCII characters.
*/