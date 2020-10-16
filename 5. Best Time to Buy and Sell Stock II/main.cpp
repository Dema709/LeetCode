#include "test_runner.h"
//#include <iostream>

using namespace std;

class Solution  {
public:
	int maxProfit(vector<int>& prices) {
		size_t number = 0;
		int sum;
		while (number!=prices.size()-1){
			sum += find_next_transaction(prices, number);
		}
		return sum;
	}
private:
	int find_next_transaction(vector<int>& prices, size_t & number){
		
		if (const auto min_pos = find_new_minimum(prices,number)){
			//cout<<"min element index = ["<<*min_pos<<"] "<<prices[*min_pos]<<endl;
			//cout<<"maybe max element index = ["<<find_new_maximum(prices,*min_pos+1)<<"] "<<prices[find_new_maximum(prices,*min_pos+1)]<<endl;
			number = find_new_maximum(prices,*min_pos+1);//max_pos
			int delta = prices[number]-prices[*min_pos];
			if (delta>0){
				return delta;
			}
		}
		number = prices.size()-1;
		return 0;
	}
	optional<size_t> find_new_minimum(vector<int>& prices, size_t number){
		//Возвращает номер элемента локального минимума
		
		for (size_t i=number+1;i<prices.size();i++){
			//cout<<prices[i-1]<<' '<<prices[i]<<' '<<endl;
			if (prices[i-1]<prices[i]){
				return i-1;
			}
		}
		
		return nullopt;//заглушка
	}
	
	size_t find_new_maximum(vector<int>& prices, size_t number){
		//Возвращает номер элемента локального максимума
		
		for (size_t i=number+1;i<prices.size();i++){
			//cout<<prices[i-1]<<' '<<prices[i]<<' '<<endl;
			if (prices[i-1]>prices[i]){
				return i-1;
			}
		}
		
		return prices.size()-1;//заглушка
	}
};


int main() {
	
	{
		vector<int> v = {7,1,5,3,6,4};
		int answer = 7;
		ASSERT_EQUAL(Solution().maxProfit(v),answer);
	}
	
	{
		vector<int> v = {1,2,3,4,5};
		int answer = 4;
		ASSERT_EQUAL(Solution().maxProfit(v),answer);
	}
	
	{
		vector<int> v = {7,6,4,3,1};
		int answer = 0;
		ASSERT_EQUAL(Solution().maxProfit(v),answer);
	}
	
	{
		vector<int> v = {};
		int answer = 0;
		ASSERT_EQUAL(Solution().maxProfit(v),answer);
	}
	
	{
		vector<int> v = {7};
		int answer = 0;
		ASSERT_EQUAL(Solution().maxProfit(v),answer);
	}
	
	{
		vector<int> v = {7,1};
		int answer = 0;
		ASSERT_EQUAL(Solution().maxProfit(v),answer);
	}
	
	{
		vector<int> v = {1,7};
		int answer = 6;
		ASSERT_EQUAL(Solution().maxProfit(v),answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*		Словарик
Internally	-	изнутри (?)
*/

/*
Best Time to Buy and Sell Stock II

Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4
*/