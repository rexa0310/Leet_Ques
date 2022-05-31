class Solution {
public:
    int numberOfBeams(vector<string>& v) {
        int pre=0,s=0;
        for(int i=0;i<v.size();i++)
        {
            int cur=0;
            for(int j=0;j<v[0].size();j++)
            {
                if(v[i][j]=='1')
                    cur++;
            }
          //  cout<<cur<<endl;
             if(cur==0)
                 continue;
            else
            {
                s+=pre*cur;
                pre=cur;
            }
            
        }
        return s;
    }
};