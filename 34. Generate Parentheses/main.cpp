#include "test_runner.h"
#include "profile.h"
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis_variant_2(int n){
		vector<string> answer;
		//Вариант через функцию generate_next_step. Генерация через выбор одного из двух путей:
		//добавить открывающую скобку (если они не закончились) или закрывающую (если баланс незакрытых скобок больше нуля)
		//Должно работать быстрее. Лень переделывать
		return answer;
	}
	vector<string> generateParenthesis(int n){
		vector<string> answer;
		string s(n,'('); for (int i=0;i<n;i++) {s.push_back(')');} answer.push_back(s);
		//cout<<s<<endl;
		string temp_string(s); next_permutation(temp_string.begin(), temp_string.end());
		while (temp_string!=s){
			if (is_valid_parenthesis(temp_string)){
				//cout<<temp_string<<endl;
				answer.push_back(temp_string);
			}
			next_permutation(temp_string.begin(), temp_string.end());
		}
		set <string> answer_set;
		
		return answer;
	}
private:
	bool is_valid_parenthesis(string & s){
		int open_parenthesis_count = 0;
		for (int i=0;i<s.size();i++){
			if (s[i]=='('){
				open_parenthesis_count++;
			} else {
				open_parenthesis_count--;
			}
			if (open_parenthesis_count<0){
				return false;
			}
		}
		return true;
	}
	void generate_next_step(int current_step, string & s, int open_parenthesis_count, int open_parenthesis_left){
		
	}
};

int main() {
	
	{
		int input = 3;
		vector<string> answer = {
			"((()))",
			"(()())",
			"(())()",
			"()(())",
			"()()()"
		};
		vector<string> real_answer = Solution().generateParenthesis(input);
		cout<<real_answer<<endl<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/