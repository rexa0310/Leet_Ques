class Solution {
public:
    
       unordered_set<int> st;
    bool isPossible(int n)
    {
        for (int i=0;i<26;i++)
        {
            int curr=(1<<i);
            if ((curr|n)==n && st.find(curr^n)!=st.end())
                return true;
        }
        return false;
    }
    int getMask(string& s)
    {
        int val=0;
        for (auto& i:s)
            val|=(1<<(i-'a'));
        return val;
    }
    int wordCount(vector<string>& arr, vector<string>& target)
    {
        for (auto& i:arr)
            st.insert(getMask(i));
        
        int count=0;
        for (auto& i:target)
        {
            if (isPossible(getMask(i)))
                count++;
        }
        return count;
    }
};