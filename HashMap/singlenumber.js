/**
 * @param {number[]} nums
 * @return {number}
 * 
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
 */
var singleNumber = function(nums) {
    var map = new Map()
    
    for( i = 0 ;i< nums.length;i ++){
        if(map.has(nums[i])){
            
            map.delete(nums[i])
            }
        else{
            map.set(nums[i],i)
        }
    }
    for (var value of map.values()) {
       console.log(value)
        return nums[value]
    }
    
    
    
};