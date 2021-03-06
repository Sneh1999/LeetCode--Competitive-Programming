/*
654. Maximum Binary Tree
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

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
   
   
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return NULL;
        int size = nums.size();
        TreeNode *root = new  TreeNode(*max_element(nums.begin(),nums.end()));
        auto element = max_element(nums.begin(),nums.end());
        cout<<*element;
        if(element != begin(nums)){
            vector<int> left(begin(nums),element);
            root->left = constructMaximumBinaryTree(left);
        }
        if(element != end(nums) - 1){
            vector<int> right(element+1,end(nums));
            root->right = constructMaximumBinaryTree(right);
        }
        
        
        return root;
        
    }
};