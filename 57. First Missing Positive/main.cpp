#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int> & nums) {
		//Решение из интернета
		int i = 0;
		int n = nums.size();
		while (i < n)
		{
			if (nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i]-1]);
			else
				i++;
		}
		for (i = 0; i < n; ++i)
			if (nums[i] != (i+1))
				return i+1;
		return n+1;
		
		/*
		sort(nums.begin(), nums.end());
		auto it = lower_bound(nums.begin(), nums.end(), 1);
		if (it==nums.end() || *it!=1){
			return 1;
		}
		int possible_answer = 0;
		//it++;
		//cout<<"nums: "<<nums<<endl;
		while (it!=nums.end()){
			//cout<<it-nums.begin()<<" pos_ans="<<possible_answer<<endl;
			if (*it-possible_answer > 1){
				return possible_answer+1;
			}
			possible_answer = *it;
			it++;
		}
		return possible_answer+1;*/
	}
};

int main() {
	
	{
		vector<int> nums = {1,2,0};
		int answer = 3;
		auto real_answer = Solution().firstMissingPositive(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums = {3,4,-1,1};
		int answer = 2;
		auto real_answer = Solution().firstMissingPositive(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums = {7,8,9,11,12};
		int answer = 1;
		auto real_answer = Solution().firstMissingPositive(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums = {0,2,2,1,1};
		int answer = 3;
		auto real_answer = Solution().firstMissingPositive(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums = {};
		int answer = 1;
		auto real_answer = Solution().firstMissingPositive(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	LOG_DURATION("Massive test");
	for (int i=0; i<1; i++){
		{
			vector<int> nums = {55,55,45,13,59,-4,22,3,34,4,-8,32,-3,15,60,20,55,30,-7,36,34,15,6,7,6,0,7,38,18,45,12,12,-1,27,-5,-2,34,58,11,38,33,45,9,40,30,40,0,24,9,34,31,53,59,7,31,36,18,48,44,6,-7};
			int answer = 1;
			//LOG_DURATION("test case 80");
			auto real_answer = Solution().firstMissingPositive(nums);
			//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
			ASSERT_EQUAL(real_answer, answer);
		}
		
		{
			vector<int> nums = {55,55,45,13,59,-4,22,3,34,4,-8,32,-3,15,60,20,55,30,-7,36,34,15,6,7,6,0,7,38,18,45,12,12,-1,27,-5,-2,34,58,11,38,33,45,9,40,30,40,0,24,9,34,31,53,59,7,31,36,18,48,44,6,-7};
			int answer = 1;
			//LOG_DURATION("test case 86");
			auto real_answer = Solution().firstMissingPositive(nums);
			//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
			ASSERT_EQUAL(real_answer, answer);
		}
		
		{
			vector<int> nums = {55,30,58,56,11,64,37,54,30,-2,23,38,8,38,53,28,62,16,10,63,61,58,57,25,8,25,53,11,42,17,21,9,58,15,52,56,14,25,22,31,10,56,4,5,29,44,44,3,-4,41,1,44,34,46,56,52,58,44,-2,12,49,7,8,42,9};
			int answer = 2;
			//LOG_DURATION("test case 98");
			auto real_answer = Solution().firstMissingPositive(nums);
			//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
			ASSERT_EQUAL(real_answer, answer);
		}
		
		{
			vector<int> nums = {55,30,58,56,11,64,37,54,30,-2,23,38,8,38,53,28,62,16,10,63,61,58,57,25,8,25,53,11,42,17,21,9,58,15,52,56,14,25,22,31,10,56,4,5,29,44,44,3,-4,41,1,44,34,46,56,52,58,44,-2,12,49,7,8,42,9};
			int answer = 2;
			//LOG_DURATION("test case 123");
			auto real_answer = Solution().firstMissingPositive(nums);
			//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
			ASSERT_EQUAL(real_answer, answer);
		}
		
		{
			vector<int> nums = {18,21,20,16,2,24,37,-4,32,46,-6,-6,13,28,-9,3,25,1,1,44,38,41,5,-3,40,3,11,17,37,1,35,10,9,2,-1,42,34,5,22,52,38,11,6,58,45,44,5,55,2,28,52,1,55,42,7,-5,42,8,2,-6};
			int answer = 4;
			//LOG_DURATION("test case 159");
			auto real_answer = Solution().firstMissingPositive(nums);
			//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
			ASSERT_EQUAL(real_answer, answer);
		}
		
		{
		vector<int> nums = {99,94,96,11,92,5,91,89,57,85,66,63,84,81,79,61,74,78,77,30,64,13,58,18,70,69,51,12,32,34,9,43,39,8,1,38,49,27,21,45,47,44,53,52,48,19,50,59,3,40,31,82,23,56,37,41,16,28,22,33,65,42,54,20,29,25,10,26,4,60,67,83,62,71,24,35,72,55,75,0,2,46,15,80,6,36,14,73,76,86,88,7,17,87,68,90,95,93,97,98};
			int answer = 100;
			//LOG_DURATION("test case 160");
			auto real_answer = Solution().firstMissingPositive(nums);
			//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
			ASSERT_EQUAL(real_answer, answer);
		}
		
		{
		vector<int> nums = {99,94,96,11,92,5,91,89,57,85,66,63,84,81,79,61,74,78,77,30,64,13,58,18,70,69,51,12,32,34,9,43,39,8,1,38,49,27,21,45,47,44,53,52,48,19,50,59,3,40,31,82,23,56,37,41,16,28,22,33,65,42,54,20,29,25,10,26,4,60,67,83,62,71,24,35,72,55,75,0,2,46,15,80,6,36,14,73,76,86,88,7,17,87,68,90,95,93,97,98};
			int answer = 100;
			//LOG_DURATION("test case 164");
			auto real_answer = Solution().firstMissingPositive(nums);
			//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
			ASSERT_EQUAL(real_answer, answer);
		}
	}
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
First Missing Positive

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

Follow up:
Your algorithm should run in O(n) time and uses constant extra space.
*/