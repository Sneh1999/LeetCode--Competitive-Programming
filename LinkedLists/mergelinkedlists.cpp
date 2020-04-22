/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4


**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* copy = NULL;
        
        if(l1 == NULL and l2 == NULL){
            return l1;
        }
        if(l1 == NULL and l2 != NULL){
            return l2;
        }
         if(l2 == NULL and l1 != NULL){
            return l1;
        }
        while(l1 != NULL and l2 != NULL){
            
            if(l1->val >= l2->val){
                if(head == NULL){
                    head = new ListNode(l2->val);
                    copy = head;
                    head->next = new ListNode(0);
                    head = head->next;
                    
                }   else{
                    
                   head->val = l2->val;
                    head->next = new ListNode(0);
                    head = head->next;
                    
                    }
                 l2 = l2->next;
                
            }
            else{
             if(head == NULL){
                    head = new ListNode(l1->val);
                    copy = head;
                    head->next = new ListNode(0);
                    head = head->next;
                 
                }   else{
                    head->val = l1->val;
                     head->next = new ListNode(0);
                    head = head->next;
                    
                }
                  l1 = l1->next;
            }
            
          
           
        }
        
        if(l1 != NULL){
            
            while(l1 != NULL){
                
                  head->val = l1->val;
                  
                    if(l1->next !=NULL){
                    head->next = new ListNode(0);
                     head = head->next;
                }
                    
                 l1 = l1->next;
            }
        }
        
          if(l2 != NULL){
            
            while(l2 != NULL){
                head->val = l2->val;
               
                if(l2->next !=NULL){
                     head->next = new ListNode(0);
                     head = head->next;
                }
               
                    
                l2 = l2->next; 
            }
        }
        
      
        
        
        return copy;
    }
};
