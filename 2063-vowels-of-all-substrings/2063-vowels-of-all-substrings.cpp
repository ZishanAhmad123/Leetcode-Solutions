class Solution {
public:
    long long countVowels(string word) {
         vector<char> f = {'a','e','i','o','u'};
        set<char> s;
        s.insert(f.begin(),f.end());
        long long n = word.length();
        long long sum =0;
        for(long long i=0; i<n; i++)
        {
            if(s.find(word[i])!=s.end())
            {
                sum += (i+1)*(n-i);
            }
        }
        return long(sum);
    }
};