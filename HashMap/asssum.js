/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 * 
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 */
var twoSum = function(numbers, target) {
    var map = new Map()
   
    for(var i = 0 ;i< numbers.length; i++){
         var count = []
        if(map.has(target-numbers[i])){
           var k =  map.get(target-numbers[i])
           if(k<i){
               console.log(i)
               count.push(k+1)
               count.push(i+1)
               return count
            }
        }
        else{
            map.set(numbers[i],i)
        }
        }
};