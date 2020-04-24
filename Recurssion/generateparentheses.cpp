/*

22. Generate Parentheses
Medium

4521

245

Add to List

Share
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

//  intresting fact about this solution that the time complexity of this problem is even worse than exponent time , as the increase in time is more with increase in the value of n. 

class Solution {
  
    vector<string> output;
public:
    vector<string> generateParenthesis(int n) {
     
        helper("",n,0,0);
        return output;
    }
    
    void helper(string s,int index,int open,int close){
            if(s.length() == 2*index){
                output.push_back(s);
                return;
            }
           if(open < index){
               helper(s+"(" , index,open+1,close);
           }
            if(close < open){
                helper(s+")" , index,open,close+1);
            }
            
    }
};
