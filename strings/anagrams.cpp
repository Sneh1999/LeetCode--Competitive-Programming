/*
49. Group Anagrams
Medium

2171

134

Favorite

Share
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.



*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> copy;
       if(strs.size() == 0) return {};
        std::unordered_map<string,vector<string>> mp;
        
        for(int i = 0;i< strs.size() ;i++){
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            mp[curr].push_back(strs[i]);
        }
        for (auto& x: mp){
            copy.push_back(x.second);
        }
        return copy;
    }
};
