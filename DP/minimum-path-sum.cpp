/*
64. Minimum Path Sum
Medium

2674

55

Add to List

Share
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int sum = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 1 ;i<n;i++) grid[i][0] += grid[i-1][0];
        for(int j = 1;j<m;j++) grid[0][j] += grid[0][j-1];
        
        for(int i = 1;i<n;i++){
            for(int j =1;j<m;j++){
                grid[i][j]= min(grid[i-1][j],grid[i][j-1]) + grid[i][j];
                
                
            }
        }
     
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
