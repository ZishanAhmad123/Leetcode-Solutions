#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
     
 
    
    ll mod_inv(ll n, ll p){           // Fermat's Little Theorem
    return bin_expo(n, p-2, p);} 
    
    ll bin_expo(ll a, ll b, ll p){
    a=a%p; if(a==0)return 0;
    ll res=1; while(b>0){
        if(b&1){
            res=(res*a)%p;} a=(a*a)%p;b=b>>1;}
         return res; 
}   
    
    int makeStringSorted(string s) {
        long long ans = 0;
        map<int, long long> freq; 
        for (char& c: s){
            freq[c - 'a']++;
        }
        vector<long long> fact(s.size() + 1, 1ll);
        for (int i = 1; i <= s.size(); i++){
            fact[i] = (fact[i - 1] * i)%mod;
        }
         
        int l = s.size();
        for (char c: s){
            l--;
            long long t = 0, rev = 1;
            for (int i = 0; i < 26; i++){
                if (i < c - 'a')
                    t += freq[i];
                rev = (rev * fact[freq[i]])%mod;
                
            }
            ans += (t*fact[l]%mod) * mod_inv(rev, mod );
            ans %= mod;
            freq[c - 'a']--;
        }
        return ans; 
    }
};