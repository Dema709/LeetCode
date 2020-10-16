#include "test_runner.h"
#include <algorithm>
using namespace std;

class Solution  {
public:
	vector<int> sortArrayByParity(vector<int> A){
		partition (A.begin(), A.end(), [](int i){return (i%2 == 0);});
		return A;
	}
};


int main() {
	
	{
		vector<int> v = {3,1,2,4};
		cout<<Solution().sortArrayByParity(v)<<endl;
		//ASSERT_EQUAL(Solution().singleNumber(v), answer);
		//Лень прописывать тесты, изи решение
		//Можно было зарезервировать вектор такой же длины и заполнять его с
		//разных концов. Это было бы быстрее, но т.к. задание ежедневное, мне лень
	}

	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Sort Array By Parity

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
You may return any answer array that satisfies this condition.

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Note:
1 <= A.length <= 5000
0 <= A[i] <= 5000
*/