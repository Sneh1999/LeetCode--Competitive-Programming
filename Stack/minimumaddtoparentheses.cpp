/*

921. Minimum Add to Make Parentheses Valid
Medium

553

42

Add to List

Share
Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.



*/

class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        int neg = 0;
        for(int i = 0;i<S.length();i++){
            if(S[i] == '('){
                s.push(')');
            }
            else{
                if(s.size() == 0){
                    neg++;
                }
                else{
                     s.pop();
                }
               
               
            }
        }
        if(neg && s.size()){
            return neg + s.size();
        }
        else if (neg && s.empty()){
            return neg;    
        }
        else{
            return s.size();
        }
        
    }
};
