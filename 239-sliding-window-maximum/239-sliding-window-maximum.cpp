class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
    vector<int> ans;
    list<int> l;
    
    while(j<n)
    {
        while(l.size()>0&&l.back()<nums[j])       // calculation
            l.pop_back();
          l.push_back(nums[j]);
        
        if(j-i+1<k)       // window size
            j++;
        
        else if(j-i+1==k)         //   ans---< calculation  ans remove and move
        {
            ans.push_back(l.front());
            if(l.front()==nums[i])
                l.pop_front();
            i++;                     
            j++;
        }
    }
    return ans;
    }
};