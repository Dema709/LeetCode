#include "test_runner.h"

using namespace std;

class Solution  {
public:
	void rotate(vector<vector<int>>& matrix){
		int n = matrix.size();
		for (int i=0;i<n/2;i++){
			for (int j=0;j<n/2;j++){
				swap(matrix[j][i], matrix[i][n-1-j]);
				swap(matrix[n-1-i][j], matrix[n-1-j][n-1-i]);
				swap(matrix[j][i], matrix[n-1-j][n-1-i]);
			}
		}
		if (n%2){
			//Нечётный размер матрицы
			int i = n/2;
			for (int j=0;j<n/2;j++){
				swap(matrix[j][i], matrix[i][n-1-j]);
				swap(matrix[n-1-i][j], matrix[n-1-j][n-1-i]);
				swap(matrix[j][i], matrix[n-1-j][n-1-i]);
			}
		}
	}
};


int main() {
	
	{
		vector<vector<int>> m1 = {
			{1,2,3},
			{4,5,6},
			{7,8,9}
		};
		vector<vector<int>> m2 = {
			{7,4,1},
			{8,5,2},
			{9,6,3}
		};
		Solution().rotate(m1);
		ASSERT_EQUAL(m1,m2);
	}
	
	{
		vector<vector<int>> m1 = {
			{ 5, 1, 9,11},
			{ 2, 4, 8,10},
			{13, 3, 6, 7},
			{15,14,12,16}
		};
		vector<vector<int>> m2 = {
			{15,13, 2, 5},
			{14, 3, 4, 1},
			{12, 6, 8, 9},
			{16, 7,10,11}
		};
		Solution().rotate(m1);
		ASSERT_EQUAL(m1,m2);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Rotate Image

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 
rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/