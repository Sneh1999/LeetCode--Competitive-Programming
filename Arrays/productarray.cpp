/*
238. Product of Array Except Self
Medium

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)





*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> output;
        int j = 0;
        int product = 1;
        // if(nums.size() == 2){
        //     if(nums[0] == 0 && nums[1] == 0){
        //         return nums;
        //     }
        // }
     
        for(int i = 0 ; i< nums.size(); i++) {
        
            if(i == nums.size() - 1 && j == nums.size() - 1){
    
                output.push_back(product);
                break;
            }
            else{
                 if(i!=j){
                
                product*= nums[i];
              
            }
          
            
            if(i == nums.size() - 1){
                output.push_back(product);
                j++;
                i = -1;
                product = 1;
            }
            }
            
             
           
        }
        return output;
    }
};


