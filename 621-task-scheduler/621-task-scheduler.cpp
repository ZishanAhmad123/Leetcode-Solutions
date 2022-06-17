class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> v(26, 0);
        int sz = tasks.size();
        for(int i = 0; i < sz; i++) {
            v[tasks[i] - 'A']++;
        }
        sort(v.begin(), v.end());
        int minlen = (n + 1) * (v[25] - 1) + 1;
        for(int i = 24;i >= 0; i--) {if(v[i] == v[25]) minlen++;}
        return max(minlen, sz);  
    }
};