#include "test_runner.h"
#include "profile.h"
#include <algorithm>
#include <utility>//pair
using namespace std;

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums){
		//Runtime: 48 ms, faster than 99.04% of C++ online submissions for Shortest Unsorted Continuous Subarray.
		//Memory Usage: 26.8 MB, less than 64.74% of C++ online submissions for Shortest Unsorted Continuous Subarray.
		
		if (nums.size()<2) return 0;
		int unsorted_start = -1;
		for (int i=1; i<nums.size(); i++){
			if (nums[i]<nums[i-1]){
				unsorted_start = i;
				break;
			}
		}
		if (unsorted_start == -1){
			return 0;
		}
		//cout<<"unsorted_start = "<<unsorted_start<<endl;
		int unsorted_end = unsorted_start;
		for (int i=nums.size()-2; i>unsorted_start; i--){
			if (nums[i]>nums[i+1]){
				unsorted_end = i;
				break;
			}
		}
		//cout<<nums<<endl;cout<<"unsorted_start = "<<unsorted_start<<endl;cout<<"unsorted_end = "<<unsorted_end<<endl;
		
		int minimum = nums[unsorted_start], maximum = nums[unsorted_start];
		for (int i=unsorted_start+1; i<=unsorted_end; i++){
			if (nums[i]>maximum) maximum = nums[i];
			else if (nums[i]<minimum) minimum = nums[i];
		}
		while (true){
			bool s_break = true;
			
			//cout<<"unsorted_start = "<<unsorted_start<<endl;cout<<"unsorted_end = "<<unsorted_end<<endl;
			while (unsorted_start > 0){
				if (nums[unsorted_start-1]>minimum){
					unsorted_start--;
					s_break = false;//cout<<"extend left"<<endl;
					
					if (nums[unsorted_start]>maximum) maximum = nums[unsorted_start];
					else if (nums[unsorted_start]<minimum) minimum = nums[unsorted_start];
				} else {
					break;
				}
			}
			
			while (unsorted_end < nums.size()-1){
				if (nums[unsorted_end+1]<maximum){
					unsorted_end++;
					s_break = false;//cout<<"extend right"<<endl;
					
					if (nums[unsorted_end]>maximum) maximum = nums[unsorted_end];
					else if (nums[unsorted_end]<minimum) minimum = nums[unsorted_end];
				} else {
					break;
				}
			}
			if (s_break) return unsorted_end-unsorted_start+1;
		}
		
		//cout<<"unsorted_start = "<<unsorted_start<<endl;cout<<"unsorted_end = "<<unsorted_end<<endl;
		return unsorted_end-unsorted_start+1;
	}
};

int main() {
	
	{
		vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
		int answer = 5;
		auto real_answer = Solution().findUnsortedSubarray(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums = {2, 4, 8, 10, 9, 15};
		int answer = 2;
		auto real_answer = Solution().findUnsortedSubarray(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums = {2, 1};
		int answer = 2;
		auto real_answer = Solution().findUnsortedSubarray(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums = {1,3,2,4,5};
		int answer = 2;
		auto real_answer = Solution().findUnsortedSubarray(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums = {1,3,5,4,2};
		int answer = 4;
		auto real_answer = Solution().findUnsortedSubarray(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Shortest Unsorted Continuous Subarray

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.

Example 1:
Input [2, 6, 4, 8, 10, 9, 15]
Output 5
Explanation You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
    Then length of the input array is in range [1, 10,000].
    The input array may contain duplicates, so ascending order here means <=.
*/