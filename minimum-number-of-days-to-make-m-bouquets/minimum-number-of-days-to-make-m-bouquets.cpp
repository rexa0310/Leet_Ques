class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
        int h=0;
        int n=v.size();
                if(m*k>n)
            return -1;
        for(int i=0;i<n;i++)
            h=max(h,v[i]);

        int l=1,c,cnt;
        while(l<h)
        { 
            c=0,cnt=0;
            int mid=l+(h-l)/2;
            for(int i=0;i<n;i++)
            {
                if(mid>=v[i])
                    c++;
                 else
                 {
                    cnt+=c/k;
                     c=0;
                 }
              
    //           cout<<cnt<<" "<<l<<" "<<h<<endl;

            }
              cnt+=c/k;
         //   cout<<endl;
                if(cnt>=m)
                    h=mid;
                else
                    l=mid+1;
         //  cout<<cnt<<" "<<l<<" "<<h<<endl;
        }
        return l;
    }
};