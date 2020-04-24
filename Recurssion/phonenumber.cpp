/*

17. Letter Combinations of a Phone Number
Medium

3438

382

Add to List

Share
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].




*/


class Solution {
    unordered_map<char, string> num_char {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
     vector<string> output;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() != 0){
            backtrack("",digits,0);
        }
        return output;
        
    }
    
    void backtrack(string combination,string next_digits,int index ){
        if(next_digits.length() == index){
            output.push_back(combination);
        }
        else{
//             I take the first number
           char comb = next_digits[index];
            
            string letters = num_char[comb];
            for(int i =0 ;i<letters.size();i++){
                string letter = num_char[comb].substr(i,1);
                backtrack(combination+letter,next_digits,index+1);
            }
           
        }
    }
};