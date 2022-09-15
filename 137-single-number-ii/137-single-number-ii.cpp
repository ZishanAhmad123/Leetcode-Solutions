class Solution
{
    public:
        void FastIO()
        {
            ios_base::sync_with_stdio(0);
            cin.tie(0);
        }
    int singleNumber(vector<int> &nums)
    {
        FastIO();
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int cnt1=0, cnt0 = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] &(1 << i)) cnt1++;
                else cnt0++;
            }
            if (cnt1%3)
                ans |= (1 << i);
        }
        return ans;
    }
};