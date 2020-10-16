#include "test_runner.h"
#include "profile.h"
//#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool wordBreak(string & s, vector<string>& wordDict){
		//Runtime: 0 ms			100%, идеально! ^^
		//Memory Usage: 8.3 MB	84%
		
		string_view sv(s);
		unordered_set<int> unreal_set;//Для этой длины нет подходяшего префикса
		return deleteOneWord(sv, wordDict, 0, unreal_set);
	}
private:
	bool deleteOneWord(string_view s, vector<string>& wordDict, int remove_prefix_size, unordered_set<int> & unreal_set){
		s.remove_prefix(remove_prefix_size);
		if (s.empty()) return true;
		
		bool stepOk = false;
		for (string & word : wordDict){
			if (word.size() <= s.size() && !unreal_set.count(s.size() - word.size())){
				bool wordContains = true;
				for (int i=0; i<word.size(); i++){
					if (word[i] != s[i]){
						wordContains = false;
						break;
					}
				}
				if (wordContains){
					if (deleteOneWord(s, wordDict, word.size(), unreal_set)){
						return true;
					} else {
						unreal_set.insert(s.size()-word.size());
					}
				}
			}
		}
		return false;
	}
};

int main() {
	
	{
		string s  = "leetcode";
		vector<string> wordDict = {"leet", "code"};
		bool answer = true;
		auto real_answer = Solution().wordBreak(s, wordDict);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string s  = "applepenapple";
		vector<string> wordDict = {"apple", "pen"};
		bool answer = true;
		auto real_answer = Solution().wordBreak(s, wordDict);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string s  = "catsandog";
		vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
		bool answer = false;
		auto real_answer = Solution().wordBreak(s, wordDict);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string s  = "catsandog";
		vector<string> wordDict = {};
		bool answer = false;
		auto real_answer = Solution().wordBreak(s, wordDict);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string s  = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
		vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
		bool answer = false;
		LOG_DURATION("36 / 43 test case");
		auto real_answer = Solution().wordBreak(s, wordDict);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string s  = "paviraagi";
		vector<string> wordDict = {"pavira","pavi","raa","gi","ag","ii"};
		bool answer = true;
		LOG_DURATION("37 / 43 test case");
		auto real_answer = Solution().wordBreak(s, wordDict);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Word Break

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.
Note:
    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/