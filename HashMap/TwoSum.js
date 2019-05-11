/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 * 
 * 
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */
var twoSum = function(nums, target) {
    let numsMap = new Map();
    console.log(nums)
    for ( i = 0 ;i < nums.length; i++){
        const complement = target - nums[i];
        if (numsMap.has(complement)){
            return [numsMap.get(complement) , i];
        }
        numsMap.set(nums[i] ,i);
    }
    throw new Error("No two sum solution found")
};