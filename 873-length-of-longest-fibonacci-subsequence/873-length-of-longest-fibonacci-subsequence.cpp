class Solution {
public:
    unordered_map< int,int> m;
    int lenLongestFibSubseq(vector<int>& v) 
    {
        for(int i=0;i<v.size();i++) 
            m[v[i]]=i;
        
        int x1,ans=0,mx=0;

        for(int i=0;i<v.size()-2;i++)
        {
            for(int j=i+1;j<v.size()-1;j++)
            {
                int y=j;
                int x=i;
                while( m.find( v[x]+v[y]) !=m.end())
                {
                    x1=m[v[x]+v[y]];
                    x=y;
                    y=x1;
                    ans++;
                }
                mx=max(mx, ans+2);
                ans=0;
            }
        }
        if(mx<3)
            return 0;
        return mx;
    }
};
