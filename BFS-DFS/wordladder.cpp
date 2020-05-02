/*

127. Word Ladder
Medium

2706

1071

Add to List

Share
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.


*/
class Solution {
      queue<pair<string,int>> q;
        int ans = 0;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
   
//         where 1 returns the level of the beginword
      q.push({beginWord,1});
        unordered_map<string,bool> visited;
        for(auto i : wordList) visited[i] = 1;
        while(!(q.empty())){
            string curr = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(curr == endWord) {
                return depth;
            }
            for(int i =0;i<curr.size();i++){
                string S = curr;
                for(int j =0;j<26;j++){
                    S[i] = (char)('a' + j);
                    if(visited[S]){
                        q.push({S,depth+1});
                        visited[S] = 0;
                    }
                }
            }
            
        }
        return 0;
    }
};
