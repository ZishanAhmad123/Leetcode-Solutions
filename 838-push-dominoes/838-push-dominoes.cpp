class Solution {
public:
    string pushDominoes(string d) {
          int len = d.length();
        string result = d;
        vector<bool> veri(len, false); // verified or not
        queue<int> Q;
        for(int i = 0; i < len; ++i)
        {
            if(d[i] != '.') Q.push(i);
        }
        
        while(!Q.empty())
        {
            int size = Q.size();
            while(size > 0)
            {
                auto idx = Q.front(); Q.pop();
                if(!veri[idx])
                {
                    veri[idx] = true;
                    auto val = result[idx];
                    if(val == 'L' && idx > 0 && !veri[idx-1] && result[idx-1] == '.')
                    {
                        d[idx-1] = d[idx-1] == 'R' ? '.' : 'L';
                        Q.push(idx-1);
                    }
                    else if(val == 'R' && idx < len - 1 && !veri[idx+1] && result[idx+1] == '.')
                    {
                        d[idx+1] = d[idx+1] == 'L' ? '.' : 'R';
                        Q.push(idx+1);
                    }
                }
                size--;
            }
			// update absolute state after full scan
            result = d;
        }
        
        return result;
    }
};