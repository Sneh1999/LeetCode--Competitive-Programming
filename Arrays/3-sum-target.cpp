/*
16. 3Sum Closest
Medium

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).



*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        vector<int> v;
       
        int res = nums[0]+nums[1]+nums[2];
        
        for(int i = 0 ; i < nums.size() - 2 ;i++){
            int second = i +1;
            int third = nums.size() - 1;
            while(second < third){
            
            int ans = nums[i] + nums[second] + nums[third];
             if(ans == target){
                 return nums[i] + nums[second] + nums[third];
             }
            else if(ans  < target){
               
                second++;
            }
            else{
               
                third-- ;
            }
                if(abs(ans-target)<abs(res-target))   
                 res=ans;
            }
        }
        
        
        return res;
    }
};
