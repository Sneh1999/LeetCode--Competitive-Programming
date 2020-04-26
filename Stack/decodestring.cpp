/*

394. Decode String
Medium

2678

133

Add to List

Share
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/

class Solution {
public:
    string decodeString(string s) {
		
        stack<pair<int, string>> st;
        st.push(make_pair(1,""));
        for(int i = 0;i<s.length();i++){
            if(s[i] == ']'){
                string temp = "";
                for(int j = 0;j< st.top().first;j++){
                    temp += st.top().second;
                }
                st.pop();
                st.top().second += temp;
              
            }
            else{
               int num = 0;
                while(isdigit(s[i])){
                        num = num* 10 + (s[i] - '0');
                        i++;
                }
                if(num != 0){
                    st.push(make_pair(num,""));
                }
                else{
                    st.top().second +=s[i];
                }
            }
        }
        return st.top().second;
    }
};
