/*
322. Coin Change
Medium

3466

124

Add to List

Share
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.

*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    
       int n = coins.size();
       
        vector<int> res(amount+1,INT_MAX);
        res[0] = 0;
        
        for(int i =0;i<n;i++){
            for(int j = coins[i];j<=amount;j++){
                if(res[j-coins[i]] != INT_MAX){
                    res[j] = min(res[j],1+res[j-coins[i]] );
                }
            }
        }
        
        return res[amount] != INT_MAX ? res[amount] : -1;
    }
    
    
};
