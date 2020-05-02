/*
279. Perfect Squares
Medium

2370

176

Add to List

Share
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/
class Solution {
public:
    int numSquares(int n) {
//         the squares which can make it are n/2
        vector<int> q;
        vector<int> nums;
//         I have all my choices
        for(int i = 1 ;i*i<=n;i++){
           
                nums.push_back(i*i);
            
        }
        q.push_back(n);
        int finalval = 0;
        while(!(q.empty()) ){
            finalval++;
            vector<int> q_next;
//             every q next means diffrent possible remainder values
// remainder = 12,11,8,3,10,7,2,7,4,9,6,1,6,3,1,6,3,3,0,           
            for(int remainder: q){
               for(int square: nums){
                   if(remainder == square){
                     
                       return finalval;
                   }
                   else if(remainder < square){
                        
                       break;
                   }
                   else{
                      
                       q_next.push_back(remainder-square);
                   }
               }
            }
           q = q_next;
        }
        return finalval;
        
    }
       
         
    
};
