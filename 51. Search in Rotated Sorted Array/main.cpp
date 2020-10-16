#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		//Банальный поиск без упора на особые условия
		//На таких длинах массива (1 <= nums.length <= 5000) работает чуть ли не быстрее, чем мудрёный
		//бинарный поиск. По памяти они примерно равны, отличия минимальны и больше зависят от
		//проверяющей системы
		
		//Runtime: 8 ms, faster than 65.30% of C++ online submissions for Search in Rotated Sorted Array.
		//Memory Usage: 11.4 MB, less than 12.84% of C++ online submissions for Search in Rotated Sorted Array.
		auto it = find(nums.begin(), nums.end(), target);
		if (it!=nums.end()){
			return it - nums.begin();
		} else {
			return -1;
		}
    }
};

int main() {
	
	{
		vector<int> nums  = {4,5,6,7,0,1,2};
		int target = 0;
		int answer = 4;
		auto real_answer = Solution().search(nums, target);
		//cout<<real_answer<<" "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {4,5,6,7,0,1,2};
		int target = 3;
		int answer = -1;
		auto real_answer = Solution().search(nums, target);
		//cout<<real_answer<<" "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {1};
		int target = 0;
		int answer = -1;
		auto real_answer = Solution().search(nums, target);
		//cout<<real_answer<<" "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Search in Rotated Sorted Array

You are given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
If target is found in the array return its index, otherwise, return -1.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

Constraints:
    1 <= nums.length <= 5000
    -10^4 <= nums[i] <= 10^4
    All values of nums are unique.
    nums is guranteed to be rotated at some pivot.
    -10^4 <= target <= 10^4
*/