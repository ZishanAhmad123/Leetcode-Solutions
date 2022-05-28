class Solution {
public:  void FastIO(){
            ios_base::sync_with_stdio(0);cin.tie(0); }
    
    int xorOperation(int n, int start) {
        FastIO();
      int ans=0;
            for(int i=0; i<n; i++){
              ans^=(start +(2*i ));
            }   
        return ans;
    }
};