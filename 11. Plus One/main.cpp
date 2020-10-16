#include "test_runner.h"
//#include <cmath>
using namespace std;

class Solution  {
public:
	vector<int> plusOne(vector<int>& digits){
		/*
		Решение на маленькие размеры вектора digits
		int d_size = digits.size();
		size num_answer = 0;
		for (int i=0;i<d_size;i++){
			num_answer += digits[d_size-1-i] * pow(10, i);
		}
		num_answer++;
		vector<int> answer;
		
		if (num_answer / static_cast<int>(pow(10,d_size))){
			answer.reserve(d_size+1);
			
			answer.push_back(1);
			for (int i=0;i<d_size;i++){
				answer.push_back(0);
			}
		} else {
			int temp_num;
			answer.reserve(d_size);
			for (int i=0;i<d_size;i++){
				temp_num = pow(10,d_size-1-i);
				answer.push_back(num_answer/temp_num);
				num_answer %= temp_num;
			}
		}*/
		vector<int> answer = digits;
		bool should_i_plus = true;
		for (int i=0;i<answer.size();i++){
			if (answer[answer.size()-1-i]!=9){
				answer[answer.size()-1-i]++;
				break;
			} else {
				answer[answer.size()-1-i] = 0;
			}
		}
		if (answer[0] == 0){
			answer.insert(answer.begin(),1);
		}
		
		return answer;
	}
};


int main() {
	
	{
		vector<int> v  = {1,2,3};
		vector<int> v2 = {1,2,4};
		ASSERT_EQUAL(Solution().plusOne(v), v2);
	}
	
	{
		vector<int> v  = {4,3,2,1};
		vector<int> v2 = {4,3,2,2};
		ASSERT_EQUAL(Solution().plusOne(v), v2);
	}
	
	{
		vector<int> v  = {0};
		vector<int> v2 = {1};
		ASSERT_EQUAL(Solution().plusOne(v), v2);
	}

	{
		vector<int> v  = {9,8,7,6,5,4,3,2,1,0};
		vector<int> v2 = {9,8,7,6,5,4,3,2,1,1};
		ASSERT_EQUAL(Solution().plusOne(v), v2);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Plus One

Given a non-empty array of digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself. 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

Example 3:

Input: digits = [0]
Output: [1]

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
*/