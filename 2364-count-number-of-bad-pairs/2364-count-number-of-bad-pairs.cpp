class Solution {
public:
#define ll long long
    
    ll countBadPairs(vector<int>& nums) {
        //for(ll i=0; i<n; i++){
        //     for(ll j=i+1; j<n; j++){
        //         if((j-i)!=(nums[j]-nums[i]))cnt++;
        //     }
        // }
        // return cnt;
        
         map<ll ,ll>mp;
        ll n=nums.size();
        for(ll i=0;i<n;i++){
            ll diff=nums[i]-i;    // count no. of nums[i]-i
            mp[diff]++;
        }
        ll total=(n*(n-1)/2);
         ll cnt=0;
        
        for(auto it=mp.begin();it!=mp.end();it++){      // travers on Map and find value which has value>=1
            if(it->second>1)
                cnt+=((it->second)*(it->second-1))/2;
            
        }
        return (total-cnt);
        
    }
};