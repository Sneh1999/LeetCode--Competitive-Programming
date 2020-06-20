/*
199. Binary Tree Right Side View
Medium

2116

128

Add to List

Share
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---



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
      vector<int> output;
public:
    vector<int> rightSideView(TreeNode* root) {
      
        if(root ==  NULL) return output;
        helper(root,0);
        return output;
    }
    void helper(TreeNode* root,int level){
//         each level can have only one value
        if(level == output.size()){
            output.push_back(root->val);
        }
        if(root->right != NULL){
            helper(root->right,level+1);
        }
        if(root->left != NULL){
              helper(root->left,level+1);
        }
    }
};
