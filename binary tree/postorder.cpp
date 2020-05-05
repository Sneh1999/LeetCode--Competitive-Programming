/*


145. Binary Tree Postorder Traversal
Hard

1514

81

Add to List

Share
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode* root) {
        
        TreeNode* curr = root;
        vector<int> output;
        stack<TreeNode*> s;
        if(root == NULL){
            return output;
        }
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            output.push_back(node->val);
            if(node->left != NULL){
                s.push(node->left);
            }
            if(node->right != NULL){
                s.push(node->right);
            }
         
        }
        reverse(output.begin(),output.end());
        return output;
    }
};
