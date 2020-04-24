/*
3. Longest Substring Without Repeating Characters
Medium

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.





*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left = 0 , len = 0;
        unordered_map<char,int> map;
        
        for(int right = 0 ;right<s.size();right++){
            if(map.find(s[right]) != map.end()){
//                 this means it exists in the map
                left = max(left, map[s[right]] + 1);
            }
            map[s[right]] = right;
            len = max(len , right - left +1);
        }
        return len;
    }
};
