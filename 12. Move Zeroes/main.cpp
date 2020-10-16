#include "test_runner.h"
using namespace std;

class Solution  {
public:
	void moveZeroes(vector<int>& nums){
		int total_notZero_count = 0;
		for (int i=0;i<nums.size();i++){
			if (nums[i]!=0){
				nums[total_notZero_count] = nums[i];
				total_notZero_count++;
			}
		}
		
		for (int i=total_notZero_count;i<nums.size();i++){
			nums[i]=0;
		}
		
	}
};


int main() {
	
	{
		vector<int> v  = {0,1,0,3,12};
		vector<int> v2 = {1,3,12,0,0};
		Solution().moveZeroes(v);
		ASSERT_EQUAL(v, v2);
	}
	
	
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/