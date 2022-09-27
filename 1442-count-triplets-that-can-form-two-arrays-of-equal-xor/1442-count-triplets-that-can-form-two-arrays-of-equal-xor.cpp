class Solution
{
    public:
        int countTriplets(vector<int> &arr)
        {
            int cnt = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                int val = 0;
                for (int j = i ; j < arr.size(); j++)
                {
                    val = val ^ arr[j];

                    if (val == 0)
                    {
                        cnt += j - i ;
                    }
                }
            }
            return cnt;
        }
};