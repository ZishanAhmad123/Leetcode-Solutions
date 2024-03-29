 #define mod 1000000007
#define ll long long
class Solution {
public:
   

vector<vector<ll> > tr;
vector<ll> sz;
int n;
vector<ll>fact,  ans;

ll bin_expo(ll a, ll b, ll p){
    a=a%p; if(a==0)return 0;
    ll res=1; while(b>0){
        if(b&1){
            res=(res*a)%p;} a=(a*a)%p;b=b>>1;}
         return res; 
}      
ll mod_inv(ll n, ll p){           // Fermat's Little Theorem
    return bin_expo(n, p-2, p);}  
    
void pre(int n){
    fact.resize(n, 1);
    for(int i = 2;i<n;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}
    
void dfs(int root){
    sz[root] = 1;
    long long prod1 = 1, prod2 = 1,s=0;
    for(auto ch: tr[root]){
        dfs(ch);       
        sz[root]+=sz[ch];     
        ans[root] = (ans[root] * ans[ch])%mod;
        prod1 = (prod1 * fact[sz[ch]])%mod;
    }
    
    prod2 = fact[sz[root] - 1];
    ans[root] = (ans[root] * prod2)%mod;
    ans[root] = (ans[root] * mod_inv(prod1, mod))%mod;
}

int waysToBuildRooms(vector<int>& pr) {
    int n = pr.size();
    tr.resize(n);
    ans.resize(n, 1);
    sz.resize(n, 0);

    // build tree
    for(int i = 1;i < n;i++){
        int par = pr[i];
        tr[par].push_back(i);
    }
    
    // pre compute factorials
    pre(n);
    
    // iterate over the tree
    dfs(0);
    return ans[0];
}
};