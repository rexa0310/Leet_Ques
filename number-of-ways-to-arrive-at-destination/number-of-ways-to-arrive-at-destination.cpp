class Solution {
    private:
    long long MOD=1e9+7;
    int djkstra( vector<vector<pair<int,long long>>>&adj,int n,int src)
    {
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty())
        {
            long long d = pq.top().first;
             long long u= pq.top().second;
             pq.pop();
            if (d > dist[u]) 
                continue;
            for(auto [v, time] : adj[u]) 
            {
                if (dist[v] > d + time) 
                {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } 
                else if (dist[v] == d + time) 
                    ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
        return ways[n-1]; 
    }
public:
    int countPaths(int n, vector<vector<int>>& v)
    {
      vector<vector<pair<int,long long>>>adj(n);
        for(auto x:v)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        return djkstra(adj,n,0);
    }
};