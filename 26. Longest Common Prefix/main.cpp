#include "test_runner.h"

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		//if (strs.size()==1) return strs[0];
		

		int prefix_size = strs[0].size();
		for (int i=1;i<strs.size();i++){
			prefix_size = longest_common_prefix_size(strs[0], strs[i], prefix_size);
		}
		/*cout<<"prefix_size="<<prefix_size<<endl;
		cout<<string(strs[0], 0, prefix_size)<<endl;*/
		return string(strs[0], 0, prefix_size);
	}
private:
	int longest_common_prefix_size(string & a, string & b, int current_n){
		int answer = 0;
		//int m = min(static_cast<int>(min(a.size(), b.size())), current_n);
		for (int i=0;i<min(static_cast<int>(min(a.size(), b.size())), current_n);i++){
			if (a[i]==b[i]) {
				answer++;
			} else {
				break;
			}
		}
		return answer;
	}
};


int main() {
	
	{
		vector<string> input = {"flower","flow","flight"};
		string answer = "fl";
		string real_answer = Solution().longestCommonPrefix(input);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		vector<string> input = {"dog","racecar","car"};
		string answer = "";
		string real_answer = Solution().longestCommonPrefix(input);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Longest Common Prefix

Solution
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/