class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int diff=abs(nums[i]-i);
            if(diff>1)
                return false;
        }
        return true;
    }
};