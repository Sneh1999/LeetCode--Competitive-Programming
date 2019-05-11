/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
 */
var searchInsert = function(nums, target) {
    let mid 
   
var y =   x(nums,target,0,(nums.length-1))
   
  return y
};

let  x = function (nums,target ,left,right){
   
    mid = parseInt((left + right)/2)
  
   if(nums[mid]===target){
     
       return mid 
       }
   else if(left >right){
       return 0 
   }
   else if(target< nums[mid]){
    let y =    x(nums,target,left,mid-1)
    return y
   }
   else if(target>nums[mid]){
      let y =  x(nums,target,mid+1,right)
      return y
   }
}

