class Solution {
    private:
    void solve(vector<vector<pair<int,int>>> &G, int a, vector<long> &dist)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            dist[a] = 0;
            pq.emplace(0, a);
            while (pq.size()) 
            {
                auto [cost, u] = pq.top();
                pq.pop();
                if (cost > dist[u]) continue;
                for (auto &[v, c] : G[u]) 
                {
                    if (dist[v] > dist[u] + c)
                    {
                        dist[v] = dist[u] + c;
                        pq.emplace(dist[v], v);
                    }
                }
            }
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& v, int s1, int s2, int dest) {
      vector<vector<pair<int,int>>> G(n), R(n);
        for (auto &e : v) 
        {
            long u = e[0], v = e[1], w = e[2];
            G[u].emplace_back(v, w);
            R[v].emplace_back(u, w);
        }
        vector<long> da(n, LONG_MAX), db(n, LONG_MAX), dd(n, LONG_MAX);
        solve(G, s1, da);
        solve(G, s2, db);
        solve(R, dest, dd);
        long ans = LONG_MAX;
        for (int i = 0; i < n; ++i)
        {
            if (da[i] == LONG_MAX || db[i] == LONG_MAX || dd[i] == LONG_MAX)                      continue;
            ans = min(ans, da[i] + db[i] + dd[i]);
        }
        return ans == LONG_MAX ? -1 : ans;
  
    }
};