class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        int totcap=jug1Capacity+jug2Capacity;
        int steps[]={jug1Capacity,-jug1Capacity,jug2Capacity,-jug2Capacity};
        vector<bool>vis(totcap,false);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int filled=q.front();
            q.pop();
             vis[filled]=1;
            if(filled==targetCapacity)
            {
                return true;
            }
            for(int i=0;i<4;i++)
            {
                int nfilled=filled+steps[i];
                if(nfilled>=0 && nfilled<=totcap && !vis[nfilled])
                {
                    q.push(nfilled);
                    vis[nfilled]=1;
                }
            }
        }
        return false;
    }
};