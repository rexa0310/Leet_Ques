class Solution {
public:
    int minimumDeviation(vector<int>& nums)
    {
          int res = INT_MAX, mini = INT_MAX;
        priority_queue<int> pq;
        for (auto n : nums)
        {
            if(n%2)
                n=n*2;
            pq.push(n);
            mini = min(mini, n); 
        }
        while (pq.top() % 2 == 0)
        {
            res = min(res, pq.top() - mini);
            mini = min(mini, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        return min(res, pq.top() - mini);
}
};