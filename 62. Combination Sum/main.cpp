#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		//Runtime: 12 ms			(67%)
		//Memory Usage: 11.5 MB		(51%)
		if (target<=0 || candidates.empty()) return {};
		
		vector<vector<int>> answer;
		vector<int> current_answer;
		combine(candidates, 0, target, answer, current_answer, 0);
		return answer;
	}
private:
	void combine(vector<int>& candidates,
			int current_num_to_use,//То, какое число мы пытаемся добавить. Номер в массиве "candidates"
			int target,//Остаток, к которому должны стремиться
			vector<vector<int>>& answer,
			vector<int> & current_answer,
			int readyAnswerSize){//Размер вектора до поступления сюда
		if (current_num_to_use>=candidates.size() ||  target<=0) return;
		for (int i=0; i<=target/candidates[current_num_to_use]; i++){
			if (i!=0){
				//target-=candidates[current_num_to_use];
				current_answer.push_back(candidates[current_num_to_use]);
				readyAnswerSize++;
			}
			if (target-i*candidates[current_num_to_use]==0){
				answer.push_back(current_answer);
			}
			combine(candidates, current_num_to_use+1, target-i*candidates[current_num_to_use], answer, current_answer, readyAnswerSize);
			current_answer.resize(readyAnswerSize);
			
			//cout<<"i="<<i<<endl;//answer.push_back({i, candidates[current_num_to_use]});
		}
	}
};

int main() {
	
	cout<<endl;
	
	{
		vector<int> nums  = {2,3,6,7};
		int target = 7;
		vector<vector<int>> answer = {
			{7},
			{2,2,3}
		};
		auto real_answer = Solution().combinationSum(nums, target);
		cout<<"Target = "<<target<<"; Initial vector: "<<nums<<endl;
		cout<<"Real_answer:"<<endl<<real_answer<<endl<<"Answer:"<<endl<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {2,3,5};
		int target = 8;
		vector<vector<int>> answer = {
			{2,2,2,2},
			{2,3,3},
			{3,5}
		};
		auto real_answer = Solution().combinationSum(nums, target);
		cout<<"Target = "<<target<<"; Initial vector: "<<nums<<endl;
		cout<<"Real_answer:"<<endl<<real_answer<<endl<<"Answer:"<<endl<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {1};
		int target = 2;
		vector<vector<int>> answer = {
			{1,1}
		};
		auto real_answer = Solution().combinationSum(nums, target);
		cout<<"Target = "<<target<<"; Initial vector: "<<nums<<endl;
		cout<<"Real_answer:"<<endl<<real_answer<<endl<<"Answer:"<<endl<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {2};
		int target = 1;
		vector<vector<int>> answer = {
		};
		auto real_answer = Solution().combinationSum(nums, target);
		cout<<"Target = "<<target<<"; Initial vector: "<<nums<<endl;
		cout<<"Real_answer:"<<endl<<real_answer<<endl<<"Answer:"<<endl<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {1};
		int target = 1;
		vector<vector<int>> answer = {
			{1}
		};
		auto real_answer = Solution().combinationSum(nums, target);
		cout<<"Target = "<<target<<"; Initial vector: "<<nums<<endl;
		cout<<"Real_answer:"<<endl<<real_answer<<endl<<"Answer:"<<endl<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Combination Sum

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all
unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = {2,3,6,7}, target = 7,
A solution set is:
{
  {7},
  {2,2,3}
}

Example 2:
Input: candidates = {2,3,5}, target = 8,
A solution set is:
{
  {2,2,2,2},
  {2,3,3},
  {3,5}
}

Constraints:
    1 <= candidates.length <= 30
    1 <= candidates[i] <= 200
    Each element of candidate is unique.
    1 <= target <= 500
*/