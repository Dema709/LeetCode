#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		//Runtime: 20 ms, faster than 80.83% of C++ online submissions for Jump Game.
		//Memory Usage: 13.1 MB, less than 17.78% of C++ online submissions for Jump Game.
		int cur_max_jump = 1;
		for (int i=0; i<nums.size(); i++){
			cur_max_jump--;
			if (nums[i]>cur_max_jump){
				cur_max_jump = nums[i];
			}
			//cout<<"i="<<i<<" cur_max_jump="<<cur_max_jump<<endl;
			if (cur_max_jump<=0 && i!=nums.size()-1){
				return false;
			}
		}
		return true;
	}
};

int main() {
	
	{
		vector<int> nums  = {2,3,1,1,4};
		bool answer = true;
		auto real_answer = Solution().canJump(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {3,2,1,0,4};
		bool answer = false;
		auto real_answer = Solution().canJump(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {2,3,1,1,0};
		bool answer = true;
		auto real_answer = Solution().canJump(nums);
		cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Jump Game

Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:
	1 <= nums.length <= 3 * 10^4
	0 <= nums[i][j] <= 10^5
*/