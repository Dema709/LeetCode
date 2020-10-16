#include "test_runner.h"
#include "profile.h"

using namespace std;

class Solution {
public:
	string getHint(string & secret, string & guess){
		string answer;
		int bulls_count = 0, cows_count = 0;
		map<char, int> secret_map, guess_map;
		for (int i=0; i<secret.size(); i++){
			if (secret[i]==guess[i]){
				bulls_count++;
			} else {
				secret_map[secret[i]]++;
				guess_map[guess[i]]++;
			}
		}
		for (auto p : guess_map){
			if (secret_map.count(p.first)!=0){
				cows_count += min(p.second, secret_map[p.first]);
			}
			//cout<<p.first<<endl;
		}
		
		//Вывод (формирование ответа):
		string temp = to_string(bulls_count);
		for (char c : temp){
			answer.push_back(c);
		}
		answer.push_back('A');
		temp = to_string(cows_count);
		for (char c : temp){
			answer.push_back(c);
		}
		answer.push_back('B');
		return answer;
	}
};

int main() {
	
	{
		string secret = "1807";
		string guess  = "7810";
		string answer = "1A3B";
		auto real_answer = Solution().getHint(secret, guess);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string secret = "1123";
		string guess  = "0111";
		string answer = "1A1B";
		auto real_answer = Solution().getHint(secret, guess);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string secret = "1";
		string guess  = "0";
		string answer = "0A0B";
		auto real_answer = Solution().getHint(secret, guess);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string secret = "1";
		string guess  = "1";
		string answer = "1A0B";
		auto real_answer = Solution().getHint(secret, guess);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Bulls and Cows

You are playing the Bulls and Cows game with your friend.
You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:
The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

Example 1:
Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"

Example 2:
Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.

Example 3:
Input: secret = "1", guess = "0"
Output: "0A0B"

Example 4:
Input: secret = "1", guess = "1"
Output: "1A0B"

Constraints:
1 <= secret.length, guess.length <= 1000
secret.length == guess.length
secret and guess consist of digits only.
*/