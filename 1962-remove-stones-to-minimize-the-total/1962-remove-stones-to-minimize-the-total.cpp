class Solution {
public:
    int minStoneSum(vector<int>& v, int k) {
        priority_queue<int>pq;
        int s=0;
        for(auto x:v)
        {
            s+=x;
            pq.push(x);
        }
        cout<<s;
        while(k--)
        {
            int x=pq.top();
                s-=x/2;
                x=x-(x/2);
            
            pq.pop();
            pq.push(x);
            
        }
        return s;
    }
};