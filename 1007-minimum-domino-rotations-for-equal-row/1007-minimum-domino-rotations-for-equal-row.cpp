class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b)
    {
      vector<int>td(7),bd(7),s(7);
        for(int i=0;i<t.size();i++)
        {
            td[t[i]]++;
            bd[b[i]]++;
            if(t[i]==b[i])
                s[t[i]]++;
        }
        int m=-1;
        for(int i=1;i<7;i++)
        {
            if(td[i]+bd[i]-s[i]==t.size())
             return t.size()-max(td[i],bd[i]);
        }
        return -1;
    }
};