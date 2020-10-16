#include "test_runner.h"
#include <stack>
using namespace std;

class MinStack {
public:
	MinStack(){}
	void push(int x){
		s_data.push(x);
		if (!s_min.empty()){
			s_min.push(min(x, s_min.top()));
			/*if (s_min.top()>x){
				s_min.push(x);
			} else {
				s_min.push(s_min.top());
			}*/
		} else {
			s_min.push(x);
		}
		//cout<<s_data.top()<<' ';
	}
	void pop(){
		s_data.pop();
		s_min.pop();
	}
	int top(){
		return s_data.top();
		//return 0;//Заглушка
	}
	int getMin(){
		return s_min.top();
		//return 0;;//Заглушка
	}
private:
	stack<int> s_data;
	stack<int> s_min;//Стак минимальных значений
};


int main() {
	
	{
		int temp;
		MinStack m;
		m.push(-2);
		m.push(0);
		m.push(-3);
		temp = m.getMin();	cout<<temp<<' ';
		m.pop();
		temp = m.top();		cout<<temp<<' ';
		temp = m.getMin();	cout<<temp<<' ';
		cout<<endl<<"Answer = 3 0 -2?"<<endl;
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 
Constraints:
Methods pop, top and getMin operations will always be called on non-empty stacks.
*/