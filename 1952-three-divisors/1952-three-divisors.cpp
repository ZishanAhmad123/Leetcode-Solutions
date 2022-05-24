class Solution {
public:
     void FastIO() {
 ios_base::sync_with_stdio(0);cin.tie(0);}
    
    bool isThree(int n) {    
           FastIO();
         int cnt=0;
      
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
            {
                cnt++;
            }
        }
        if(cnt==3)
        {
            return true;
        }
        return false;
    }
};