- Double array vector in C++ is made as follows:
  - vector<vector<int>> v;
- to push back to an array to a double vector we say 
  - v.push_back({0,0,0,})
- For sorting we say 
  - sort(nums.begin(),nums.end())
- Set C++
 ```
  set<int> st; 
   for (it1 = st.begin(); it1!=st.end();  ++it1) 
        cout << *it1 << " "; 
   set<vector<int>>s;
   if(s.find({nums[i], nums[l], nums[r]}) == s.end()){
    v.push_back({nums[i], nums[l], nums[r]});
    s.insert({nums[i], nums[l], nums[r]});
    }
 ```
