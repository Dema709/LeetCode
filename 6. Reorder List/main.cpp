#include "test_runner.h"
#include <deque>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ostream& operator << (ostream& os, ListNode& s) {
  //os << "{";
  cout<<s.val;
  if (s.next){
	  cout<<", "<<*s.next;
  }
  return os;// << "}";
}

ListNode* CreateNode(int value, deque<ListNode> & d){
	d.emplace_back(value, nullptr);
	return &d.back();
}

ListNode make_ListNode_from_vector(vector<int>& v, deque<ListNode> & d){
	ListNode * firstNode = CreateNode(v[0],d);
	ListNode * lastNode = firstNode;
	ListNode * currentNode;
	
	for (int i = 1;i<v.size();i++){
		currentNode=CreateNode(v[i],d);
		lastNode->next = currentNode;
		lastNode = currentNode;
	}
	return *firstNode;
}

class Solution  {
public:
	void reorderList(ListNode* head){
		if (!head){
			return;
		}
		
		//Если есть как минимум два потомка, вызвать функцию ещё раз
		if (!head->next){
			//cout<<"only one for:"<<endl;
			return;
		}
		if (!head->next->next){
			//cout<<"second is "<< head->next->val<<endl;
			return;
		}
		
		ListNode* temp_node = getBeforeLastNode(head);//Ln-1
		temp_node->next->next = head->next;//За Ln следует L1
		head->next = temp_node->next;//За L0 следует Ln
		temp_node->next = nullptr;   //За Ln-1 не следует ничего

		reorderList(head->next->next);
	}
private:
	ListNode* getBeforeLastNode(ListNode* head){
		if (!head->next->next){
			//cout<<"only one for:"<<endl;
			return head;//Предпоследняя нода
		} else {
			return getBeforeLastNode(head->next);
		}
	}
};


int main() {
	
	{
		vector<int> vect1 = {1,2,3,4};
		vector<int> vect2 = {1,4,2,3};
		deque<ListNode> nodes;
		ListNode list1 = make_ListNode_from_vector(vect1,nodes);
		Solution().reorderList(&list1);
		ListNode list2 = make_ListNode_from_vector(vect2,nodes);
		cout<<'{'<<list1<<'}'<<endl;
		cout<<'{'<<list2<<'}'<<endl;
	}
	
	{
		vector<int> vect1 = {1,2,3};
		vector<int> vect2 = {1,3,2};
		deque<ListNode> nodes;
		ListNode list1 = make_ListNode_from_vector(vect1,nodes);
		Solution().reorderList(&list1);
		ListNode list2 = make_ListNode_from_vector(vect2,nodes);
		cout<<'{'<<list1<<'}'<<endl;
		cout<<'{'<<list2<<'}'<<endl;
	}
	
	{
		vector<int> vect1 = {4};
		vector<int> vect2 = {4};
		deque<ListNode> nodes;
		ListNode list1 = make_ListNode_from_vector(vect1,nodes);
		Solution().reorderList(&list1);
		ListNode list2 = make_ListNode_from_vector(vect2,nodes);
		cout<<'{'<<list1<<'}'<<endl;
		cout<<'{'<<list2<<'}'<<endl;
	}
	
	{
		vector<int> vect1 = {6,1};
		vector<int> vect2 = {6,1};
		deque<ListNode> nodes;
		ListNode list1 = make_ListNode_from_vector(vect1,nodes);
		Solution().reorderList(&list1);
		ListNode list2 = make_ListNode_from_vector(vect2,nodes);
		cout<<'{'<<list1<<'}'<<endl;
		cout<<'{'<<list2<<'}'<<endl;
	}
	
	{
		vector<int> vect1 = {1,2,3,4,5,6,7};
		vector<int> vect2 = {1,7,2,6,3,5,4};
		deque<ListNode> nodes;
		ListNode list1 = make_ListNode_from_vector(vect1,nodes);
		Solution().reorderList(&list1);
		ListNode list2 = make_ListNode_from_vector(vect2,nodes);
		cout<<'{'<<list1<<'}'<<endl;
		cout<<'{'<<list2<<'}'<<endl;
	}
	
	{
		vector<int> vect1 = {1,2,3,4,5,6};
		vector<int> vect2 = {1,6,2,5,3,4};
		deque<ListNode> nodes;
		ListNode list1 = make_ListNode_from_vector(vect1,nodes);
		Solution().reorderList(&list1);
		ListNode list2 = make_ListNode_from_vector(vect2,nodes);
		cout<<'{'<<list1<<'}'<<endl;
		cout<<'{'<<list2<<'}'<<endl;
	}
	
	{
		vector<int> vect1 = {1,2,3,4,5};
		vector<int> vect2 = {1,5,2,4,3};
		deque<ListNode> nodes;
		ListNode list1 = make_ListNode_from_vector(vect1,nodes);
		Solution().reorderList(&list1);
		ListNode list2 = make_ListNode_from_vector(vect2,nodes);
		cout<<'{'<<list1<<'}'<<endl;
		cout<<'{'<<list2<<'}'<<endl;
	}
	
	cout<<endl<<"Check for identity! Is it OK?"<<endl;
	
	return 0;
}

/*
Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:
Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

*/