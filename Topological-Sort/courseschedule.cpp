/*

207. Course Schedule
Medium

3180

163

Add to List

Share
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5


*/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<int> course(numCourses,0);
        stack<int> s;
        int count = 0;
        for(int i =0;i<prerequisites.size();i++){
//             we have two courses 0 and one and for each I am calculating the course val
          course[prerequisites[i][0]]++;
        }
        for(int i =0;i<course.size();i++){
//              if the course has no prerequisute 
            if(course[i] == 0){
                s.push(i);
            }
        }
        while(!(s.empty())){
            int connected = s.top();
            count++;
            s.pop();
          
            for(int i =0 ;i<prerequisites.size();i++){
                if(prerequisites[i][1] == connected){
                      course[prerequisites[i][0]]--;
                      if(course[prerequisites[i][0]] == 0){
                          s.push(prerequisites[i][0]);
                      }
                }
            }
            
        }
        return count == numCourses;
        
    }
};
