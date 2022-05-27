class Solution {
public:
    bool isPowerOfFour(int num) {
        long long res=1;
        while(res<num){
            res*=4;
        }
        if(res==num)return true;
      else return false;
    }
};