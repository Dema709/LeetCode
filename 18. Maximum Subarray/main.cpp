#include "test_runner.h"
#include <algorithm>

using namespace std;

class Solution  {
public:
	int maxSubArray(vector<int>& nums){
		/*{
			auto it = max(nums.begin(),nums.end());
			if (*it<=0) return *it;
		}
		{
			if (nums.size()==1)
				return nums[0];
		}*/
		vector<int> mountains_and_lakes;
		int step = 0;
		while (true){
			if (step<nums.size()){
				mountains_and_lakes.push_back(find_lake(nums,step)); //cout<<"lake: "<<mountains_and_lakes[mountains_and_lakes.size()-1]<<endl;
			} else {
				break;
			}
			if (step<nums.size()){
				mountains_and_lakes.push_back(find_mountain(nums,step)); //cout<<"mountain: "<<mountains_and_lakes[mountains_and_lakes.size()-1]<<endl;
			} else {
				break;
			}
		}
		
		if (mountains_and_lakes.size()==1){
			//Все числа меньше нуля или равны ему
			cout<<"mountains_and_lakes.size()==1)"<<endl;
			auto it = max_element(nums.begin(),nums.end());
			return *it;
		}
		if (mountains_and_lakes.size()<4){
			//Есть только один островок с положительными числами
			cout<<"mountains_and_lakes.size()<4"<<endl;
			return mountains_and_lakes[1];
		}
		
		//Ну а дальше мы так просто не отделаемся
		//cout<<"mountains count:"<<mountains_and_lakes.size()/2<<endl;
		/*step=0;
		
		while (step<mountains_and_lakes.size()/2){
			cout<<mountains_and_lakes<<endl;
			try_unite(mountains_and_lakes, step);
			step++;
		}*/
		//cout<<"mountains_and_lakes: "<<mountains_and_lakes<<endl;
		return try_unite_and_return_max(mountains_and_lakes);//*max(mountains_and_lakes.begin(),mountains_and_lakes.end());
		
		//return 0;//заглушка
	}
private:
	int find_lake(vector<int>& nums, int& step){
		if (nums[step]>0) return 0;//Сразу гора
		int sum = 0;//Сумма элементов горы
		while (true){
			if (nums[step]>0){
				return sum;
			} else {
				sum+=nums[step];
			}
			step++; if (step == nums.size()) return sum;
		}
		return 0;//заглушка
	}
	int find_mountain(vector<int>& nums, int& step){
		if (nums[step]<0) return 0;//Сразу озеро
		int sum = 0;//Сумма элементов озера
		while (true){
			if (nums[step]<0){
				return sum;
			} else {
				sum+=nums[step];
			}
			step++; if (step == nums.size()) return sum;
		}
		return 0;//заглушка
	}
	int try_unite_and_return_max(vector<int>& nums){
		vector<int> maximums;
		//int maximums =;
		int slow_pointer = 1;
		while (true){
			//cout<<"no more, baby"<<endl;
			if (slow_pointer >= nums.size()) break;
			
			int max_sum = nums[slow_pointer], max_last_element = slow_pointer;
			int fast_pointer = slow_pointer, fast_max_sum = max_sum;
			while (true){
				fast_pointer += 2; if (fast_pointer >= nums.size()) break;
				fast_max_sum += nums[fast_pointer] + nums[fast_pointer-1];
				if (fast_max_sum >=  max_sum){
					max_sum = fast_max_sum;
					max_last_element = fast_pointer;
				}
			}
			
			maximums.push_back(max_sum);
			//slow_pointer = max_last_element;
			//cout<<"slow_pointer = "<<slow_pointer<<" and max_sum = "<<max_sum<<endl;
			slow_pointer += 2; 
			//break;
		}
		//cout<<"maximums="<<maximums<<endl;
		//cout<<"max="<<*max_element(maximums.begin(),maximums.end())<<endl;
		return *max_element(maximums.begin(),maximums.end());
		
		
		
		
		/*int sum_count = 0;//Количество просуммированных гор
		int sum = nums[1+step*2];//Сумма горы в итоге
		int temp_sum_count, temp_sum;//Для поиска. Не факт, что инициализировать это тут и этим!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		temp_sum_count = sum_count; temp_sum = sum;
		
		//Начинаем суммировать с горы под номером step, т.е. элемент 1+step*2
		while (true){
			if (step+sum_count == nums.size()/2){//Если нечего больше суммировать
				break;
			}
			//Если всё-таки есть, что суммировать
			//Стоит ли это делать?
			

			//Суммируем
			//Если итоговая сумма temp_sum больше чем sum, заменяем временные sum_count и sum на постоянные
			temp_sum += nums[1+step*2+temp_sum_count*2+1] + nums[1+step*2+temp_sum_count*2+2];
			temp_sum_count++;
			
			if (temp_sum>=sum){
				sum=temp_sum;
				sum_count=temp_sum_count;
			}
		}
		
		
		if (sum_count){//Если хоть что-то просуммировалось
			nums[1+step*2] = sum;
			//...переброс элементов
			//с позиций (step+sum_count)*2+1 до позиции .size()/2*2 (т.е. кроме последнего озера) вниз на sum_count*2
			//позиции включаются
			for (int i=(step+sum_count)*2+1;i<nums.size()/2*2;i++){
				nums[i-sum_count*2]=nums[i];
			}
			
			nums.resize(nums.size()/2-sum_count);
		}*/
	}
};


int main() {
	
	{
		vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
		int real_answer = 6;
		int answer = Solution().maxSubArray(v);
		//cout<<"Answer: "<<answer<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	{
		vector<int> v = {0};
		int real_answer = 0;
		int answer = Solution().maxSubArray(v);
		cout<<"Answer: "<<answer<<endl;
		ASSERT_EQUAL(answer, real_answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/