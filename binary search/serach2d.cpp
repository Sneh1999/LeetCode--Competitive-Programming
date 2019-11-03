/*
74. Search a 2D Matrix
Medium

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false





*/



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i = 0 ; i< matrix.size(); i++){
            vector<int> mat = matrix[i];
             
            int l = 0;
            int r = mat.size() -1 ;
            bool result = binarySearch(mat,l ,r, target);
            if(result){
                return result;
            }
             std::cout<<result;
        }
        return false;
        
    }
    
    
    bool binarySearch(vector<int> mat,int l , int r, int target){
       
       if(l>r){
           return false;
       }
       
          int mid = (l + r)/2 ;
        
        if(mat[mid] == target){
            return true;
        }
        
        else if(mat[mid] > target){
         
          return binarySearch(mat, l , mid -1 , target);
                  
            
        }
        else{
          
                   return binarySearch(mat, mid+1,r , target);
            
           
           
        }  
// [[1,3,5,7],[10,11,16,20],[23,30,34,50]]
// 13
        
//        
       
    
}
             };
