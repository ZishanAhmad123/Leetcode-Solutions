class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        unordered_set<int>st(nums.begin(), nums.end());
        while(1){
            if(st.find(i)==st.end())
                return i;
            i++;
        }
    }
};