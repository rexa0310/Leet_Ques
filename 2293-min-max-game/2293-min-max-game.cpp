class Solution {
public:
    int minMaxGame(vector<int>& v) {
        int n=v.size();
        while(n>1)
        {
            int j=0;
            for(int i=0;i<n/2;i++)
            {
                if(j%2==0)
                    v[j]=min(v[2*i],v[2*i+1]);
                else 
                    v[j]=max(v[2*i],v[2*i+1]);
                j++;
            }
            n/=2;
        }
        return v[0];
    }
};