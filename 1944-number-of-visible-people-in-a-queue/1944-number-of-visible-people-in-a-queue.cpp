class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& v)
    {
        int n = v.size();
        vector<int> ans(n,0);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) 
        {
            while (!st.empty() && v[i] > st.top()) 
            {
                st.pop();
                ++ans[i];
            }
            if (!st.empty())
                ++ans[i];
            st.push(v[i]);
        }
        return ans;
    }
};