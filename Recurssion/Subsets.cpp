/*
78. Subsets
Medium

3163

73

Add to List

Share
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
     vector<vector<int>> output;
    int k ;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() != 0){
            for(k = 0;k<(nums.size()+1);k++){
               vector<int> result = {}; 
                 backtrack(nums,0,result); 
            }
        }
       return output;
        
    }
    void backtrack(vector<int> nums, int index,vector<int> result){
        if(result.size() == k){
             output.push_back(result); 
        }

        for(int i = index;i< nums.size();i++){
//         first round one comes in , then 1,2 and 
            result.push_back(nums[i]);
//             what this does is that for 1 when added it tries f
            backtrack(nums,i+1,result);
//  this helps to convert from 1,2 to 1,3          
             result.pop_back();
//  0,1,1,2,1,3,1,2,3,2,2,3
        }
        
       
    }
};
