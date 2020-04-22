/*

19. Remove Nth Node From End of List
Medium

2859

204

Add to List

Share
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
//        move such that the distance between first and second is  n
         
        for(int i =1;i<= n+1;i++){
            first = first->next;
        } 
       
       while(first != NULL){
           first = first->next;
           second = second->next;
         
       }
       cout<<second->next->val;
        second->next = second->next->next;
       
        return dummy->next;
    }
};
