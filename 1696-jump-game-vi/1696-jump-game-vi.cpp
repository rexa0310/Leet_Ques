class Solution {
public:
    int maxResult(vector<int>& v, int k) {
      deque<int> d{0};
        for (int i = 1; i < v.size(); ++i) {
            if (d.front() + k < i)
                d.pop_front();        
            v[i] += v[d.front()];
            while (!d.empty() && v[d.back()] <= v[i])
                d.pop_back();
            d.push_back(i);
        }
        return v.back();
}
};