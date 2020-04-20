# include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> hmap;
      vector<int> sum;
        for(int i = 0; i< nums.size(); i++){
            int complement = target - nums[i];
            if(hmap.find(complement) != hmap.end()){
                sum.push_back(i);
                sum.push_back(hmap[complement]);
                return sum;
                }
            else {
                hmap[nums[i]] = i;
            }
            }
        return sum;
    }
};
