/**
 * @param {number} x
 * @return {number}
 * Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
 */
var mySqrt = function(x) {
    var lo = 0, hi = x, mid;
    if(x===1){
return 1}
  for(var i = 0 ; i < 1000 ; i++){
      mid =  parseInt((lo+hi)/2);
     
      if(mid*mid == x) return mid;
      if(mid*mid > x) hi = mid;
      else lo = mid;
  }
  return mid;
};