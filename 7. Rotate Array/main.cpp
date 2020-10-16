#include "test_runner.h"

using namespace std;

class Solution  {
public:
	void rotate(vector<int> & nums, int k_){
		size = nums.size();
		if (size<2) return;
		k = k_;
		k = k%size;
		if (k==0) return;
		int Delitel = minimalDecimator();
		if (Delitel != 1){
			//cout<<"Interesting case!"<<endl;
			
			for (int i=0;i<Delitel;i++){
				int pointer = i;
				int temp = nums[i];
				for (int j=0;j<size/Delitel-1;j++){
					nums[pointer] = nums[toOld(pointer)];
					pointer = toOld(pointer);
				}
				nums[toNew(i)]=temp;
			}
			
			
		} else {
			int temp = nums[0];
			int pointer = 0;
			for (int i=0;i<size-1;i++){
				//cout<<"changing N"<<i<<": "<<pointer<<' '<<toOld(pointer)<<endl;
				nums[pointer] = nums[toOld(pointer)];
				pointer = toOld(pointer);
			}
			nums[toNew(0)]=temp;
		}
			
		
	}
	
private:
	int toNew(int oldNum){
		return (oldNum+k)%size;
	}
	int toOld(int newNum){
		return (newNum+size-k)%size;
	}
	int minimalDecimator(){
		//Минимальный общий делитель по алгоритму Евклида
		int a = size;
		int b = k;
		
		while (a>0 && b>0){
			if (a>b){
				a%=b;
			} else {
				b%=a;
			}
		}
		return a+b;
	}
	
	size_t size;
	int k;
};


int main() {
	
	{
		vector<int> v = {1,2,3,4,5,6,7};
		int k = 3;
		vector<int> answer = {5,6,7,1,2,3,4};
		Solution().rotate(v,k);
		ASSERT_EQUAL(v,answer);
	}
	
	{
		vector<int> v = {-1,-100,3,99};
		int k = 2;
		vector<int> answer = {3,99,-1,-100};
		Solution().rotate(v,k);
		ASSERT_EQUAL(v,answer);
	}
	
	{
		vector<int> v = {1,2};
		int k = 0;
		vector<int> answer = {1,2};
		Solution().rotate(v,k);
		ASSERT_EQUAL(v,answer);
	}

	{
		vector<int> v = {1,2,3,4,5,6};
		int k = 4;
		vector<int> answer = {3,4,5,6,1,2};
		Solution().rotate(v,k);
		ASSERT_EQUAL(v,answer);
	}
	
	{
		vector<int> v = {0,1,2,3,4,5,6,7,8,9};
		int k = 5;
		vector<int> answer = {5,6,7,8,9,0,1,2,3,4};
		Solution().rotate(v,k);
		ASSERT_EQUAL(v,answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Rotate Array

Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 
Constraints:

1 <= nums.length <= 2 * 10^4
It's guaranteed that nums[i] fits in a 32 bit-signed integer.
k >= 0


*/