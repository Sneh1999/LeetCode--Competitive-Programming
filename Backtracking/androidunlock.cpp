/*
351. Android Unlock Patterns
Medium

372

573

Add to List

Share
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

 

Rules for a valid pattern:

Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.
 


 

Explanation:

| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

 

Example:

Input: m = 1, n = 1
Output: 9

*/

class Solution {

    bool used[9];

public:
    int numberOfPatterns(int m, int n) {
        int res = 0;
        
//         number of values possible in a string
        for(int len = m;len<=n;len++){
//             calculates how many strings are possible out of len
            res+= calcPatterns(-1,len);
            for(int i=0;i<9;i++){
                used[i] = false;
            }
        }
        return res;
    }
    
    bool isValid(int index,int last){
        if(used[index]) return false;
//         first digit of the pattern 
        if(last == -1) return true;
//         knight moves to the adjacent cell
        if((index+last) % 2 == 1) return true;
//         indexes are at the end of diagonal 
        int mid = (index+last)/2;
        if(mid == 4) return used[mid];
//         adjacent cells on diagonal
          // adjacent cells on diagonal  - for example 0,0 and 1,0 or 2,0 and //1,1
        if ((index%3 != last%3) && (index/3 != last/3)) {
            return true;
        }
       return used[mid];
        
    }
    
    int calcPatterns(int last, int len){
        if(len == 0) return 1;
        int sum =0;
        for(int i = 0;i<9;i++){
            if(isValid(i,last)){
                used[i] = true;
                sum += calcPatterns(i,len-1);
                used[i] = false;
            }
        }
        return sum;
    }
};