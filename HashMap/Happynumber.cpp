/*

202. Happy Number
Easy

1866

397

Add to List

Share
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> umap;
        while(1){
             int totalsum = number(n);
            if(umap.find(n) != umap.end()){
                return false;
            }
            else if(n == 1){
                return true;
            }
            else{
                umap[n] = 1;
            }
            n = totalsum;
        }
     
    }
    
    
    int number(int n){
        int sum =0;
         while(n){
          
          int r = n%10;
          n = n/10;
          sum += r*r;
      }
        return sum;
        
    }
    
    
};
