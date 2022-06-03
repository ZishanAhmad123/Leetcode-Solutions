class Solution {
public:
     int word2Int( string &in) {
        int base = 0;
        for ( auto ch : in) {
            base |= 1 << (ch - 'a');
        }
        return base;
    }
    
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> targets;
        for ( auto word : startWords) {
            int base = word2Int(word);
            // all possible resulting string (in int style)
            for (int i = 0; i < 26; ++i) {
                if (!((1 << i) & base)) {
                    targets.insert(base | (1 << i));
                }
            }
        }
        int res = 0;
        for ( auto word : targetWords) {
            int end = word2Int(word);
            if (targets.count(end)) {
                res++;
            }
        }
        return res;
    }
};