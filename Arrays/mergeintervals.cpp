/*

56. Merge Intervals
Medium

3602

263

Add to List

Share
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

class Solution {
public:
   bool static compare(vector<int>& first, vector<int> second){
        return first[0] < second[0]; 
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return intervals;
        }
        vector<vector<int>> merged;
        vector<vector<int>> output(intervals);
        
        sort(output.begin(),output.end(),compare);
        
        merged.push_back(output[0]);
        
        
        for(int i = 1;i<output.size();i++){
            if(output[i][0] <= merged[merged.size()-1][1]){
          merged[merged.size()-1][1] = max(output[i][1],merged[merged.size()-1][1]);
            }
            else{
                merged.push_back(output[i]);
            }
        }
        return merged;
    }
  
};
