typedef pair<int,pair<int, int>> pii;
class Solution {
public:
    int n, m;
    bool isValid(int x, int y){
        if(x >= 0 && y >= 0 && x < n && y < m)return true;
        return false;
    }
    int trapRainWater(vector<vector<int>>& hm) {
        n = hm.size(); m = hm[0].size();
        vector<vector<int>> dir {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i=0; i<n; i++){
            pq.push({hm[i][0],{i,0}});
            pq.push({hm[i][m-1],{i,m-1}});
            vis[i][0] = true;
            vis[i][m-1] = true;
        }
        for(int i=0; i<m; i++){
            pq.push({hm[0][i],{0,i}});
            pq.push({hm[n-1][i],{n-1,i}});
            vis[0][i] = true;
            vis[n-1][i] = true;
        }
        int res = 0;
        int mxh = 0;
        while(!pq.empty()){
            int sz = pq.size();
            while(sz--){
                auto a = pq.top();
                pq.pop();
                int h = a.first, x = a.second.first, y = a.second.second;
                mxh = max(mxh, h);
                for(auto d: dir){
                    int dx = x + d[0], dy = y + d[1];
                    if(isValid(dx, dy) && !vis[dx][dy]){
                        res+=max(0, mxh - hm[dx][dy]);
                        pq.push({hm[dx][dy], {dx, dy}});
                        vis[dx][dy] = true;
                    }
                }
            }
        }
        return res;
        
    }
};