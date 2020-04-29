/*
102. Binary Tree Level Order Traversal
Medium

2567

66

Add to List

Share
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]


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
    vector<vector<int>> merge;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
        {
            return merge;
        }
        helper(root,0);
        return merge;
    }
    void helper(TreeNode* root, int rootlevel ){
       if(merge.size() == rootlevel){
           vector<int> v1{};
           merge.push_back(v1) ;
       }
          merge[rootlevel].push_back(root->val);
         
                           
        if(root->left != NULL){
            helper(root->left,rootlevel +1);
        }
         if(root->right != NULL){
            helper(root->right,rootlevel +1);
        }
                           
    }
                           
};
