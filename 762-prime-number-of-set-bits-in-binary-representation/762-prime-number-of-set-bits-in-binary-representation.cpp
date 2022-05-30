class Solution {
public:
   bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int                 i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
   
      int count_1 (int n){
            int cnt=0;
            for (int i = 0; i < 32; i++){
                if (n &(1 << i)) 
                   cnt++; 
            }
            return cnt;
        }
    
    
    int countPrimeSetBits(int left, int right) {
        vector<int>v;
        
        for(int i=left; i<=right; i++){
            v.push_back( count_1(i)) ;
        }
        
        int cnt=0;
        for(auto x: v){
            if(isPrime(x))cnt++;
        }
        return cnt;
    }
};