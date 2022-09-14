class Solution {
public:
    string frequencySort(string s) {
         priority_queue<pair<int,char>> pq;
        unordered_map<char,int> m;

        for(auto ch:s){
            m[ch]++;
        }

        for(auto a:m){
            pq.push({a.second,a.first});
        }

        string res(s.size(),' ');
        int j=0;
        while(pq.size()>0){
            pair<int,char> top_element = pq.top();
            for(int i=0;i<top_element.first;++i){
                s[j]=top_element.second;
                ++j;    
            }
            pq.pop();
        }

        return s;
        
    }
};