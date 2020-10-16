#include "test_runner.h"

using namespace std;

class Solution {
public:
	//Решение лучше 93% по времени работы и 70% по памяти
	//Используем нулевой столбец/колонку для записи флагов
	void setZeroes(vector<vector<int>>& matrix) {
		bool first_row_have_zeroes    = false;
		bool first_column_have_zeroes = false;
		if (matrix[0][0]==0){
			first_row_have_zeroes    = true;
			first_column_have_zeroes = true;
			//matrix[0][0]=1;
		}
		if (!first_row_have_zeroes){
			for (int j=1; j<matrix[0].size(); j++){
				if (matrix[0][j]==0){
					first_row_have_zeroes = true;
					break;
					//matrix[0][j]=1;
				}
			}
		}
		if (!first_column_have_zeroes){
			for (int i=1; i<matrix.size(); i++){
				if (matrix[i][0]==0){
					first_column_have_zeroes = true;
					break;
					//matrix[i][0]=1;
				}
			}
		}
		//Уже оценили, имеет ли нулевой столбец/колонка нули
		//Записываем в нулевой столбец и колонку состояние подматрицы
		for (int i=1; i<matrix.size(); i++){
			for (int j=1; j<matrix[0].size(); j++){
				if (matrix[i][j]==0){
					matrix[i][0]=0;
					matrix[0][j]=0;
				}
			}
		}
		
		for (int i=1; i<matrix.size(); i++){
			if (matrix[i][0]==0){
				for (int j=0; j<matrix[0].size(); j++){
					matrix[i][j]=0;
				}
			}
		}

		for (int j=1; j<matrix[0].size(); j++){
			if (matrix[0][j]==0){
				for (int i=0; i<matrix.size(); i++){
					matrix[i][j]=0;
				}
			}
		}
		
		if (first_row_have_zeroes){
			for (int j=0; j<matrix[0].size(); j++){
				matrix[0][j]=0;
			}
		}
		if (first_column_have_zeroes){
			for (int i=0; i<matrix.size(); i++){
				matrix[i][0]=0;
			}
		}
	}
	
/*
	//Решение лучше 75% по времени работы и 37% по памяти
	//Модификации с continue не дали заметного ускорения
	void setZeroes(vector<vector<int>>& matrix) {
		set<int> is, js;
		for (int i=0; i<matrix.size(); i++){
			for (int j=0; j<matrix[0].size(); j++){
				if (matrix[i][j]==0){
					is.insert(i);
					js.insert(j);
				}
			}
		}
		//cout<<"i's "<<is<<endl<<"j's "<<js<<endl;
		for (int i : is){
			for (int j=0; j<matrix[0].size(); j++){
				matrix[i][j]=0;
			}
		}
		for (int i=0; i<matrix.size(); i++){
			for (int j : js){
				matrix[i][j]=0;
			}
		}
	}
*/
};


int main() {
	/*
	{
		vector<vector<int>> input  = {{1,1,1},{1,0,1},{1,1,1}};
		vector<vector<int>> answer = {{1,0,1},{0,0,0},{1,0,1}};
		Solution().setZeroes(input);
		//cout<<input<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(input, answer);
	}*/
	
	{
		vector<vector<int>> input  = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
		vector<vector<int>> answer = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
		Solution().setZeroes(input);
		//cout<<input<<endl<<answer<<endl<<endl;
		ASSERT_EQUAL(input, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Set Matrix Zeroes

Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 
Example 1:
Input: matrix = {{1,1,1},{1,0,1},{1,1,1}}
Output: {{1,0,1},{0,0,0},{1,0,1}}

Example 2:
Input: matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}}
Output: {{0,0,0,0},{0,4,5,0},{0,3,1,0}}
 
Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1
*/