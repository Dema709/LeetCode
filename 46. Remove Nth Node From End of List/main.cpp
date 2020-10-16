#include "test_runner.h"
#include "profile.h"
//#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //n=5;
        int list_size = 1;
        ListNode* temp = head;
        while (temp->next != nullptr){
            list_size++;
            temp = temp->next;
        }
        if (list_size==n){
            if (n==1) return nullptr;
            return head->next;
        }
        temp = head;
        for (int i=0; i<list_size-n-1; i++){
            temp = temp->next;
        }
       /* if (temp->next->next!=nullptr){
            temp->val = temp->next->next->val;
        }*/
        temp->next = temp->next->next;
        //cout<<temp->val;
        
        return head;
    }
};

int main() {
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
*/