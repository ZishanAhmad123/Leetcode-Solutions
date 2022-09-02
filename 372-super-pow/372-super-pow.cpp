#define ll long long 
class Solution {
public:
    ll bin_expo(ll a, ll b, ll p){
    a=a%p; if(a==0)return 0;
    ll res=1; while(b>0){
        if(b&1){
            res=(res*a)%p;} a=(a*a)%p;b=b>>1;}
         return res; 
}     
    int superPow(int a, vector<int>& b) {
          int size = b.size() - 1;
        int value = b[0];
        for (int i = 1; i <= size; i++)
        {
            value = (value * 10 + b[i]) % 1140;
        }
        int ans = bin_expo(a, value, 1337);
        return ans;
    }
};