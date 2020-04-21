/*
41. First Missing Positive
Hard

2947

742

Add to List

Share
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1


*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n = nums.size();
        int flag = 0;
        for(int i = 0;i<nums.size();i++ ){
            if(nums[i]== 1){
                  flag = 1;
                break;
            }
        }
        
        if(flag == 0){
            return 1;
        }
        if(nums.size() == 1){
            return 2;    
        }
        else{
//             convert all the negatives and 0. and numbers more than nums.size to 1
            for(int i=0; i<nums.size();i++){
                if(nums[i] <= 0 || nums[i] > nums.size()){
                    nums[i] = 1;
                }
            }
        }
        
        for(int i =0;i<n;i++){
            int a = abs(nums[i]);
            
            if(a == n){
//                 this is the maximum possible case
                num[0] = - abs(nums[0]);
            }
            else{
                nums[a] = - abs(nums[a]);
            }
        }
        
        for(int i =1 ;i<n;i++){
            if(nums[i]> 0){
                return i;
            }
        }
        
        if(nums[0] > 0){
            return n;
        }
        
        return n+1;
     }
};
