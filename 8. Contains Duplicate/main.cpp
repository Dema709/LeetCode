#include "test_runner.h"
#include <unordered_set>

using namespace std;

class Solution  {
public:
	bool containsDuplicate(vector<int> & nums){
		for (const int & n : nums){
			if (s.count(n)){
				return true;
			} else {
				s.insert(n);
			}
		}
		return false;//Заглушка
	}
private:
	unordered_set<int> s;
};


int main() {
	
	{
		vector<int> v = {1,2,3,1};
		ASSERT(Solution().containsDuplicate(v));
	}
	
	{
		vector<int> v = {1,2,3,4};
		ASSERT(!Solution().containsDuplicate(v));
	}
	
	{
		vector<int> v = {1,1,1,3,3,4,3,2,4,2};
		ASSERT(Solution().containsDuplicate(v));
	}
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Contains Duplicate

Solution
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/