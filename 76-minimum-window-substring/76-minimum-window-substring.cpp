class Solution {
public:
    string minWindow(string s, string t) {
    int n = s.length(), m1 = t.length(), i = 0, j = 0, count, a1 = INT_MAX;
    string ans;
    unordered_map<char, int> m;
    for(int i=0; i<m1; i++)
        m[t[i]]++;
        
    count = m.size();
    while(j<n)
    {
        if(m.find(s[j])!=m.end())
        {
            m[s[j]]--;
            if(m[s[j]]==0)
                count--;
        }
        while(count==0)
        {
            if(a1>j-i+1)
            {
                a1 = j-i+1;
                ans = s.substr(i, a1);
            }
            
            if(m.find(s[i])!=m.end())
                {
                    m[s[i]]++;
                    if(m[s[i]]==1)
                        count++;
                }
            
            i++;
         }
         j++;
    }
    return ans;
    }
};