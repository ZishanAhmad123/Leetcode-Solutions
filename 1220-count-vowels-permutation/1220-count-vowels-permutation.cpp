class Solution {
public:
    int mod=1000000007;
    #define ll long long
    int f(int n){
        ll a=1,e=1,i=1,o=1,u=1;
        int count=1;
        while(count<n)
        {
            count++;
            ll ee=(a+i) % mod;
            ll aa=(e+u+i) % mod;
            ll ii=(e+o) % mod;
            ll oo=(i) % mod;
            ll uu=(i+o) % mod;
        
            a=aa;
            e=ee;
            i=ii;
            o=oo;
            u=uu;
        }
        
        return (a+e+i+o+u) % mod;
    }
    int countVowelPermutation(int n) {
        if(n==0)
            return 0;
        return f(n);
    }
};