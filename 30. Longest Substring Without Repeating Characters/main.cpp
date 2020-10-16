#include "test_runner.h"
#include "profile.h"

using namespace std;

class Solution {
public:
//Решение из интернета. 68 ms, 8.6 MB. Т.о. оно быстрее в ~10 раз, но использует чуть больше памяти
	int lengthOfLongestSubstring(string s) {
		map<char, int> charMap;//Map'а с индексами последнего вхождения символа
		//Второй вариант - вектор и обращение через char -> int по индексу
        int start = 0;//-1 было в решении
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (charMap.count(s[i]) != 0) {//Если этот символ встречался раньше
                start = max(start, charMap[s[i]]+1);//в оригинале - без +1, а так - это индекс следующего символа после повторяющегося
            }
            charMap[s[i]] = i;//Меняем последнюю позицию символа
            maxLen = max(maxLen, i-start+1);//+1 для получения именно количества символов
        }
        
        return maxLen;
	}
	/*
//Time Limit Exceeded ;p
	//Хотел улучшить, а получилось только хуже
	int lengthOfLongestSubstring(string s) {
		int max_length = 0;
		for (int i=0; i<s.size(); i++){
			int cur_length = 1;
			set<char> cur_set; cur_set.insert(s[i]);
			for (int j=i+1;j<s.size();j++){
				//cout<<"i/j="<<i<<'/'<<j<<" "<<cur_set<<endl;
				if (cur_set.count(s[j])){
					//max_length = max(max_length, cur_length);
					break;
				} else {
					cur_set.insert(s[j]);
					cur_length++;
				}
			}
			max_length = max(max_length, cur_length);
		}
		
		return max_length;
	}
	*/
	/*
//980-1156 ms, 6.9 Mb
	int lengthOfLongestSubstring(string s) {
		if (s.size()==1) return 1;
		int max_length=0;
		
		for (int i=0; i<s.size(); i++){
			//Проверка подстроки с i-того индекса
			for (int j=i+1; j<s.size(); j++){
				//Проверить, совпадает ли символ s[j] с одним из диапазона s[i...j-1]
				bool is_repeating = false;
				for (int k=0; k<j-i; k++){
					if (s[j]==s[i+k]){
						//Найден повтор с i+k элементом
						//Это значит, что найдена подстрока без повторов
						//с индексами [i...j]
						max_length = max(max_length, j-i);
						is_repeating = true;
						i=i+k;
						break;
					}
				}
				if (is_repeating){
					break;
				} else if (j==s.size()-1){
					max_length = max(max_length, j-i+1);
				}
			}
		}
		
		return max_length;
	}
	*/
};

int main() {
	
	{
		string input = "abcabcbb";
		int answer = 3;
		int real_answer = Solution().lengthOfLongestSubstring(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = "bbbbb";
		int answer = 1;
		int real_answer = Solution().lengthOfLongestSubstring(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = "pwwkew";
		int answer = 3;
		int real_answer = Solution().lengthOfLongestSubstring(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = "";
		int answer = 0;
		int real_answer = Solution().lengthOfLongestSubstring(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = " ";
		int answer = 1;
		int real_answer = Solution().lengthOfLongestSubstring(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = " 123";
		int answer = 4;
		int real_answer = Solution().lengthOfLongestSubstring(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = "xxzqi";
		int answer = 4;
		int real_answer = Solution().lengthOfLongestSubstring(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0
 
Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/