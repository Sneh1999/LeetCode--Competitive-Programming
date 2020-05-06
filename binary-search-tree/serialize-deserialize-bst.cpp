/*
449. Serialize and Deserialize BST
Medium

1136

65

Add to List

Share
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

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
    
    void serializehelper(TreeNode* root ,string& s){
        if(root == NULL){
            return;
        }
        s+=to_string(root->val) + ","; // ',' for seperating each value
        serializehelper(root->left, s);
        serializehelper(root->right, s);
    }
   
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       
         if(root == NULL){
            return "";
        }
        
        string s = "";
        serializehelper(root,s);
        return s;
       
    }
    
    int convertStringtoInt(string& data, int& pos){ // Find ',' and return value
        pos=data.find(',');
        int value=stoi(data.substr(0, pos));
        return value;
    }
    
    TreeNode* deserializehelper(string& data, int min, int max) {
        if(data.size()==0) return nullptr;
        int pos=0;
        int value = convertStringtoInt(data, pos); // Find new value and position of ','
        if (value < min || value > max) return nullptr; // Is new value in given range
        
        TreeNode* tnode = new TreeNode(value); 
        data=data.substr(pos+1); // Update only when in range
        
        tnode->left=deserializehelper(data, min, tnode->val); // Branch off to left & right subtree with given ranges
        tnode->right=deserializehelper(data, tnode->val, max);
        return tnode;
    }
    
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        return deserializehelper(data, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
