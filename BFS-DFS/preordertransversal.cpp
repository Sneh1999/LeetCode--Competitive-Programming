/*

144. Binary Tree Preorder Traversal
Medium

1294

54

Add to List

Share
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> output;
        s.push(root);
      
        while(!(s.empty())){
            TreeNode* curr = s.top();
             s.pop();
            if(curr != NULL){
                 output.push_back(curr->val);
               
                s.push(curr->right);
                s.push(curr->left);
            }
           
        }
        return output;
    }
};
