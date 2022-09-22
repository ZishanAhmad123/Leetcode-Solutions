class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
         //multiset arranges in lexical order
        
        unordered_map<string,multiset<string>> graph;
        vector<string> result;
        for(auto v:tickets)
        {
            graph[v[0]].insert(v[1]);
        }
        //The reason we are using stack is because if path doesnt exists from small lexical order, we will try the next and store it in stack
        stack<string> s;
        s.push("JFK");      //starting from JFK
        while(!s.empty())
        {
            string src = s.top();
            if(graph[src].size() == 0)          //if we cant move to anywhere from src
            {
                result.push_back(src);
                s.pop();
            }
            else{
                auto dst = graph[src].begin();     //else we pick the place with smaller lexical order and push it into stack.
                s.push(*dst);
                graph[src].erase(dst);          //remove it from adjacency list as we  visited it 
            }
     
        }
        //The order will be stored in reverse as we have used a stack
        reverse(result.begin(),result.end());
        return result;
    }
};