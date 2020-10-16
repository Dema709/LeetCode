#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
		//Первый вариант с итераторами:					44ms, 89MB
		//Второй вариант с объединением и сортировкой:	52ms, 89.4MB
		
		if (true){
			if (nums1.empty()){
				if (nums2.size()%2){//Нечет
					return nums2[nums2.size()/2];
				} else {//Чёт
					return (nums2[nums2.size()/2]+nums2[nums2.size()/2-1])/2.0;
				}
			}
			if (nums2.empty()){
				if (nums1.size()%2){//Нечет
					return nums1[nums1.size()/2];
				} else {//Чёт
					return (nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2.0;
				}
			}
			//Работаем с непустыми массивами
			auto it1=nums1.begin(), it2=nums1.end(), it3=nums2.begin(), it4=nums2.end();
			int minimum, maximum;
			while (true){
				//cout<<"(it1==it2) (it3==it4) "<<(it1==it2)<<' '<<(it3==it4)<<endl;
				if (it1==it2){
					//Первый массив закончился
					if (it3==it4){
						//И второй тоже
						//cout<<"returning?"<<endl;
						return (minimum+maximum)/2.0;
					} else {
						minimum=*it3;
						it3=next(it3);
					}
				} else {
					if (it3==it4){
						//Закончился только второй массив
						minimum=*it1;
						it1=next(it1);
					} else {
						//Есть два доступных массивами
						if (*it1<*it3){
							minimum=*it1;
							it1=next(it1);
						} else {
							minimum=*it3;
							it3=next(it3);
						}
					}
				}
				//cout<<"minimum "<<minimum<<endl;
				
				//cout<<"(it1==it2) (it3==it4) "<<(it1==it2)<<' '<<(it3==it4)<<endl;
				if (it1==it2){
					//Первый массив закончился
					if (it3==it4){
						//И второй тоже
						return minimum;
					} else {
						maximum=*prev(it4);
						it4=prev(it4);
					}
				} else {
					if (it3==it4){
						maximum=*prev(it2);
						it2=prev(it2);
					} else {
						if (*prev(it2)<*prev(it4)){
							maximum=*prev(it4);
							it4=prev(it4);
						} else {
							maximum=*prev(it2);
							it2=prev(it2);
						}
					}
				}
				//cout<<"maximum "<<maximum<<endl;
			}
		}
		else {
			nums1.insert(nums1.end(), nums2.begin(), nums2.end());
			sort(nums1.begin(), nums1.end());
			if (nums1.size()%2){//Нечет
				return nums1[nums1.size()/2];
			} else {//Чёт
				return (nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2.0;
			}
		}
	}
};

int main() {
	
	{
		vector<int> nums1 = {1,3};
		vector<int> nums2 = {2};
		double answer = 2;
		auto real_answer = Solution().findMedianSortedArrays(nums1, nums2);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums1 = {1,2};
		vector<int> nums2 = {3,4};
		double answer = 2.5;
		auto real_answer = Solution().findMedianSortedArrays(nums1, nums2);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums1 = {0,0};
		vector<int> nums2 = {0,0};
		double answer = 0;
		auto real_answer = Solution().findMedianSortedArrays(nums1, nums2);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums1 = {};
		vector<int> nums2 = {1};
		double answer = 1;
		auto real_answer = Solution().findMedianSortedArrays(nums1, nums2);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums1 = {2};
		vector<int> nums2 = {};
		double answer = 2;
		auto real_answer = Solution().findMedianSortedArrays(nums1, nums2);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
Follow up: The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:
Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:
Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:
Input: nums1 = [2], nums2 = []
Output: 2.00000
 
Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/