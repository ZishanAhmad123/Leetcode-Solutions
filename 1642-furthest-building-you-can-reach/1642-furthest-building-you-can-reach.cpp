class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
         int p = heights.size();
        int ans=0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < p-1; i++){
            if(heights[i+1]>heights[i]){
                int diff = heights[i+1]-heights[i];
                q.push(diff);
                if(q.size()<=ladders){
                    continue;
                }
                
                bricks-= q.top();
                q.pop();
                if(bricks<0){
                    return i;
                }
            }  
            }
        return p-1;
    }
};