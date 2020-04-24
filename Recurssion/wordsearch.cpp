/*
79. Word Search
Medium

3107

154

Add to List

Share
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

// the time complexity for this would be O(N⋅4^L) and space complexity is  O(L) 

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        bool val;

        for(int row = 0;row<board.size();row++){
           for(int col =0;col<board[0].size();col++){
               val = backtrack(board,word,row,col,0);
               if(val){
                   return true;
               }
           }
           
        }
        return false;
    }
    bool backtrack(vector<vector<char>>& board, string word,int row, int col ,int index){
        if(index == word.length()){
            return true;
        }
        
        if( row <0 ||  row == board.size() || col<0 || col == board[0].size() ||  board[row][col] != word[index] ){
            return false;
        }
        
        vector<int> rows = {0, 1, 0, -1};
        vector<int> cols = {1, 0, -1, 0};
        bool ret = false;
//         we are doing this in case all the values lead to a false path
        board[row][col] = '!';
        
        for(int i =0;i<4;i++){
            ret = backtrack(board,word,row + rows[i], col+ cols[i], index+1);
            if(ret){
              return true;
            }
        }
        board[row][col] = word[index];
        return false;
    }
};
