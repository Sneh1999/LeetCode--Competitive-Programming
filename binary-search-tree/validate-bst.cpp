/*
98. Validate Binary Search Tree
Medium

3428

488

Add to List

Share
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.



*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int valsum = 0;
public:
    bool isValidBST(TreeNode* root) {
   
      return helper(root,numeric_limits<long>::min(),
                                  numeric_limits<long>::max());  
    }
    bool helper(TreeNode* root,long min,long max){
        if(root == NULL) return true;
        int val = root->val;
        if(val != valsum &&   val <= min) return false;
        if(val != valsum && val >= max) return false;
        
        
        if(!(helper(root->left,min,val))) return false;
        if(!(helper(root->right,val,max))) return false;
        return true;
    }
};
