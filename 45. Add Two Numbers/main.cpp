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

/*
 Runtime: 32 ms, faster than 79.34% of C++ online submissions for Add Two Numbers.
 Memory Usage: 70.8 MB, less than 28.52% of C++ online submissions for Add Two Numbers.
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1_size=0, n2_size=0;
        ListNode* cur_node=l1;
        while (true){
            n1_size++;
            if (cur_node->next==nullptr) break;
            cur_node = cur_node->next;
        }
        cur_node=l2;
        while (true){
            n2_size++;
            if (cur_node->next==nullptr) break;
            cur_node = cur_node->next;
        }
        if (n2_size>n1_size){
            swap(l1,l2);
        }//Т.о. l1 всегда длиннее
        
        int remainder = 0;//В данном слечае - то, что переносится дальше
        int cur_sum;
        bool l2_ended = false;
        cur_node=l1;
        while (true){
            if (!l2_ended){
                if (l2->next==nullptr) l2_ended=true;
                cur_sum = l1->val+remainder+l2->val;
                remainder = cur_sum/10;
                l1->val = cur_sum%10;
                
                if (l1->next==nullptr){
					if (remainder!=0){
						l1->next=l2;
						l1->next->val = remainder;
						l1->next->next = nullptr;//Лишнее
					}
					return cur_node;
                }
                
                l1 = l1->next;
                if (!l2_ended) l2 = l2->next;
            } else {
                cur_sum = l1->val+remainder;
                remainder = cur_sum/10;
                l1->val = cur_sum%10;
                
                if (l1->next==nullptr){
					if (remainder!=0){
						l1->next=l2;
						l1->next->val = remainder;
						l1->next->next = nullptr;//Лишнее
					}
					return cur_node;
                }
                
                l1 = l1->next;
            }
        }
        return cur_node;//Заглушка
    }
};

int main() {
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

Значения могут выходить за int и long long, т.е. считать сумму надо на месте.
*/


/*
Решение из интернета (через создание новых нодов!):

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        ListNode *l3=NULL;
        ListNode **node=&l3;
        while(l1!=NULL||l2!=NULL||sum>0)
        {
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            (*node)=new ListNode(sum%10);
            sum/=10;
            node=&((*node)->next);
        }        
        return l3;
    }
};
*/