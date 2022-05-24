
class Solution {
 public:
    int sumdigit(int  n){ if(n==0)return 0;return n%10 +sumdigit(n/10);}
   
    int getLucky(string s, int k) {
        int sum=0;
        for(auto c: s){
            sum+=sumdigit(c-'a'+1);
        }
       k--;
        while(k){
            sum=sumdigit(sum);
            k--;
        }
        return sum;
    }
};