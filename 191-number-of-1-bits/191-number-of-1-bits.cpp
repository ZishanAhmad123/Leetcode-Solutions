class Solution {
public:
    int hammingWeight(uint32_t num) {
        //int n=floor(log2(num))+1;
    int cnt=0;
        for(int i=0; i<32; i++){
            if(num&(1<<i))cnt++;
        }
        return cnt;
    }
};