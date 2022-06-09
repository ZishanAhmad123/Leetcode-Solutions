class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         unordered_map<int, int>mp;
        for (int i = 0; i < numbers.size(); i++) {
           int rest = target - numbers[i];
            if (mp.find(rest) != mp.end()) {
                return { mp[rest] + 1, i + 1 };
            }
            mp[numbers[i]] = i;
        }
        return { 1456,1071};  
    }
};