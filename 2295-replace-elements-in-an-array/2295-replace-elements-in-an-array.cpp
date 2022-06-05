class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
            unordered_map<int, int>mp;
            for(int i=0; i<nums.size(); i++){
                mp[nums[i]]=i;
            }
        for(int i=0; i<size( operations); i++){
            int newx= operations[i][0];
            int newy= operations[i][1];
            int ind=mp[newx];
            nums[ind]=newy;
            mp.erase(nums[ind]);
            mp[newy]=ind;
        }
        return nums;
    }
};