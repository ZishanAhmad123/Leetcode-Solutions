class Solution {
public:
    typedef pair<int,int> p;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstP) 
    {
        vector<int> ans;
        vector<bool> vis(n, false); 
        vector<vector<p>> adj(n);   
        priority_queue<p, vector<p>, greater<p>> q;    
        int time, person;
        
        q.push({0,0}), q.push({0, firstP});   //because the know at time 0
        
        for(auto i: meetings)  
        {
            adj[i[0]].push_back({i[2], i[1]});  // person - time of meeting, other person with whom meeting
            adj[i[1]].push_back({i[2], i[0]});
        }
        
        while(!q.empty()) 
        {
            time = q.top().first;
            person = q.top().second;
            q.pop();
            
            if(vis[person])     
                continue; 
            
            vis[person] = true;     
            ans.push_back(person);  //visited persons know the secret, jo jo jante ja rhe they will come in answer
            for(auto nbr: adj[person])
                if(vis[nbr.second] == false and nbr.first >= time)  
                    q.push(nbr);
        }
        return ans;
    }
};