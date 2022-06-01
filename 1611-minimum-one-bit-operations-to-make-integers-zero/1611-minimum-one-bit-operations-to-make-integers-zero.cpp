class Solution {
public:
    int minimumOneBitOperations(int n) {
        
          for(int i=31;i>=0;i--){
            if(n&(1<<i)){
                return pow(2,i+1)-1 - minimumOneBitOperations(n^(1<<i));
            }
        }
        return 0;
    }
};