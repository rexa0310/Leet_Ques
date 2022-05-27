class Solution {
public:
    int canCompleteCircuit(vector<int>& u, vector<int>& v) {
        int n=v.size();
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            x+=v[i];
            y+=u[i];
        }
        if(x>y)
            return -1;
        int st=0,c=0;
        for(int i=0;i<n;i++)
        {
            if(c<0)
            {
                st=i;
                c=0;
            }
            c+=u[i]-v[i];
        }
        return st;
    }
};