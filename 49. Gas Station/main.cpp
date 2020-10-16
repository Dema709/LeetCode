#include "test_runner.h"
#include "profile.h"
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
		//Интернет решение
		//Если можно за круг заправиться на больший объём, чем тратится, значит решение существует.
		//Если баланс меньше нуля, значит, что эта точка - не ответ; надо пробовать следующую,
		//обнулив перед этим баланс (бак)
		
		//Runtime: 12 - 16 ms, faster than 66.43% - 35.33% of C++ online submissions for Gas Station.
		//Memory Usage: 9.8 MB - 10 MB, less than 23.59% - 90.57% of C++ online submissions for Gas Station.
		int sum=0; // to calc intermediate solution
        int res=0; // to point to starting point if exist
        int total=0; // count the remaining gas to be at the of the trip
        for(int i=0;i<cost.size();i++) {
            sum+=(gas[i]-cost[i]);
            total+=(gas[i]-cost[i]);
            if(sum<0) {
                res=i+1;
                sum=0;
            }
        }
        return total<0?-1:res;
		
		/*
		//Runtime: 540-670 ms (0%)	Memory Usage: 9.8-9.9 MB (57-83%)
		for (int i=0; i<gas.size(); i++){
			if (gas[i] - cost[i] >= 0){
				bool route_ok = true;
				int tank = 0;
				tank += gas[i] - cost[i];
				for (int j=1; j<gas.size(); j++){
					tank += gas[(i+j)%gas.size()] - cost[(i+j)%gas.size()];
					if (tank<0){
						route_ok = false; break;
					}
				}
				if (route_ok){
					return i;
				}
			}
		}
		return -1;
		*/
		
		/*
		//Runtime: 828-884 ms (0%)	Memory Usage: 9.8-9.9 MB (57-83%)
		for (int i=0; i<gas.size(); i++){
			int tank = 0;
			bool route_ok = true;
			for (int j=0; j<gas.size(); j++){
				tank += gas[(i+j)%gas.size()] - cost[(i+j)%gas.size()];
				if (tank<0){
					route_ok = false; break;
				}
			}
			if (route_ok){
				return i;
			}
		}
		return -1;
		*/
	}
};

int main() {
	
	{
		vector<int> gas  = {1,2,3,4,5};
		vector<int> cost = {3,4,5,1,2};
		int answer = 3;
		auto real_answer = Solution().canCompleteCircuit(gas, cost);
		//cout<<real_answer<<" "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> gas  = {2,3,4};
		vector<int> cost = {3,4,3};
		int answer = -1;
		auto real_answer = Solution().canCompleteCircuit(gas, cost);
		//cout<<real_answer<<" "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Gas Station

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once in the clockwise
direction, otherwise return -1.

Note:
    If there exists a solution, it is guaranteed to be unique.
    Both input arrays are non-empty and have the same length.
    Each element in the input arrays is a non-negative integer.

Example 1:
Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:
Input: 
gas  = [2,3,4]
cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
*/