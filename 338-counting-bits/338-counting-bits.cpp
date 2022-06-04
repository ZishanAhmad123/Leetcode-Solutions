class Solution {
public: int count_1 (int n){
            int cnt=0;
            for (int i = 0; i < 32; i++){
                if (n &(1 << i)) 
                   cnt++; 
            }
            return cnt;
        }
    vector<int> countBits(int n) {
        vector<int>v;
        for(int i=0; i<=n; i++){
            v.push_back(count_1(i));
        }
        return v;
    }
};