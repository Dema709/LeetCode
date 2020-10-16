#include "test_runner.h"
#include "profile.h"

using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums){
		//Не обязательно подряд!
		if (nums.size()<3) return false;
		int minimum_triplet_start_non_increasing = nums[0];
		bool minimum_triplet_start_increasing_found = false;
		int minimum_triplet_start_increasing;
		int minimum_triplet_second;
		
		
		
		bool prev_triplet_increasing = nums[1]>nums[0];
		for (int i=1; i<nums.size(); i++){
			/*cout<<"i = "<<i<<" and min = "<<minimum_triplet_start_non_increasing;
			if (minimum_triplet_start_increasing_found){cout<<"; increasing found: "<<minimum_triplet_start_increasing<<"->"<<minimum_triplet_second;}
			cout<<endl;*/
			
			if (minimum_triplet_start_increasing_found){
				if (nums[i]>minimum_triplet_second){
					return true;
				}
				if (nums[i]>minimum_triplet_start_non_increasing){
					minimum_triplet_start_increasing = minimum_triplet_start_non_increasing;
					minimum_triplet_second = nums[i];
					
				}
				else if (nums[i]<minimum_triplet_second && nums[i]>minimum_triplet_start_increasing){
					minimum_triplet_second = nums[i];
					//cout<<"minimum_triplet_second = nums[i] = "<<nums[i]<<endl;
				}
			} else {
				if (nums[i]>minimum_triplet_start_non_increasing){
					minimum_triplet_start_increasing_found = true;
					minimum_triplet_second = nums[i];
					minimum_triplet_start_increasing = minimum_triplet_start_non_increasing;
				}
			}
			if (nums[i]<minimum_triplet_start_non_increasing){
				minimum_triplet_start_non_increasing = nums[i];
			}
			
			
			
		}
		return false;
	}
};

int main() {
	
	{
		vector<int> input = {1,2,3,4,5};
		bool answer = true;
		bool real_answer = Solution().increasingTriplet(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> input = {5,4,3,2,1};
		bool answer = false;
		bool real_answer = Solution().increasingTriplet(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> input = {5,1,5,5,2,5,4};
		bool answer = true;
		bool real_answer = Solution().increasingTriplet(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> input = {1,2,-10,-8,-7};
		bool answer = true;
		bool real_answer = Solution().increasingTriplet(input);
		//cout<<real_answer<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:
Input: [1,2,3,4,5]
Output: true

Example 2:
Input: [5,4,3,2,1]
Output: false
*/