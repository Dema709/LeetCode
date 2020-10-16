#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity){
		//16ms(98%), 9.7MB(88%) Вариант через вектор лучше, так как 0 <= trips[i][1] < trips[i][2] <= 1000, 
		//т.е. километры посадки и высадки - малые числа по сравнению с количеством поездок
		vector<int> delta_persons_over_kilometers(1001);
		for (vector<int> & v : trips){
			delta_persons_over_kilometers[v[1]] += v[0];
			delta_persons_over_kilometers[v[2]] -= v[0];
		}
		
		int num_passengers = 0;
		for (auto delta : delta_persons_over_kilometers){
			num_passengers += delta;
			if (num_passengers>capacity) return false;
		}
		
		/*
		//80ms(7%), 9.9MB(62%)
		//Допустим, поездки отсортированы по начальному километражу, т.е. по второй цифре вектора 
		sort(trips.begin(), trips.end(), [](vector<int> & lhs, vector<int> & rhs){return lhs[1]<rhs[1];});
		
		vector<vector<int>> current_trips;//Где высадить и сколько человек
		for (vector<int> & v : trips){
			int current_distance = v[1];
			auto it = remove_if(current_trips.begin(), current_trips.end(), [current_distance](vector<int> & lhs){return lhs[0]<=current_distance;});
			current_trips.erase(it, current_trips.end());
			int current_persons = 0;
			for (auto & i : current_trips){
				current_persons += i[1];
			}
			if (v[0]+current_persons>capacity) return false;
			current_trips.push_back({v[2], v[0]});
		}
		//cout<<current_trips<<endl;
		//current_trips.erase(0);
		//cout<<trips<<endl;
		*/
		return true;
	}
};

int main() {
	
	{
		vector<vector<int>> trips = {{3,2,7},{3,7,9},{8,3,9}};
		int capacity = 11;
		bool answer = true;
		auto real_answer = Solution().carPooling(trips, capacity);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<vector<int>> trips = {{2,1,5},{3,5,7}};
		int capacity = 3;
		bool answer = true;
		auto real_answer = Solution().carPooling(trips, capacity);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<vector<int>> trips = {{2,1,5},{3,3,7}};
		int capacity = 5;
		bool answer = true;
		auto real_answer = Solution().carPooling(trips, capacity);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<vector<int>> trips = {{2,1,5},{3,3,7}};
		int capacity = 4;
		bool answer = false;
		auto real_answer = Solution().carPooling(trips, capacity);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Car Pooling
You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)
Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up,
and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.
Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

Example 1:
Input: trips = {{2,1,5},{3,3,7}}, capacity = 4
Output: false

Example 2:
Input: trips = {{2,1,5},{3,3,7}}, capacity = 5
Output: true

Example 3:
Input: trips = {{2,1,5},{3,5,7}}, capacity = 3
Output: true

Example 4:
Input: trips = {{3,2,7},{3,7,9},{8,3,9}}, capacity = 11
Output: true

Constraints:
trips.length <= 1000
trips[i].length == 3
1 <= trips[i][0] <= 100
0 <= trips[i][1] < trips[i][2] <= 1000
1 <= capacity <= 100000
*/