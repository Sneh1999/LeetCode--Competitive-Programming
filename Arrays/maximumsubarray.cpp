/*
53. Maximum Subarray
Easy

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.




*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0;
        int curr = nums[0];
        int max = nums[0];
        int accum = 0;
        for(int right = 0; right< nums.size(); right ++){
            int rightNum = nums[right];
            accum += rightNum;
            
            if(rightNum >= accum) {
                left = right;
                accum = rightNum;
            }
            max = std::max(max,accum);
        }
        return max;
    }
};
