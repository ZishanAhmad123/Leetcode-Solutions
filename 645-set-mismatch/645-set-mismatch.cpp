class Solution
{
    public:
        vector<int> findErrorNums(vector<int> &nums)
        {
             vector<int>v;
      map<int,int>m;
        for(int i=1;i<=nums.size();i++)
        {
            m[i]=0;
        }
      for(int i=0;i<nums.size();i++)
      {
          m[nums[i]]++;
      }
        for(auto it:m)
        {
            if(it.second==2)
            {
                v.push_back(it.first);
                break;
            }
            
        }
        for(auto it:m)
        {
            if(it.second==0)
            {
                v.push_back(it.first);
                break;
            }
            
        }
        return v;
}
};