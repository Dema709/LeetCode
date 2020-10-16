#include "test_runner.h"
#include "profile.h"

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits){
		if (digits.empty()) return {};
		
		vector<string> answer;
		vector<vector<char>> digit_to_char_map = {
								{'a','b','c'},	{'d','e','f'},
			{'g','h','i'},		{'j','k','l'},	{'m','n','o'},
			{'p','q','r','s'},	{'t','u','v'},	{'w','x','y','z'}
		};//Алфавит как на кнопочном телефоне
		
		string s;//(digits.size(), '-');
		for (int i=0; i<digits.size(); i++){
			s.push_back(digit_to_char_map[digits[i]-'2'][0]);
		}
		//cout<<s;
		change_and_add_combination(s, answer, digit_to_char_map, digits, 0);
		
		
		return answer;
	}
private:
	void change_and_add_combination(string & s, vector<string> & answer, vector<vector<char>> & digit_to_char_map, string & digits, int cur_index){
		//string & s - изменяемая строка
		//vector<string> & answer - вектор, в который делать push_back
		//vector<vector<char>> & digit_to_char_map - словарь букв
		//string & digits - входные данные (нажимаемые цифры)
		//int cur_index - текущий изменяемый индекс
		if (cur_index==digits.size()-1){
			for (char c : digit_to_char_map[digits[cur_index]-'2']){
				s[cur_index] = c;
				answer.push_back(s);
			}
		} else {
			for (char c : digit_to_char_map[digits[cur_index]-'2']){
				s[cur_index] = c;
				change_and_add_combination(s, answer, digit_to_char_map, digits, cur_index+1);
			}
		}
	}
};

int main() {
	
	{
		string input = "23";
		vector<string> answer = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
		vector<string> real_answer = Solution().letterCombinations(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = "";
		vector<string> answer = {};
		vector<string> real_answer = Solution().letterCombinations(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = "2";
		vector<string> answer = {"a", "b", "c"};
		vector<string> real_answer = Solution().letterCombinations(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/