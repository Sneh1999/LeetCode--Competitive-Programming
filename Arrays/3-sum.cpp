/*
15. 3Sum
Medium

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]



*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> v;
        
        if(nums.size() < 3){
            return v;
        }
        
        bool flag = true;
        
        for(int i =0 ;i<nums.size();i++){
            
            if(nums[i] != 0){
                flag = false;
                break;
            }
        }
        
        if(flag){
            v.push_back({0,0,0});
            return v;
        }
        
        set<vector<int>>s;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ;i<nums.size()-2; i++){
            int second = i+1;
            int third = nums.size() - 1;
            
            while(second < third){
                if(nums[i] + nums[second] + nums[third] == 0){
                    if(s.find({nums[i] ,nums[second] , nums[third]}) == s.end()){
                        v.push_back({nums[i] ,nums[second] ,nums[third]});
                        //the step is here to ensure that the numbers are distinct because set helps keep distinct                              numbers 
                        s.insert({nums[i],nums[second],nums[third]});
                    }
                    second++;
                }
                    else if(nums[i] + nums[second] < -nums[third]){
                        //this happens that as we have more negative we need more positive so we add the second
                        second++;
                    }
                    else{
                        third--;
                    }
                }
            }
        
        return v;
    }
};
