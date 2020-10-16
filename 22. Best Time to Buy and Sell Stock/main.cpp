#include "test_runner.h"

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices){
		if (prices.size() ==0 ) return 0;
		int localMin = prices[0];
		int maxProfitCount = 0;
		for (auto & t : prices){
			if (t - localMin > maxProfitCount){
				maxProfitCount = t - localMin;
			}
			if (t < localMin){
				localMin = t;
			}
		}
		return maxProfitCount;
	}
};


int main() {
	
	
	
	{
		vector<int> v = {7,1,5,3,6,4};
		int answer = 5;
		int real_answer = Solution().maxProfit(v);
		//cout<<v<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		vector<int> v = {7,6,4,3,1};
		int answer = 0;
		int real_answer = Solution().maxProfit(v);
		//cout<<v<<' '<<real_answer<<' '<<answer<<endl<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
			 
Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/