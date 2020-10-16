#include "test_runner.h"
#include <unordered_set>

using namespace std;

class Solution  {
public:
	int singleNumber(vector<int>& nums){
		//Решение в лоб:
		return singleNumber_noBrain(nums);
		
	}
private:
	int singleNumber_noBrain(vector<int>& nums){
		unordered_set<int> s;
		for (const int & n : nums){
			
			//cout<<"set before "<<n<<": ";	for (int n: s){				cout<<n<<' ';			}	cout<<endl;
			if (s.count(n)){
				s.erase(n);
			} else {
				s.insert(n);
			}

			//cout<<"set after  "<<n<<": ";	for (int n: s){				cout<<n<<' ';			}	cout<<endl;
			
			
		}
		
		
		
		return *s.begin();
	}
};


int main() {
	
	{
		vector<int> v = {2,2,1};
		int answer = 1;
		Solution().singleNumber(v);
		ASSERT_EQUAL(Solution().singleNumber(v), answer);
	}

	{
		vector<int> v = {4,1,2,1,2};
		int answer = 4;
		Solution().singleNumber(v);
		ASSERT_EQUAL(Solution().singleNumber(v), answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Single Number

Solution
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4
*/