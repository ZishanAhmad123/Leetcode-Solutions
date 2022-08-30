#include "bits/stdc++.h"
class Solution {
public:
  static bool cmp(string a,string b){
    return a+b > b+a;
}
    string largestNumber(vector<int>& nums) {
         vector<string>v;
        
        for(auto s:nums){
            v.push_back(to_string(s));
        }
        
        sort(v.begin(),v.end(), cmp);
      
        //for(auto x: v)cout<<x<<" ";
        string str = "";
        for(int i=0;i<nums.size();i++){
        str+=v[i];
        }
        while(str[0]=='0' and str.size()>1)str.erase (0, 1);
        return str;
    }
};