/*
323. Number of Connected Components in an Undirected Graph
Medium

657

19

Add to List

Share
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

*/

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
            
           vector<vector<int>> adjlist(n,vector<int>(0));
            vector<bool> visited(n,false);
             int num = 0;
            stack<int> dfs;
//  to find adjlist     
            for(auto edge: edges){
                int from = edge[0];
                int to = edge[1];
                adjlist[from].push_back(to);
                adjlist[to].push_back(from);
            }
        
            for(int i = 0;i< n;i++){
                if(!visited[i]){
                    num++;
                    dfs.push(i);
                    while(!(dfs.empty())){
                       int connected = dfs.top();
                        visited[connected] = true;
                        dfs.pop();
                        for(int neighbour: adjlist[connected]){
                            if(!(visited[neighbour])){
                                dfs.push(neighbour);
                            }
                            
                        }
                    }
                }
            }
        return num;
    }
};
