class Solution {
public:
    int totalFruit(vector<int>&fruits) {
      int n = fruits.size(), i=0, j=0, ans = 0;
    unordered_map<int, int> m;
        int k=2;
    while(j<n)
    {
        m[fruits[j]]++;
        if(m.size()<=k)
        {
            ans = max(ans, j-i+1);
            j++;
        }
        else if(m.size()>k)
        {
            while(m.size()>k)
            {
                m[fruits[i]]--;
                if(m[fruits[i]]==0)
                    m.erase(fruits[i]);
                i++;
            }
            j++;
        }
    }
    return ans;

    }
};