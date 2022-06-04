#include "bits/stdc++.h"
#define ll long long
class Solution
{
    public:
        int numberOfArrays(vector<int> &differences, int lower, int upper)
        {
         ll mini = 0;
        ll maxi = 0;
        ll c =0;
            
        for (int d: differences) {
             c += d;

              mini=min(mini, c);
              maxi=max(maxi, c);
        }

       return max(0ll, upper - lower - (maxi - mini) + 1);
}
};