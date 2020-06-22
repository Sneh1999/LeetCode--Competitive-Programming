/*
226. Invert Binary Tree
Easy

3272

53

Add to List

Share
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* help = root;
        helper(root);
        return help;
    }
    TreeNode* helper(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        if(root->left == NULL || root->right == NULL){
            if(root->left == NULL && root->right != NULL){
                root->left = root->right;
                root->right = NULL;
                helper(root->left);
            }
             else if(root->right == NULL && root->left != NULL){
                root->right = root->left;
                root->left = NULL;
                helper(root->right);
            }
            else{
                return NULL;
            }
            
        }
        if(root->left != NULL && root->right != NULL ){
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right =  temp;
            helper(root->left);
            helper(root->right);
        }
        return NULL;
    }
};
