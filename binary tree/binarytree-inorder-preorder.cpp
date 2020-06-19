/*

105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

3180

92

Add to List

Share
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
//  inorder : left->root->right
// preorder: root->left->right;
class Solution {
    int rootIndex = 0;
    std::unordered_map<int,int> Map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int index = 0;
//         what map does is it helps in keep tracking of where the root is in inorder
        for(int val: inorder){
            Map[val] = index;
            index++;
        }
        
        return helper(preorder,inorder,0,inorder.size());
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int left ,int right){
//          no subtree left
            if(left >= right) return NULL;
            
//         get the root
        int rootI =  preorder[rootIndex];
        TreeNode* root = new TreeNode(rootI);
        rootIndex++;
        int index = Map[rootI];
         root->left = helper(preorder,inorder,left,index);
         root->right = helper(preorder,inorder,index+1,right);
        
        return root;
    }
};
