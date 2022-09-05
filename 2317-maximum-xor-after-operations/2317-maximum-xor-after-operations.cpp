#define ll                long long
class Solution {
public:

    int maximumXOR(vector<int>& nums) {
         vector<ll>cnt(32 , 0);
        for(int i  = 0 ; i<size(nums) ; i++){
            ll num = nums[i];
            ll ind = 0;
            while(num){
                if(num&1) {     // last digit 1
                    cnt[ind]=1;
                }
                num >>= 1;
                ind++;
            }
        }
        ll res = 0;
        // ll n = floor(log2(n))
        for(ll i = 0 ; i<32 ; i++){
            if(cnt[i]!=0)
                res += pow(2 , i);
        }
        return res;
    }
};