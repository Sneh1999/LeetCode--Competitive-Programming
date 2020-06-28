/*
994. Rotting Oranges
Medium

1661

179

Add to List

Share
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.



/*



class Solution {
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>> q;
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1 ){
                    cnt++;
                }
            }
        }
        if( cnt == 0){
            return 0;
        }
        int ans = -1;
        
        while(!q.empty()){
            int s = q.size();
            ans++;
        for(int i = 0;i<s;i++){  

                pair<int,int> cur = q.front();
                q.pop();
//                 i-1,j
                if(cur.first > 0 && grid[cur.first-1][cur.second] == 1){
                     grid[cur.first - 1][cur.second] = 2;   // making it as 2
                    cnt--;
                    q.push({cur.first-1,cur.second});
                }
                if(cur.first < m-1 && grid[cur.first+1][cur.second] == 1){
                     grid[cur.first + 1][cur.second] = 2;   // making it as 2
                    cnt--;
                    q.push({cur.first+1,cur.second});
                }
                  if(cur.second > 0 && grid[cur.first][cur.second-1] == 1){
                     grid[cur.first][cur.second -1] = 2;   // making it as 2
                    cnt--;
                    q.push({cur.first,cur.second-1});
                }
                  if(cur.second < n-1 && grid[cur.first][cur.second+1] == 1){
                     grid[cur.first][cur.second + 1] = 2;   // making it as 2
                    cnt--;
                    q.push({cur.first,cur.second+1});
                } 
                 }
        
        }
         if(cnt == 0)  // if successful then return the number of minutes consumed or time else -1
            return ans;
        return -1;
    }
};
