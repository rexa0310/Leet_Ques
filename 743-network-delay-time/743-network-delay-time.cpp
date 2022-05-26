class Solution {
public:
    int networkDelayTime(vector<vector<int>>& g, int n, int k) {
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        for (int i = 0; i < n; i++)
        {
            for (vector<int> e : g)
            {
                int u = e[0], v = e[1], w = e[2];
                if (dis[u] != INT_MAX && dis[v] > dis[u] + w) 
                    dis[v] = dis[u] + w;
                
            }
        }

        int m = 0;
        for (int i = 1; i <= n; i++)
            m = max(m, dis[i]);
         if(m == INT_MAX)
            return  -1 ;
        return m;
    }
};