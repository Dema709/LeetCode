#include "test_runner.h"
#include "profile.h"
//#include <algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height){
		//Подсмотренное решение из интернета
		//Возможность нахождения воды в точке определяется максимумами слева и справа
		//8ms (93%)
		if (height.size()<3) return 0;
		int answer = 0;
		auto it_lhs = height.begin(), it_rhs = prev(height.end());
		int max_lhs = *it_lhs, max_rhs = *it_rhs;
		while (it_lhs<it_rhs){
			//cout<<'['<<it_lhs-height.begin()<<' '<<it_rhs-height.begin()<<"] "<<*it_lhs <<" "<< *it_rhs<<endl;
			if (*it_lhs < *it_rhs){
				if (*it_lhs < max_lhs)
					answer += max_lhs - *it_lhs;
				else
					max_lhs = *it_lhs;
				it_lhs++;
			} else {
				if (*it_rhs < max_rhs){
					answer += max_rhs - *it_rhs;
					//cout<<"answer "<<answer<<endl;
				}
				else
					max_rhs = *it_rhs;
				it_rhs--;
			}
		}
		
		return answer;
		/*
		//76ms (0%)
		if (height.size()<3) return 0;
		
		int answer = 0, minimum;
		int idx_left = 0, idx_right;
		while (true){
			idx_left   = find_local_max_left (height, idx_left); //cout<<"idx_left "<<idx_left<<endl;
			if (idx_left == -1) return answer;
			idx_right =  find_local_max_right(height, idx_left); //cout<<"idx_right "<<idx_right<<endl;
			if (idx_right == -1) return answer;
			minimum = min(height[idx_left],height[idx_right]);
			int delta=0;
			for (int i=idx_left+1; i<idx_right; i++){
				if (height[i]<minimum){
					delta+=minimum-height[i];
					height[i]=minimum;//cout<<'i'<<i<<endl;
				}
			}
			answer+=delta;
			//cout<<"delta "<<delta<<endl;cout<<height<<endl;//cout<<"answer "<<answer<<endl;
			
			
			while (true){
				idx_right =  find_local_max_right(height, idx_right-1); //cout<<"idx_right "<<idx_right<<endl;
				if (idx_right == -1) break;
				minimum = min(height[idx_left],height[idx_right]);
				int delta=0;
				for (int i=idx_left+1; i<idx_right; i++){
					if (height[i]<minimum){
						delta+=minimum-height[i];
						height[i]=minimum;//cout<<'i'<<i<<endl;
					}
				}
				if (delta==0) break;
				answer+=delta;
				//cout<<"delta "<<delta<<endl;cout<<height<<endl;//cout<<"answer "<<answer<<endl;
			}
			idx_left++;
		}
		
		return answer;
		*/
	}
private:
	int find_local_max_left(vector<int>& height, int start_idx){
		//Возвращает индекс элемента, который может быть левой границей "держателя воды"
		for (/*int i=start_idx*/; start_idx<height.size()-1; start_idx++){
			//Проверка всех значений кроме предпоследнего
			if (height[start_idx]>height[start_idx+1])
				return start_idx;
		}
		return -1;
	}
	int find_local_max_right(vector<int>& height, int left_idx){
		//Возвращает индекс элемента, который может быть правой границей "держателя воды"
		for (int end_idx = left_idx+2; end_idx<height.size()-1; end_idx++){
			if (height[end_idx]>height[end_idx-1])
				return end_idx;
		}
		//Проверка последнего значения
		if (height[height.size()-1] >= height[height.size()-2]) return height.size()-1;
		return -1;
	}
};

int main() {
	
	{
		vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
		int answer = 6;
		auto real_answer = Solution().trap(input);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> input = {2,0,2};
		int answer = 2;
		auto real_answer = Solution().trap(input);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> input = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
		int answer = 83;
		auto real_answer = Solution().trap(input);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> input = {};
		int answer = 0;
		auto real_answer = Solution().trap(input);
		//cout<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/