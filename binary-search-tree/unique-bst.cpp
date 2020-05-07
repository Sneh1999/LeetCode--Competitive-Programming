/* 96. Unique Binary Search Trees
Medium

2831

106

Add to List

Share
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
Accepted
265,236
Submissions
525,606
*/


class Solution {

public:
    int numTrees(int n) {
//         as then we would only have 0,n-1 but we need 0,n to return n
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2;i<=n;i++){
            for(int j = 1 ;j<=i;j++){
                dp[i] += (dp[j-1])*(dp[i-j]);
            }
        }
            return dp[n];
    }

   
};