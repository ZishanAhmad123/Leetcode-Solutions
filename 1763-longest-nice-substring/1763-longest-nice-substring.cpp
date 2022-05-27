class Solution
{
    public:
        bool isNice(string s)
        {
            map<char, int> mp;
            for (auto &i: s) mp[i]++;

            for (auto &i: s)
            {
                if (i >= 'A' && i <= 'Z')
                {
                    if (mp[i + 32] == 0) return 0;
                }
                else if (mp[i - 32] == 0) return 0;
            }

            return 1;
        }
    string longestNiceSubstring(string s)
    {
        string ans = "";
        int max_length = 0;

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                string str = s.substr(i, j - i + 1);
                if (isNice(str))
                {
                    if (str.length() > max_length)
                    {
                        max_length = str.length();
                        ans = str;
                    }
                }
            }
        }

        return ans;
    }
};