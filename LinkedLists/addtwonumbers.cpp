/*
2. Add Two Numbers
Medium

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.






*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int carry = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    
        ListNode* newlist = newList(l1,l2);
        
        return newlist;
    }
    
    ListNode* newList(ListNode* l1,ListNode* l2){
        int count = 0;
        ListNode *curr = new ListNode(0);
        ListNode *save = curr;
        while(l1 != NULL || l2!=NULL){
            
            if(l1){
                carry+=l1->val;
                l1=l1->next;
            }
            if(l2){
                carry+= l2->val;
                l2=l2->next;
            
            }
            curr->val = carry%10;
            carry /= 10;
            
            if(l1|| l2 ||carry){
                curr->next = new ListNode(carry);
                curr = curr->next;
            }
        
            
        }
        
       
      
       
        return save;
    }
    
    
};
