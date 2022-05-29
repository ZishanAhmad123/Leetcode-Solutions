#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string toHex(int num) {
        if (num==0)return "0";
            unsigned int n = num; 
         string res;
        while(n){
            int rem=n%16;
            if(rem>9){
            res+='a'+ (rem-10);    
            }
            else
                res+=to_string(rem);
            n=n/16;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};