/*
66. Plus One
Easy

1322

2159

Add to List

Share
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
   
        
        int tail = digits.size()-1;
        digits[tail] = digits[tail] + 1;
        if(digits[tail] <10){
            return digits;
        }
        
        digits[tail] = 0;
        tail--;
        int carry = 1;
        while(tail >= 0 && carry != 0){
             if(digits[tail] + carry <10){
                digits[tail]++;
                 carry--;
                 break;
            }
            digits[tail] = 0;
            tail--;
           
        }
         if(tail < 0 && carry != 0){
              digits.insert(digits.begin(), carry);
                carry --;
            }
        return digits;
    }
};
