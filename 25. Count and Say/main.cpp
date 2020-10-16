#include "test_runner.h"

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		vector<int> v = {1};
		for (int i=1;i<n;i++){
			v = countAndSayOnce(v);
		}
		
		ostringstream output;
		for (auto t : v){
			output<<t;
		}
		return output.str();
	}
private:
	vector<int> countAndSayOnce(vector<int> vect){
		vector<int> v;
		int temp_n = vect[0], temp_count = 1;
		for (int i=1;i<vect.size();i++){
			if (vect[i]!=temp_n){
				v.push_back(temp_count);
				v.push_back(temp_n);
				//
				temp_n = vect[i];
				temp_count = 1;
			} else {
				temp_count++;
			}
		}
		v.push_back(temp_count);
		v.push_back(temp_n);
		return v;
	}
};


int main() {
	
	//cout<<Solution().countAndSayOnce({1,2,1,1});
	
	{
		int n = 1;
		string answer = "1";
		string real_answer = Solution().countAndSay(n);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		int n = 2;
		string answer = "11";
		string real_answer = Solution().countAndSay(n);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		int n = 3;
		string answer = "21";
		string real_answer = Solution().countAndSay(n);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		int n = 4;
		string answer = "1211";
		string real_answer = Solution().countAndSay(n);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		int n = 5;
		string answer = "111221";
		string real_answer = Solution().countAndSay(n);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in
other words from the previous member read off the digits, counting the number of digits in groups of the same digit.
Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"
Explanation: This is the base case.

Example 2:
Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means
frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".
*/