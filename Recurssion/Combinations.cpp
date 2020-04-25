/*
77. Combinations
Medium

1268

63

Add to List

Share
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/
class Solution {
     vector<vector<int>> output;
    int val;
public:
    vector<vector<int>> combine(int n, int k) {
//         my choices are 1---4
//  my choices have two places to go , so thats my decision space
//  my contraints are that the first value < second value        
                
                val = k;
                backtrack(1,{},n);
                return output;
           
    }
    
    void backtrack(int index,vector<int> result,int n){
        if(result.size() == val ){
            output.push_back(result);
        }
        
//   these are my choices      
        for(int i = index;i<=n;i++){
                result.push_back(i);
                backtrack(i+1,result,n);
                result.pop_back();
        }
        
    }
};
