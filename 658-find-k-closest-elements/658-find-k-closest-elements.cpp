class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(auto it: arr){
            int dist = abs(it - x);
            pq.push({dist,it});
        }
        vector<int> res;
        while(!pq.empty() && k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};