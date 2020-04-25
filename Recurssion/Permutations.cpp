/*
46. Permutations
Medium

3376

98

Add to List

Share
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/



// key idea: if the element of i is already at the first position then dont swap
//  or else swap
class Solution {
     vector<vector<int>> output;
    int val;
public:
    vector<vector<int>> permute(vector<int>& nums) {
//         this is my descision space
        vector<int> result;
        
            for(int i = 0;i<nums.size();i++){
                result.push_back(nums[i]);
            }
      
            backtrack(0,nums,result);
      
        return output;
    }
    void backtrack(int index,vector<int>& nums,vector<int> result){
         
        if(index == nums.size()){
            output.push_back(result);
        }
//       my constraint is to keep my index element in all the possible available desion spaces
        for(int i = index ;i<nums.size();i++){
         
//                 I am swapping because I want my first element to exist in all desicion spaces
                 swap(result[index],result[i]);
                 backtrack(index+1,nums,result);
                  swap(result[index],result[i]);
                
         
            
           
        }
    }
    
};
