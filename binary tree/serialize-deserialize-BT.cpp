/*
297. Serialize and Deserialize Binary Tree
Hard

2681

134

Add to List

Share
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.



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
class Codec {
public:

     // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       
         if(root == NULL){
            return "X";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);
        
        return to_string(root->val) + "," + left + "," + right;
    }
    
    int convertStringtoInt(string& data){
        int pos = data.find(',');
        int value = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return value;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        return deserializehelper(data);
    }
    TreeNode* deserializehelper(string &data ){
  
      if(data[0]=='X'){
            if(data.size()>1)
                data=data.substr(2);  // keep removing data 
            return NULL;
        }
          TreeNode* node = new TreeNode(convertStringtoInt(data));
          node->left = deserializehelper(data);
          node->right = deserializehelper(data);
          return node;
      }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
