/*
94. Binary Tree Inorder Traversal
Medium

2102

93

Favorite

Share
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?


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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<TreeNode*> first;
        vector<TreeNode*> second;
        vector<int> res;
        TreeNode* curr;
        if(root)
            first.push_back(root);
        while(true){
            if(!first.empty()){
                curr = first.back();
                first.pop_back();
                if(curr->left){
                    first.push_back(curr->left);
                }
                second.push_back(curr);
            }
            else if(!second.empty()){
                curr = second.back();
                second.pop_back();
                res.push_back(curr->val);
                if(curr->right){
                    first.push_back(curr->right);
                }
                
            }
            else 
                break;
        }
        return res;
    
    }
};