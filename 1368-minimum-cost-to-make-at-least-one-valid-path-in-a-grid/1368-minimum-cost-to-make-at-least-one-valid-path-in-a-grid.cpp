class Solution {
public:
    int minCost(vector<vector<int>>& g) {
          vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = g.size(), n = g[0].size();
    
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        pq.push(make_pair(0, make_pair(0, 0)));
        while (pq.size())
        {
            auto& z = pq.top();
            int cost=z.first;
            int x=z.second.first;
            int y=z.second.second;
            
            pq.pop();
            
            if (vis[x][y])
                continue;
            
            vis[x][y] = 1;
            
            if (x == m - 1 && y == n - 1)
                return cost;
            for (int i = 0; i < 4; ++i)
            {
                auto &[dx, dy] = dir[i];
                int nx = dx + x, ny = dy + y;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny])
                {
                    if (i == g[x][y] - 1) 
                        pq.push(make_pair(cost,make_pair( nx, ny)));
                     else 
                        pq.push(make_pair(cost + 1,make_pair(nx, ny)));
                }
            }
        }
        return -1;
    }
};