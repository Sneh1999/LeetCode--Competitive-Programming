/*

572. Subtree of Another Tree
Easy

2046

101

Add to List

Share
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
 

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
 

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
       return transverse(s,t);
    }
    
    bool equals(TreeNode* x, TreeNode* y){
        if(x == NULL & y == NULL) return true;
        if(x == NULL || y == NULL) return false;
        return x->val == y->val && equals(x->left,y->left)  && equals(x->right ,y->right);
    }
    bool transverse(TreeNode* s,TreeNode* t){
        return s!= NULL && (equals(s,t) || transverse(s->left,t) || transverse(s->right,t)); 
    }
    
};
