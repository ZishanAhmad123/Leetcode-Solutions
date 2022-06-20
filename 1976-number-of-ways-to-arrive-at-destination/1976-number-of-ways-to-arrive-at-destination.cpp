
#define ll long long

class Solution
{
    public:
        int mod = 1e9 + 7;
    int countPaths(int n, vector<vector < int>> &roads)
    {

        priority_queue<pair<ll, ll>, vector< pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({ 0,0 });
        vector<ll> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<ll> ways(n, 0);
        ways[0] = 1;

        vector<pair<ll, ll>> adj[n];
        for (auto &it: roads)
        {
            adj[it[0]].push_back({ it[1],
                it[2] });
            adj[it[1]].push_back({ it[0],
                it[2] });
        }
            while (!pq.empty())
            {
                ll node = pq.top().second;
                ll dis = pq.top().first;
                   pq.pop();
                 for (auto it: adj[node])
                {
                    ll wt = it.second;
                    ll adjnode = it.first;
                    if (wt + dis < dist[adjnode])
                    {
                        dist[adjnode] = wt + dis;
                        ways[adjnode] = ways[node];
                        pq.push({ dist[adjnode],
                            adjnode });
                    }
                    else if (wt + dis == dist[adjnode])
                    {
                        ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                    }
                }
            }

            return ways[n - 1];
        }
    };