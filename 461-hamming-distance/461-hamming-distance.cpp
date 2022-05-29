class Solution
{
    public:
        int count(int n){
            int cnt=0;
            for (int i = 0; i < 32; i++){
                if (n &(1 << i)) {
                   cnt++; 
                }
            }
            return cnt;
        }
    int hammingDistance(int x, int y)
    {
        int xor1 = x ^ y;
        return count(xor1);
    }
};