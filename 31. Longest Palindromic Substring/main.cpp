#include "test_runner.h"
#include "profile.h"

using namespace std;

class Solution {
public:
//Решение из интернета, 12 мс, 6.7 Мб
//I recoded this more intuitively, hopefully it's easier to read:
string longestPalindrome(string s) {
    if(s.size() < 2) return s;
    int max_len = 0;
    int start_idx = 0;
    int i = 0;
    while(i < s.size()) {
																											cout<<"i "<<i<<endl;
        int r_ptr = i; 
        int l_ptr = i;
        //find the middle of a palindrome
        while(r_ptr < s.size()-1 && s[r_ptr] == s[r_ptr + 1]) r_ptr++;//На случай чётных палиндромов (ну и других с повторами, чтобы не делать лишнюю работу)
        i = r_ptr+1;
        //expand from the middle out
        while(r_ptr < s.size()-1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1]) {
            r_ptr++;
            l_ptr--;
        }
        int new_len = r_ptr - l_ptr + 1;
        if(new_len > max_len) {
            start_idx = l_ptr;
            max_len = new_len;
        }
    }
    return s.substr(start_idx, max_len);
}



/*
//Моё решение, 708 мс, 6.9 Мб
	string longestPalindrome(string s){
		if (s.size()<2) return s;
		for (int i=0; i<s.size(); i++){
			//Узнаём, палиндром ли выражение длиной s.size()-i
			//Таких палиндромов должно быть i+1
			for (int j=0; j<i+1; j++){
				if (isPalingrome({&s[j], s.size()-i}))
					return string{&s[j], s.size()-i};
			}
		}
		return s;//Заглушка. Без неё компилятор ругается на возможный невозврат значения)
		//Хотя такого не будет, и в любом случае сюда не дойдём, так как выражение длиной
		//в 1 символ - всегда палиндром, а короткие строки мы отбрасываем в самом начале.
	}
private:
	bool isPalingrome(string_view s){
		for (int i=0; i<s.size()/2; i++){
			if (s[i]!=s[s.size()-1-i])
				return false;
		}
		return true;
	}*/
};

int main() {
	
	{
		string input = "babad";
		string answer = "bab";
		string real_answer = Solution().longestPalindrome(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = "cbbd";
		string answer = "bb";
		string real_answer = Solution().longestPalindrome(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/