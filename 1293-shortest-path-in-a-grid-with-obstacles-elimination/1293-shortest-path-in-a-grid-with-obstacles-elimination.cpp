class Solution {
public:
    bool safe(int x,int y,int n,int m)
    {
        return x>=0 and y>=0 and x<n and y<m;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},k});
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        int ans=0;
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
            auto f=q.front();
                q.pop();
                int i=f.first.first;
                int j=f.first.second;
                int cnt=f.second;
               
                if(i==n-1 and j==m-1)
                    return ans;
                for(int c=0;c<4;c++)
                {
                    int x=i+dx[c];
                    int y=j+dy[c];
                    if(safe(x,y,n,m) )
                    {
                     if(grid[x][y]==0 and !vis[x][y][cnt])
                     {
                         q.push({{x,y},cnt});
                         vis[x][y][cnt]=1;
                     }
                        else if(grid[x][y] and cnt>0 and !vis[x][y][cnt-1])
                        {
                            q.push({{x,y},cnt-1});
                            vis[x][y][cnt-1]=1;
                        }
                    }
                }
                
            }
            ans++;
        
        }
        return -1;
    }
};