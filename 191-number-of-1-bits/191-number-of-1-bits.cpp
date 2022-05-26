class Solution {
public:
    int hammingWeight(uint32_t num) {
        int cnt=0;
       while(num){
           if(num&1){
               cnt++;
           }
           num=num>>1;
       }
        return cnt;
    }
};