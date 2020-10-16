#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	void print_delta(const string &a, const string &b){
		int i = 0, j = 0;
			int tag1 = 0, tag2 = 0;
			while (tag1 < 2 && tag2 < 2)
			{
				if (i == a.length()) {
					i = 0;
					tag1++;
					cout<<"i = 0; tag1++; tag1="<<tag1<<endl;
				}
					
				if (j == b.length()) {
					j = 0;
					tag2++;
					cout<<"j = 0; tag2++; tag2="<<tag2<<endl;
				}
				cout<<"check "<<a[i]<<" and "<<b[j]<<" under numbers "<<i<<" "<<j<<endl;
				if (a[i] < b[j]){
					cout<<"false"<<endl;
					return;// false;
				}
				else if (a[i] > b[j]){
					cout<<"true"<<endl;
					return;// true;
				}
				i++; j++;
			}
			cout<<"false"<<endl;
			return;// false;
	}
	string largestNumber(vector<int> &nums) {
		//Решение из интернета
		if (nums.empty()) return "0";
		
		vector<string> arr;
		for(auto i:nums)
			arr.push_back(to_string(i));
		
		//Гениально! Но можно и быстрее проверить
		//sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
		
		//Непонятная проверка из интернета. Работает! о_О
		//Нереально быстро
		sort(arr.begin(), arr.end(), [](const string &a, const string &b) 
		{ 
			int i = 0, j = 0;
			int tag1 = 0, tag2 = 0;
			while (tag1 < 2 && tag2 < 2)
			{
				if (i == a.length()) {
					i = 0;
					tag1++;
				}
					
				if (j == b.length()) {
					j = 0;
					tag2++;
				}
				if (a[i] < b[j])
					return false;
				else if (a[i] > b[j])
					return true;
				i++; j++;
			}
			return false;
		});
		
		//Чуть более понятное сравнение, хоть и малость медленнее предыдущего варианта
		/*sort(arr.begin(), arr.end(), [](const string &a, const string &b) 
		{
			int a_size = a.size(), b_size = b.size();
			for (int i=0; i<a_size+b_size; i++){
				int left, right;
				if (i<a_size){
					if (i<b_size){
						if (a[i]!=b[i]){
							return a[i]>b[i];
						}
					} else {
						if (a[i]!=a[i-b_size]){
							return a[i]>a[i-b_size];
						}
					}
				} else {
					if (i<b_size){
						if (b[i-a_size]!=b[i]){
							return b[i-a_size]>b[i];
						}
					} else {
						if (b[i-a_size]!=a[i-b_size]){
							return b[i-a_size]>a[i-b_size];
						}
					}
				}
			}
			return false;
		});*/
		
		
		string res;
		for(auto & s:arr)
			res+=s;
		//cout<<res<<endl;
		while(res[0]=='0' && res.length()>1)
			res.erase(0,1);
		return res;
	}
};

int main() {
	
	{
		Solution().print_delta("000000000","00");
	}
	
	
	
	/*{
		vector<int> nums  = {0,0};
		string answer = "0";
		auto real_answer = Solution().largestNumber(nums);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {};
		string answer = "0";
		auto real_answer = Solution().largestNumber(nums);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {1};
		string answer = "1";
		auto real_answer = Solution().largestNumber(nums);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {9,3,30};
		string answer = "9330";
		auto real_answer = Solution().largestNumber(nums);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {10,2};
		string answer = "210";
		auto real_answer = Solution().largestNumber(nums);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {3,30,34,5,9};
		string answer = "9534330";
		auto real_answer = Solution().largestNumber(nums);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {9,9,9,9,9,9,9,9,9};
		string answer = "999999999";
		LOG_DURATION("Same test");
		auto real_answer = Solution().largestNumber(nums);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {0,1,2,3,4,5,6,7,8,9};
		string answer = "9876543210";
		LOG_DURATION("Rising test");
		auto real_answer = Solution().largestNumber(nums);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> nums  = {9,8,7,6,5,4,3,2,1,0};
		string answer = "9876543210";
		LOG_DURATION("Descending test");
		auto real_answer = Solution().largestNumber(nums);
		//cout<<"Answers: '"<<real_answer<<"' '"<<answer<<"'"<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
	vector<int> nums  = {41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55};
		LOG_DURATION("Massive test 202/222");
		for (int i=0; i<4000; i++){
			auto real_answer = Solution().largestNumber(nums);
		}
	}*/
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"

Example 2:

Input: [3,30,34,5,9]
Output: "9534330"

Note: The result may be very large, so you need to return a string instead of an integer.
*/

/*
Вариант, который не справился с тестом 202/222
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.empty()) return "0";
		vector<string> nums_str;
		for (auto i : nums){
			nums_str.push_back(to_string(i));
		}
		sort(nums_str.begin(),nums_str.end(),[](string& lhs, string& rhs){return lhs[0]<rhs[0];});
		string answer = largestNumber(move(nums_str), -1);
		//cout<<answer<<endl;
		if (answer[0]=='0') return "0";
		else return answer;
		//return "";
	}
private:
	string largestNumber(vector<string> s, int del_index){
		if (del_index!=-1){
			auto it_del = next(s.begin(),del_index);
			s.erase(it_del);
			if (s.size()==1){
				return s[0];
			}
		}
		if (s.empty()) return "";
		
		string answer;
		char max_char = s[s.size()-1][0];//cout<<"max_char = "<<max_char<<endl;
		string prev_str;
		for (int i=0; i<s.size(); i++){
			if (s[s.size()-1-i][0]!=max_char){//Проверяем с конца
				break;
			} else {
				
				if (prev_str != s[s.size()-1-i]){
				//if (true){
					string temp = s[s.size()-1-i] + largestNumber(s, s.size()-1-i);
					if (temp>answer){
						answer = temp;
					}
					
					prev_str = s[s.size()-1-i];
				}
			}
		}
		return answer;
		//return "";//Заглушка
	}
};
*/