class Solution {
public:
    string subStrHash(string s, int p, int mod, int k, int target) {
        long h = 0, N = s.size(), pp = 1;
        int pos = -1;
        string r(rbegin(s), rend(s)); //reverse string
        for (int i = 0; i < N; ++i) {
            if (i < k) pp = pp * p % mod; //final value of p^k in pp
            h = (h * p + (r[i] - 'a' + 1)) % mod; 
            if (i - k >= 0) { 
                h = (h - (r[i - k] - 'a' + 1) * pp % mod + mod) % mod;
            }
            if(h == target) pos = i; //store position of last  matching target
        }
        if(pos == -1) return "";
        pos = N-pos-1;  //position in reverse string
        return s.substr(pos, k); 
    }
};