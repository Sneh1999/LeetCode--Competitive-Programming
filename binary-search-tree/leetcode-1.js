// Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

// The binary search tree is guaranteed to have unique values.

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var rangeSumBST = function(root, L, R) {
    var count = L + R
    c
    
    function calculate(root){
        if(root.left == null && root.right === null){
            return
            }
        if(root.val>L && root.val<R){
            count += root.val
        }
     
        if(root.left !== null){
             calculate(root.left)
        }
        if(root.right !== null){
             calculate(root.right)
        }
       
       
    }
    
 calculate(root)
      
       
 return count
   
    
};

