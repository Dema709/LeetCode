#include "test_runner.h"
#include "profile.h"

using namespace std;

class Solution {
public:
	bool isRobotBounded(string instructions){
		vector<int> robot_pos = {0, 0, 0};//x, y, face_angle
		//Север - 0, юг - 2, запад - 3, восток - 1
		
		//Один цикл инструкций
		for (auto c : instructions){
			if (c=='G'){
				if (robot_pos[2]%2){
					//Восток или запад
					robot_pos[0] += 2-robot_pos[2];
				} else {
					//Север или юг
					robot_pos[1] += 1-robot_pos[2];
				}
			} else if (c=='R'){
				robot_pos[2] = (robot_pos[2]+1)%4;
			} else {
				//'L'
				robot_pos[2] = (4+robot_pos[2]-1)%4;
			}
			//cout<<"Pos: "<<robot_pos<<endl;
		}
		
		//Возврат в начальную точку
		if (robot_pos[0]==0 && robot_pos[1]==0) return true;
		//Если робот не сморит на север, то через ещё 1 или 3 итерации он вернётся
		//Юг - через 1, запад или восток - через 3
		if (robot_pos[2]!=0) return true;
		else return false;
		
		//Излишние проверки, которые я делал до заглядывания в ответы по вопросу
		/*
		for (int i=0; i<3; i++){
			for (auto c : instructions){
				if (c=='G'){
					if (robot_pos[2]%2){
						//Восток или запад
						robot_pos[0] += 2-robot_pos[2];
					} else {
						//Север или юг
						robot_pos[1] += 1-robot_pos[2];
					}
				} else if (c=='R'){
					robot_pos[2] = (robot_pos[2]+1)%4;
				} else {
					//'L'
					robot_pos[2] = (4+robot_pos[2]-1)%4;
				}
				//cout<<"Pos: "<<robot_pos<<endl;
			}
			if (robot_pos[0]==0 && robot_pos[1]==0) return true;
		}
		
		
		return false;*/
	}
};

int main() {
	
	{
		string input = "GGLLGG";
		bool answer = true;
		auto real_answer = Solution().isRobotBounded(input);
		//cout<<"Input: "<<input<<endl<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = "GG";
		bool answer = false;
		auto real_answer = Solution().isRobotBounded(input);
		//cout<<"Input: "<<input<<endl<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	{
		string input = "GL";
		bool answer = true;
		auto real_answer = Solution().isRobotBounded(input);
		//cout<<"Input: "<<input<<endl<<"My answer is "<<real_answer<<" and real answer is "<<answer<<endl<<endl;
		ASSERT_EQUAL(real_answer, answer);
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Robot Bounded In Circle

On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:
"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.
Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

Example 1:
Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.

Example 2:
Input: "GG"
Output: false
Explanation: 
The robot moves north indefinitely.

Example 3:
Input: "GL"
Output: true
Explanation: 
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...

Note:

1 <= instructions.length <= 100
instructions[i] is in {'G', 'L', 'R'}
*/