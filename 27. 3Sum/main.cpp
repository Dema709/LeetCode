#include "test_runner.h"
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums){
		if (nums.size()<3) return {};
		
		sort(nums.begin(), nums.end());
		vector<vector<int>> answer;
		auto it_i = nums.begin();
		while (it_i<prev(nums.end(),2)){
			auto it_j = next(it_i);
			auto it_end = nums.end();
			
			while (it_j<prev(it_end)){
				//Медленная часть кода, кажется. Можно переделать через номера индексов и без lower_bound, тогда будет быстрее
				it_end = lower_bound(next(it_j), it_end, -*it_i -*it_j);
				
				//cout<<"searching for "<<-*it_i -*it_j<<" -> ";
				//cout<<it_i-nums.begin()<<' '<<it_j-nums.begin()<<' '<<it_end-nums.begin()<<endl;
				if (it_end!=nums.end()){
					if (*it_i+*it_j+*it_end == 0){
						answer.push_back({*it_i, *it_j, *it_end});
					}
				}
				
				//it_j=upper_bound(it_j, nums.end(), *it_j);
				//Замена строчки сверху (так быстрее):
				while (it_j<prev(nums.end())){
					it_j=next(it_j);
					if (*it_j!=*prev(it_j)){
						break;
					}
				}
			}
			
			//it_i=upper_bound(it_i, nums.end(), *it_i);
			//Замена строчки сверху (так быстрее):
			while (it_i<prev(nums.end())){
				it_i=next(it_i);
				if (*it_i!=*prev(it_i)){
					break;
				}
			}
		}
		return answer;
	}
};


int main() {
	
	{
		vector<int> input = {-1,0,1,2,-1,-4};
		vector<vector<int>> answer = {{-1,-1,2},{-1,0,1}};
		vector<vector<int>> real_answer = Solution().threeSum(input);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		vector<int> input = {};
		vector<vector<int>> answer = {};
		vector<vector<int>> real_answer = Solution().threeSum(input);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		vector<int> input = {0};
		vector<vector<int>> answer = {};
		vector<vector<int>> real_answer = Solution().threeSum(input);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		vector<int> input = {0,0,0};
		vector<vector<int>> answer = {{0,0,0}};
		vector<vector<int>> real_answer = Solution().threeSum(input);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		vector<int> input = {1,-1,-1,0};
		vector<vector<int>> answer = {{-1,0,1}};
		vector<vector<int>> real_answer = Solution().threeSum(input);
		//cout<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		vector<int> input = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
		vector<vector<int>> answer = {{-4,0,4},{-4,1,3},{-3,-1,4},{-3,0,3},{-3,1,2},{-2,-1,3},{-2,0,2},{-1,-1,2},{-1,0,1}};
		vector<vector<int>> real_answer = Solution().threeSum(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []

Constraints:
0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/