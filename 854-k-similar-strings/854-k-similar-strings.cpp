class Solution {
public:
    int kSimilarity(string s1, string s2) {
         int n = s1.size();
        queue<pair<string,int>>q;  // (string , steps)
         set<string>seen;
        seen.insert(s1);
        q.push({s1,0});
        
        while(!q.empty()){
            auto [curr,steps] = q.front();
            cout << curr << " ";
            q.pop();
            if(curr==s2)return steps;
            //match untill the match and find where is mismatched occured
            int i = 0;
            while(i < n and curr[i] == s2[i])i++;
            
            for(int j=i+1;j<n;j++){
                if(curr[j]==s2[i]){
                    swap(curr[j],curr[i]);
                    if(seen.count(curr)==0)q.push({curr,steps+1}),seen.insert(curr);
                    swap(curr[j],curr[i]);
                }
            }
        }
        return 0;
    }
};