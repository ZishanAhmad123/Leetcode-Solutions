// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
       
//         int left = 0;
//         int right = 0;
//         int ans = 0;
//         set<int>st;
//         while (left < s.length()) {
//             auto it =st.find(s[left]);
//             if(it==st.end()){
//                 if(left-right+1>ans)
//                     ans=left-right+1;
//                     st.insert(s[left]);
//                 left++;
//             }
//             else{
//                 st.erase(s[right]);
//                 right++;
//             }
            
//         }
       
//         return ans;
//     }
// };
class Solution {
public:        
    int lengthOfLongestSubstring(string str) {        
         unordered_map<char, int> mp;
  int max_len = 0;
  int left = 0, right = 0;
  int k;
  while (right < str.size()) {
    ++mp[str[right]];
    k = (right - left + 1);
    if (mp.size() == k) {
      max_len = max(max_len, k);
    } else {
      while (mp.size() < k) {
        char ch = str[left];
        --mp[ch];
        if (mp[ch] == 0) mp.erase(ch);
        left++;
        k--;    // increasing left meaning window size is shrinked.
      }
      if (mp.size() == k) {
        max_len = max(max_len, k);
      }
    }
    right++;
  }
  return max_len;
    }
};