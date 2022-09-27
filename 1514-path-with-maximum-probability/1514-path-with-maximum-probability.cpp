class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int , double>>>adj(n);
      int i=0;  
      for(auto x:edges){
       adj[x[0]].push_back({x[1],succProb[i]});
       adj[x[1]].push_back({x[0],succProb[i]});
          i++;
      } 
        vector<double> prob(n, INT_MIN);
        prob[start] = 1;             // bs distance ki jgh pr prob kr diya hai
                                    // hm src se hr node ki max prob store krenge aur last me end wale ka prob return kr                                           denge              
        priority_queue <pair<double, int>> pq;                              
        pq.push({1, start});

        while(!pq.empty()){
            
            double probN = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto nbr: adj[node]){
                
                int childN = nbr.first;
                double probC = nbr.second;
                if( probC * probN > prob[childN]){        // we want max prob at child
                    prob[childN] = probC * probN;
                    pq.push({prob[childN], childN});
                }
            }
        }
        
        if(prob[end] == INT_MIN) return 0;
        return prob[end];
        
    }
};