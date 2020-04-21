/*

34. Find First and Last Position of Element in Sorted Array
Medium

2901

130

Add to List

Share
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]


*/
class Solution {
public:
     int binarySearch(vector<int>& nums, int target, bool b) {
        
        
        int left = 0;
        int right = nums.size();
      
        while(left < right){
            int middle = (left + right)/2;
            
            if(((target ==  nums[middle]) && b) || (nums[middle] > target)  ){
//                 we are trying to make the right index the upper  boundry  index 
//                 it would be upper bound as it would be higher only at the +1 index
                right = middle;
               
            }
            else{

                 left = middle +1;
            }
        }
//       when left == right   
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low = binarySearch(nums,  target, true);
        cout<<low;
        if(low == nums.size() ||  nums[low] != target){
            return {-1,-1};
        }
        int right = binarySearch(nums, target, false) - 1;
        return {low,right};

    }
   
    
};
