#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	//Лучше 98.9% по времени и 97.8% по памяти ;p
	int coinChange(vector<int> & coins, int amount){
		if (amount < 0 || coins.empty()) return -1;
		sort(coins.begin(), coins.end());
		
		coinChange(coins, amount, 0, coins.size());
		if (coins_count!=INT_MAX)
			return coins_count;
		else
			return -1;
		//return -1;//Заглушка
	}
private:
	void coinChange(vector<int> & coins, int amount, int coins_used, int current_coins_left/*Количество видов монет, которые можно использовать*/){
		if (current_coins_left==1){
			if (amount%coins[0] == 0){
				if (amount/coins[0] + coins_used < coins_count){
					coins_count = amount/coins[0]+coins_used;
				}
			}
			return;
		}
		current_coins_left--;
		
		int max_count_of_this_coins = amount/coins[current_coins_left];
		//int answer;// = -1;
		for (int i=0; i<max_count_of_this_coins+1; i++){
			//Используем max_count_of_this_coins-i монет
			if (coins_count!=INT_MAX){//Если решение уже есть и оно лучше текущего
				if (max_count_of_this_coins-i+coins_used > coins_count){
					return;
				}
			}
			coinChange(coins, amount - (max_count_of_this_coins-i)*coins[current_coins_left], max_count_of_this_coins-i+coins_used, current_coins_left);
			//if (answer != -1) return answer + (max_count_of_this_coins-i);
		}
		
		//return -1;
	}
int coins_count = INT_MAX;
};

int main() {
	
	{
		vector<int> coins = {1, 2, 5};
		int amount = 11;
		int answer = 3;
		auto real_answer = Solution().coinChange(coins, amount);
		cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> coins = {2};
		int amount = 3;
		int answer = -1;
		auto real_answer = Solution().coinChange(coins, amount);
		cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> coins = {1, 2, 5, 10, 50, 100};
		int amount = 575;
		int answer = 5+1+2+1;
		auto real_answer = Solution().coinChange(coins, amount);
		cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> coins = {1};
		int amount = 0;
		int answer = 0;
		auto real_answer = Solution().coinChange(coins, amount);
		cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> coins = {186, 419, 83, 408};
		int amount = 6249;
		int answer = 20;
		auto real_answer = Solution().coinChange(coins, amount);
		cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> coins = {288,160,10,249,40,77,314,429};
		int amount = 9208;
		int answer = 22;
		LOG_DURATION("Test 114");//4534ms
		auto real_answer = Solution().coinChange(coins, amount);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		//ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins
that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.
*/