const int M=1000000007;
#define ll  long long
#include "bits/stdc++.h"
class Solution {
public:
     int maxdiff(vector<int>cut,  int lenght){
         sort(cut.begin(), cut.end());
        int  maxdif=cut[0];
         for(int i=1; i<size(cut); i++){
             maxdif= max(maxdif, abs(cut[i]-cut[i-1]));
         }
         maxdif=max(maxdif, lenght-cut.back());
         return maxdif;
     }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        ll x=maxdiff(horizontalCuts, h);
        ll y=maxdiff(verticalCuts, w);
        return (x*y)%M;
    }
};