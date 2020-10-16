#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		//Runtime: 80 ms, faster than 73.18% of C++ online submissions for Assign Cookies.
		//Memory Usage: 17.5 MB, less than 89.47% of C++ online submissions for Assign Cookies.
		
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int answer = 0;
        int cur_children = g.size()-1;
        for (int i=0; i<s.size(); i++){
            while(true){
                if (cur_children<0) return answer;
                if (s[s.size()-1-i]>=g[cur_children]){
                    //Печенька достаточно большая
                    cur_children--;
                    answer++;
                    
                    break;
                }
                cur_children--;
            }
        }
        return answer;
    }
};

int main() {
	
	{
		vector<int> children  = {1,2,3};
		vector<int> cookies = {1,1};
		int answer = 1;
		auto real_answer = Solution().findContentChildren(children, cookies);
		//cout<<real_answer<<" "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		vector<int> children  = {1,2};
		vector<int> cookies = {1,2,3};
		int answer = 2;
		auto real_answer = Solution().findContentChildren(children, cookies);
		//cout<<real_answer<<" "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Assign Cookies

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj.
If sj >= gi, we can assign the cookie j to the child i, and the child i will be content.
Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.

Example 2:
Input: [1,2], [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
*/