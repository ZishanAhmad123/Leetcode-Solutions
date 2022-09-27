class Solution {
    vector<vector<pair<int, int>>> graph;
    vector<int> distance;
    vector<int> dp;
    int N;

    // O(E)
    int dfs(int u) {
        if (dp[u] != -1) return dp[u];
        if (u == N) return 1;
        int ans = 0;

        for (auto e : graph[u]) {
            int v = e.second;
            if (distance[v] >= distance[u]) continue;
            ans = (ans +  dfs(v)) % 1000000007;
        }
        return dp[u] = ans;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        N = n;
        graph = vector<vector<pair<int, int>>>(n + 1);
        // O(E)
        for (auto e : edges) {
            graph[e[0]].push_back({e[2], e[1]});
            graph[e[1]].push_back({e[2], e[0]});
        }

        // djikstra
        distance = vector<int>(n + 1, INT_MAX);
        dp= vector<int>(n + 1, -1);
        distance[n] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, n});

        // O(ElogV)
        while (!q.empty()) {
            int u = q.top().second; int d = q.top().first;
            q.pop();

            for (auto e : graph[u]) {
                int v = e.second; int wt = e.first;
                if (distance[v] <= wt + d) continue;
                distance[v] = wt + d;
                q.push({wt + d, v});
            }
        }

        return dfs(1);
    }
};