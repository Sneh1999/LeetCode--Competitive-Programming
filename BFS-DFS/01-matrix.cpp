/*

542. 01 Matrix
Medium

1184

100

Add to List

Share
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]

*/
class Solution {
    vector<vector<int>> output;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0){
            return matrix;
        }
        int cols = matrix[0].size();
        
        vector<vector<int>> dist(rows, vector<int>(cols,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i = 0; i<rows;i++){
            for(int j = 0;j<cols;j++ ){
                if(matrix[i][j] == 0){
                    dist[i][j] = 0;
//                      put all the 0's 
                    q.push(make_pair(i,j)); 
                    
                }
            }    
        }
        vector<vector<int>> dir = {{-1,0} , {1,0} , {0,1}, {0,-1}};
        
        while(!(q.empty())){
            pair<int,int> curr = q.front();
            q.pop();
            for(int i = 0 ;i<4;i++){
                int r = curr.first + dir[i][0];
                int c = curr.second + dir[i][1];
//                 if we found. the closest zero then we stop fpr this value
                if(r <0 || r>= rows || c <0 || c>= cols ) continue;
//                  this means if intialli int_max make it one
                if(dist[r][c] > dist[curr.first][curr.second] + 1){
                        dist[r][c] =  dist[curr.first][curr.second] + 1;
                        q.push({r,c});
                }
                
                
            }
        }
        
        return dist;
    }
};
