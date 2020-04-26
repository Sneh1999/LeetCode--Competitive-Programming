/*
20. Valid Parentheses
Easy

4530

207

Add to List

Share
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stackcheck;
        if(s.size() == 0){
            return true;
        }
        
         if(s.size() == 1){
            return false;
        }
        
        for(int i = 0; i< s.size(); i++){
            char c = s[i];
            
            if(c == '}' || c == ']' || c == ')'){
                if(stackcheck.size() == 0){
                    return false;
                }
             
                if(c == '}' && stackcheck.top() != '{')
                    return false;
                if(c == ')' && stackcheck.top() != '(')
                    return false;
                if(c == ']' && stackcheck.top() != '[')
                    return false;
                
                stackcheck.pop() ;
                
                
            }
            else{
                stackcheck.push(c);
            }
        }
        if(stackcheck.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};
