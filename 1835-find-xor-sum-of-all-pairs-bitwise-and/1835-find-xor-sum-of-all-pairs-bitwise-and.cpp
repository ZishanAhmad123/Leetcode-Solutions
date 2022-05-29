#include "bits/stdc++.h"
using namespace std;
#define ll                long long

class Solution {
public: void FastIO(){
            ios_base::sync_with_stdio(0);cin.tie(0); }
//     The original: (a1 & x1) ^ (a1 & x2) ^ (a2 & x1) ^ (a2 & x2)
//     can be simplified to: (x1 ^ x2) & (a1 ^ a2)
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        FastIO();
        
        ll xor1=0, xor2=0;
       for(int i=0; i<arr1.size(); i++){
            xor1=xor1^arr1[i];
       }
         for(int i=0; i<arr2.size(); i++){
            xor2=xor2^arr2[i];
       }
        return (xor1&xor2);
    }
};