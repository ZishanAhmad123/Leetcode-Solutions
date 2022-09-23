class Solution {
public:

#define ll long long int 
 ll mod = 1e9 + 7 ; 
 void FastIO() {
 ios_base::sync_with_stdio(0);cin.tie(0);}
    
    int concatenatedBinary(int n) {
       FastIO();
         ll i,sum=1,x;
        for(i=2;i<=n;i++)
        {
            x=log2(i)+1;
            sum=sum*pow(2,x)+i;
            sum=sum%mod;
        }
        return sum;
    }
};