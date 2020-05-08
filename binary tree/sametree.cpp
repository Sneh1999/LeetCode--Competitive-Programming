/*
100. Same Tree
Easy

1848

55

Add to List

Share
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        queue<TreeNode*> s,s1;
        s.push(p);
        s1.push(q);
        
        while(!(s.empty() )&& !(s1.empty()) ){
            TreeNode* t1 = s.front();
            TreeNode* t2 = s1.front();
            s.pop();
            s1.pop();
            if(t1 == NULL && t2 == NULL) continue;
            if(t1 == NULL || t2 == NULL) return false;
            if(t1->val != t2->val) return false;
             s.push(t1->left);
            s1.push(t2->left);
            s.push(t1->right);
            s1.push(t2->right);
           
        }
        return true;
    }
};
