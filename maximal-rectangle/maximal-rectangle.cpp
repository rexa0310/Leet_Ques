class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if(mat.size()==0)return 0;
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> x(n,vector<int>(m));
        vector<vector<int>> y(n,vector<int>(m));
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0'){
                    cnt=0;
                    x[i][j]=cnt;
                }else{
                    cnt++;
                    x[i][j]=cnt;
                }
            }
        }
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[j][i]=='0'){
                    cnt=0;
                    y[j][i]=cnt;
                }else{
                    cnt++;
                    y[j][i]=cnt;
                }
            }
        }
     
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(mat[i][j]!='0')
                 {
                     int w=x[i][j],h=y[i][j],hd;
                     hd=h;
                     int I=i,J=j,hh=1;
                     while(hd>0)
                     {
                        w=min(w,x[I][J]);
                         ans=max(ans,w*hh);
                         I--;hd--;hh++;
                     }
                   
                 }
            }
        }
        return ans;
    }
};