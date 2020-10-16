#include "test_runner.h"
#include <iostream>
#include <vector>
#include <cmath>	//pow()
using namespace std;

class Solution {
public:
	vector<int> numsSameConsecDiff(int N, int K){
		vector<int> result;
		vector<int> tempResult;
		
		if (N==1){
			result.push_back(0);
		}
		
		for (int i=1;i<10;i++){
			tempResult = generateNextStep(N,K,i);
			for (int t : tempResult){
				result.push_back(t);
			}
			
			//cout<<i<<endl;
		}
		
		
		return result;
	}
private:

	vector<int> generateNextStep(int currentN, int deltaK, int currentInt){
		vector<int> result;
		
		if (currentN == 1){
			result.push_back(currentInt);
			return result;
		}
			
		
		vector<int> tempResult1;
		vector<int> tempResult2;
		//cout<<"currentInt+-deltaK "<<currentInt-deltaK<<' '<<currentInt+deltaK<<' '<<(currentInt-deltaK>=0)<<' '<<(currentInt+deltaK<=9)<<endl;
		if (currentInt-deltaK>=0){
			tempResult1 = generateNextStep(currentN-1, deltaK, currentInt-deltaK);
		}
		if (deltaK!=0){
			if (currentInt+deltaK<=9){
				tempResult2 = generateNextStep(currentN-1, deltaK, currentInt+deltaK);
			}
		}
		int multiplier = pow(10,currentN-1);
		
		//cout<<"tempResult1 "<<tempResult1<<endl;
		//cout<<"tempResult2 "<<tempResult2<<endl;
		
		for (int t : tempResult1){
			result.push_back(currentInt*multiplier+t);
		}
		for (int t : tempResult2){
			result.push_back(currentInt*multiplier+t);
		}
		
		return result;
	}
};


int main() {
	
	{
		vector<int> v = {181,292,707,818,929};
		ASSERT_EQUAL(v, Solution().numsSameConsecDiff(3,7))
	}
	
	{
		vector<int> v = {10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98};
		ASSERT_EQUAL(v, Solution().numsSameConsecDiff(2,1))
	}
	
	{
		vector<int> v = {0,1,2,3,4,5,6,7,8,9};
		ASSERT_EQUAL(v, Solution().numsSameConsecDiff(1,0))
	}
	
	{
		vector<int> v = {11,22,33,44,55,66,77,88,99};
		ASSERT_EQUAL(v, Solution().numsSameConsecDiff(2,0))
	}
	
	//cout<<Solution().generateNextStep(3,1,7)<<endl;
	//cout<<Solution().numsSameConsecDiff(3,7);
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Numbers With Same Consecutive Differences

Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.
Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.
You may return the answer in any order.

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

Note:
1 <= N <= 9
0 <= K <= 9
*/