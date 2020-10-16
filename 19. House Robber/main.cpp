#include "test_runner.h"

using namespace std;

class Solution  {
public:
	int rob(vector<int>& nums){
		if (nums.empty()) return 0;
		{
			int if_rob, if_not_rob, if_not_rob_twice;
			int if_rob_prev=0, if_not_rob_prev=0, if_not_rob_twice_prev=0;
			for (int i=0;i<nums.size();i++){
				if_rob = max(if_not_rob_prev, if_not_rob_twice_prev) + nums[i];
				if_not_rob = if_rob_prev;
				if_not_rob_twice = if_not_rob_prev;
				//cout<<if_rob<<' '<<if_not_rob<<' '<<if_not_rob_twice<<endl;
				if_rob_prev = if_rob;//swap(if_rob, if_rob_prev);
				if_not_rob_prev = if_not_rob;//swap(if_not_rob, if_not_rob_twice);
				if_not_rob_twice_prev = if_not_rob_twice;//swap(if_not_rob_prev, if_not_rob_twice_prev);
			}
			return max(if_rob,if_not_rob);
			//cout<<"Alg1_end"<<endl;
		}
		
		/*
		//Излишнее выделение памяти
		{
			vector<int> if_rob, if_not_rob, if_not_rob_twice;
			//Нет смысла пропускать три дома подряд
			for (int i=0;i<nums.size();i++){
				if (i==0){
					if_rob.push_back(nums[i]);
					if_not_rob.push_back(0);
					if_not_rob_twice.push_back(0);
				} else {
					if_rob.push_back(max(if_not_rob[i-1],if_not_rob_twice[i-1])+nums[i]);
					if_not_rob.push_back(if_rob[i-1]);
					if_not_rob_twice.push_back(if_not_rob[i-1]);
				}
			}
			//cout<<if_rob<<endl<<if_not_rob<<endl<<if_not_rob_twice<<endl;cout<<"Alg2_end"<<endl;
			return max(if_rob[if_rob.size()-1],if_not_rob[if_not_rob.size()-1]);//Заглушка
		}
		*/

	}
};


int main() {
	
	{
		vector<int> v = {1,2,3,1};
		int real_answer = 4;
		int answer = Solution().rob(v);
		//cout<<"Answer: "<<answer<<" ("<<real_answer<<')'<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}

	{
		vector<int> v = {2,7,9,3,1};
		int real_answer = 12;
		int answer = Solution().rob(v);
		//cout<<"Answer: "<<answer<<" ("<<real_answer<<')'<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		vector<int> v = {6, 100, 7, 8, 100, 1};
		int real_answer = 200;
		int answer = Solution().rob(v);
		//cout<<"Answer: "<<answer<<" ("<<real_answer<<')'<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		vector<int> v = {};
		int real_answer = 0;
		int answer = Solution().rob(v);
		//cout<<"Answer: "<<answer<<" ("<<real_answer<<')'<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it
will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
money you can rob tonight without alerting the police.
 
Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
			 
Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 400
*/