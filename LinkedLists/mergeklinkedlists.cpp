/*

23. Merge k Sorted Lists
Hard

4126

262

Add to List

Share
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> listcopy;
        for(int i = 0; i< lists.size(); i++){
            ListNode* copy = (lists[i]);
            while(copy != NULL){
                listcopy.push_back(copy->val);
                copy = copy->next;
            }
            
        }
        sort(listcopy.begin(), listcopy.end());
        ListNode* head = NULL;
        ListNode* copy = NULL;
        for(int i = 0 ; i< listcopy.size(); i++){
       
            if(head == NULL){
               
                head = new ListNode(listcopy[i]);
                copy = head; 
            }
            else{
                 head->val = listcopy[i];
            }
            if(i != listcopy.size()-1){
                 head->next = new ListNode(0);
              head = head->next;
            }
           
        }
        
  
         return copy;
    }
    
   
};
