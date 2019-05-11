/**
 * @param {number} num
 * @return {boolean}
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false

 */
var isPerfectSquare = function(num) {
    var lo = 0 ,hi = num
  
    if(num<2){
        return false
    }
    
    let mid = parseInt((lo+hi)/2)
    console.log(mid)
     if(mid*mid===num){
        return true
    }
    else{
      let i =  isPerfectSquare(mid)
      return i
    }
    
};

