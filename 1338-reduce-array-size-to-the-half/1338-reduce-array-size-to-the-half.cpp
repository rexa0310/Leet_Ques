class Solution {
public:
    int minSetSize(vector<int>& v) {
        
         unordered_map<int, int> m;
    priority_queue<int> pq;
    for (auto n : v)
        ++m[n];
    for (auto &p : m)
        pq.push(p.second);
    int res = 0, cnt = 0;
    while (cnt * 2 < v.size()) 
    {
        ++res;
        cnt += pq.top();
        pq.pop();
    }
    return res;
    }
};