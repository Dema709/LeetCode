#include "test_runner.h"
#include <algorithm>

using namespace std;

class Solution  {
public:
	vector<int> twoSum(vector<int>& nums, int target){
		/*
		//Вариант с тупым перебором
		//Вариант с поиском по минимуму и максимуму
		*/
		
		//Вариант с копированием и сортировкой вектора, убрал пару итераторов и вывод в поток
		vector<int> nums_copy = nums;
		sort(nums_copy.begin(), nums_copy.end());
		auto it_end = nums_copy.end();
		auto it_find = nums_copy.begin();
		while (true){
			it_find = lower_bound(it_find, it_end, target - *prev(it_end));
			if (*prev(it_end) + *it_find == target){
				//cout<<"match found: "<<*prev(it_end)<<' '<<*it_find<<endl;
				it_find = find(nums.begin(),nums.end(),*it_find);
				if (*prev(it_end)==*it_find){//Два числа равны
					it_end = find(next(it_find),nums.end(),*it_find);
					return {static_cast<int>(distance(nums.begin(),it_find)), static_cast<int>(distance(nums.begin(),it_end))};
				} else {
					it_end = find(nums.begin(),nums.end(),*prev(it_end));
					return {static_cast<int>(distance(nums.begin(),it_find)), static_cast<int>(distance(nums.begin(),it_end))};
				}
				//static_cast<int>(distance(nums.begin(),...));
			} else {
				it_end = prev(it_end);
			}
			
		}
	}
};


int main() {
	
	{
		vector<int> v  = {2, 7, 11, 15};
		int target = 9;
		vector<int> v2 = {0,1};
		//cout<<Solution().twoSum(v, target)<<' '<<v2<<endl;;
		ASSERT_EQUAL(Solution().twoSum(v, target), v2);
	}
	
	
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/