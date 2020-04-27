/*

739. Daily Temperatures
Medium

2382

71

Add to List

Share
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].


*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        vector<int> output(T.size());
        stack<int> s;
//         we will start from the last so that we know ahead of us what the warmer temperatures are 
        for(int i = T.size()-1; i>= 0;i--){
            
            while(!(s.empty()) && T[i] >= T[s.top()]) s.pop();
            output[i] = s.empty() ? 0: s.top()-i;
             s.push(i);
        }
        
        return output;
       
    }
};
