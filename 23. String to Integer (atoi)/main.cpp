#include "test_runner.h"
#include <cmath>	//pow()

using namespace std;

class Solution {
public:
	int myAtoi(string str){
		vector<int> number;
		bool integer_found = false, sign_found = false;
		bool positive_integer = true;
		for (int i = 0; i<str.size(); i++){
			//cout<<"number "<<number<<endl;
			//cout<<str[i]<<" integer_found = "<<integer_found<<endl;
			//cout<<(!str[i]==' ')<<endl;
			if (!integer_found){
				if (!(str[i]==' ')){
					
					//число или знак?
					if (str[i] == '+' || str[i] == '-'){
						if (sign_found) return 0;
						if (str[i] == '-'){
							positive_integer = false;
						}
						sign_found = true;//integer_found = true;
					} else if (str[i]-'0'>=0 && str[i]-'0'<=9){
						if (str[i] != '0'){
							number.push_back(str[i]-'0');
							integer_found = true;
						} else {
							sign_found = true;////////////////////////////////
						}
					} else {
						return 0;
					}	
				} else {
					if (sign_found) break;
				}				//else do nothing
			} else {
				if (str[i]-'0'>=0 && str[i]-'0'<=9){
					number.push_back(str[i]-'0');
					if (number.size()>10){
						if (positive_integer) {return 2147483647;}
						else {return -2147483648;}
					}
				} else {
					break;
				}
			}
		}
		//cout<<"number "<<number;
		
		//	min/max_int= -2147483648 2147483647
			
		int answer = 0;
		for (int i=0; i<number.size(); i++){
			if (i==9){
				if (number[number.size()-1-i] > 2) {
					if (positive_integer) {return 2147483647;}
					else {return -2147483648;}
				};
				if (number[number.size()-1-i] == 2){
					if (positive_integer){
						if (answer>147483647) return 2147483647;
					} else {
						if (answer<-147483648) return -2147483648;
					}
				}
			}
			if (positive_integer){
				answer += number[number.size()-1-i]*pow(10,i);
			} else {
				answer -= number[number.size()-1-i]*pow(10,i);
			}
		}
		
		return answer;//Заглушка
	}
	

};


int main() {
	
	{
		string s = "42";
		int answer = 42;
		int real_answer = Solution().myAtoi(s);
		//cout<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "   -42";
		int answer = -42;
		int real_answer = Solution().myAtoi(s);
		//cout<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "4193 with words";
		int answer = 4193;
		int real_answer = Solution().myAtoi(s);
		//cout<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "words and 987";
		int answer = 0;
		int real_answer = Solution().myAtoi(s);
		//cout<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "-91283472332";
		int answer = -2147483648;
		int real_answer = Solution().myAtoi(s);
		//cout<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "0000000000000000012345678";
		int answer = 12345678;
		int real_answer = Solution().myAtoi(s);
		//cout<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "     +0  123";
		int answer = 0;
		int real_answer = Solution().myAtoi(s);
		//cout<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		string s = "0-1";
		int answer = 0;
		int real_answer = Solution().myAtoi(s);
		//cout<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
String to Integer (atoi)

Implement atoi which converts a string to an integer.
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character,
takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains
only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned.

Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is
out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−2^31) is returned.
*/