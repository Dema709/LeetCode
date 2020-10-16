#include "test_runner.h"
#include <string_view>
using namespace std;

class Solution {
public:
	int romanToInt(string s){
		
		vector<pair<char,int>> symbols = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
		string_view s_View = s;
		/*for (int i=0;i<Symbols.size();i++){
			auto n = s.find(Symbols[Symbols.size()-1-i].first);
			if (n!=string::npos){
				cout<<Symbols[Symbols.size()-1-i].second<<"'s pos=";
				cout<<s.find(Symbols[Symbols.size()-1-i].first)<<endl;
				if (n==0){
					
				}
				
				
				
			}
			
		}	//cout<<endl;*/
		
		
		return romanToInt(s_View, symbols, symbols.size()-1);//Заглушка
	}
	
	
	
	int romanToInt(string_view string_to_recognize, vector<pair<char,int>>& symbols, int n /*Номер символа*/){
		auto pointer = string_to_recognize.find(symbols[n].first);
		const size_t pos_end = string_to_recognize.npos;
		if (pointer == pos_end){
			//Такого символа нет
			if (n==0){
				return 0;
			} else {
				return romanToInt(string_to_recognize, symbols, n-1);
			}
		} else {
			
			//cout<<'\''<<symbols[n].first<<"\' at position "<<pointer<<endl;
			if (pointer!=0){
					//cout<<string_to_recognize<<"=-"<<string_to_recognize.substr(0,pointer)<<'+';
				int result = romanToInt(string_to_recognize.substr(0,pointer), symbols, n-1);
				string_to_recognize.remove_prefix(pointer);
					//cout<<string_to_recognize<<endl;
				return romanToInt(string_to_recognize, symbols, n) - result;
				//cout<<"result: "<<result<<endl;
			} else {
				int result = symbols[n].second;
					//cout<<string_to_recognize<<"="<<symbols[n].first<<'('<<result<<")+";
				string_to_recognize.remove_prefix(1);
					//cout<<string_to_recognize<<endl;
				return romanToInt(string_to_recognize, symbols, n) + result;//int result = 
				
			}
			
			
			
		}
		
		
		return 0;//Заглушка
	}
};


int main() {
	
	{
		string s = "III";
		int answer = 3;
		int real_answer = Solution().romanToInt(s);
		//cout<<s<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "IV";
		int answer = 4;
		int real_answer = Solution().romanToInt(s);
		//cout<<s<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "IX";
		int answer = 9;
		int real_answer = Solution().romanToInt(s);
		//cout<<s<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "LVIII";
		int answer = 58;
		int real_answer = Solution().romanToInt(s);
		//cout<<s<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "MCMXCIV";
		int answer = 1994;
		int real_answer = Solution().romanToInt(s);
		//cout<<s<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: "III"
Output: 3

Example 2:
Input: "IV"
Output: 4

Example 3:
Input: "IX"
Output: 9

Example 4:
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/