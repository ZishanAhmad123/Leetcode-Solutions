class Solution {
public:
    int getSum(int a, int b) {
      int xor1=a^b;
         unsigned  carry=a&b;
        if(carry==0)return xor1;
        else return getSum(xor1, carry<<1);
    }
};