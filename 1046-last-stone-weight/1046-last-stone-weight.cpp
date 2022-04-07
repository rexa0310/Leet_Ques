class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int>p;
        for(int i=0;i<v.size();i++)
            p.push(v[i]);
        
        while(p.size()!=1)
        {
            int x=p.top();
            p.pop();
            int y=p.top();
            p.pop();
            p.push(x-y);
        }
        return p.top();
    }
};