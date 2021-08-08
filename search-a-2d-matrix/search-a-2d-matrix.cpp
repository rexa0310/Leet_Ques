class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target)
    {
        int n=mat.size();
        int m=mat[0].size();
        int l=0,h=n;
        int mid;
         while(l<h)
         {
             mid=l+(h-l)/2;
             if(target>=mat[mid][0] && target <=mat[mid][m-1])
                 break;
             else if(target>=mat[mid][m-1])
                 l=mid+1;
             else h=mid;
         }
      //  cout<<mid;
        
        l=0,h=m;
        while(l<h)
        {
            int x=l+(h-l)/2;
           // cout<<x;
             if(mat[mid][x]==target)
                 return true;
            if(mat[mid][x]<target)
                l=x+1;
            else 
                h=x;
        }
        return false;
    }
};