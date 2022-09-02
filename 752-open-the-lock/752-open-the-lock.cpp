class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      vector<bool>visited(10000, false);
        unordered_set<string>s;
        for(int i=0;i<deadends.size();i++)
            s.insert(deadends[i]);
        
        if(s.find("0000")!=s.end()) return -1;
        
        queue<string>q;
        q.push("0000");
        visited[0]=true;
        int steps=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                string temp=q.front();
                q.pop();
                if(temp==target) return steps;
                for(int i=0;i<=3;i++)
                {
                    string res=temp,k=temp;
                    res[i]=(((res[i]-'0')+1)%10)+'0';
                    k[i]=(((k[i]-'0')+9)%10)+'0';
                    if(s.find(res)==s.end() && !visited[stoi(res)])
                    {
                        q.push(res);
                        visited[(stoi(res))]=true;
                    }
                    if(s.find(k)==s.end() && !visited[(stoi(k))])
                    {
                        q.push(k);
                        visited[stoi(k)]=true;
                    }
                }
            }
          steps++;
        }
        
        return -1;
    }
};