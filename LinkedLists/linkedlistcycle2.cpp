/*

142. Linked List Cycle II
Medium

2298

192

Add to List

Share
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

*/


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       
      
        if(head == NULL){
            return NULL;
        }
        ListNode* first = head;
        ListNode* second = head;
    
        
        
        while( second != NULL && second->next != NULL){
            first = first->next;
            second = second->next->next;
            if(first == second){
              first = head;
                while(first!= second){
                    first = first->next;
                    second = second->next;
                }
                return first;
            }
            
           
        }
        return NULL;
        
    }
};
