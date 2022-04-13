class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
          vector<vector<int> > res(n,vector<int>(n));
        int i=0,j=0,cur=1;
        while(n>0){
            res[i][j]=cur++;
            n--;
            int step=n;
            while(step>0){
                res[i][++j]=cur++;
                step--;
            }
            step=n;
            while(step>0){
                res[++i][j]=cur++;
                step--;
            }
            step=n--;
            while(step>0){
                res[i][--j]=cur++;
                step--;
            }
            step=n;
            while(step>0){
                res[--i][j]=cur++;
                step--;
            }
            j++;
        }
        return res;
    }
};