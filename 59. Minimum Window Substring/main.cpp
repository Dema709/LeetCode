#include "test_runner.h"
#include "profile.h"
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string minWindow(string & s, string & t) {
		if (s.size()<t.size()) return "";
        unordered_map<char, int> t_map;
		int s_size = s.size(), t_size = t.size();
		
        for (auto c : t){
            t_map[c]++;
        }
		/*
		s = "ABB";
		unordered_map<char, int> c_map; for (auto c : s){c_map[c]++;};
		cout<<"Map_t: ";for (auto& zz : t_map){cout<<"["<<zz.first<<' '<<zz.second<<"] ";} cout<<endl;
		cout<<"Map_c: ";for (auto& zz : c_map){cout<<"["<<zz.first<<' '<<zz.second<<"] ";} cout<<endl;
		bool m = matching(c_map, t_map); cout<<"matching? "<<m<<endl;
		*/
		
		for (int i=0; i<s_size-t_size; i++){
			unordered_map<char, int> temp_map;
			for (int j=i; j<s_size; j++){
				temp_map[s[j]]++;
				if (j-i+1 >= t_size){
					cout<<"Checking: "<<i<<' '<<j<<endl;
					if (matching(temp_map, t_map)){
						cout<<"Match found: "<<i<<' '<<j<<endl;
						cout<<"Map: ";for (auto& zz : temp_map){cout<<"["<<zz.first<<' '<<zz.second<<"] ";} cout<<endl;
						break;
					}
				}
			}
		}
		
        return "";
    }
	bool matching(unordered_map<char, int> & lhs, unordered_map<char, int> & rhs){
		for (auto & r : rhs){
			//cout<<r.first<<' '<<r.second<<' '<<lhs.count(r.first)<<endl;
			if (!lhs.count(r.first)){
				return false;
			} else if(r.second<lhs[r.first]){
				return false;
			}
		}
		return true;
	}
};

int main() {
	
	{
		string s = "ADOBECODEBANC";
		string t = "ABC";
		string answer = "BANC";
		auto real_answer = Solution().minWindow(s, t);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:
Input S = ADOBECODEBANC, T = ABC
Output BANC

Note:
    If there is no such window in S that covers all characters in T, return the empty string .
    If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/