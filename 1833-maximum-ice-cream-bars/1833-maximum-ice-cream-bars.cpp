class Solution {
public:
    int maxIceCream(vector<int>& v, int x) {
        int c=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<=x)
            {
                x-=v[i];
                c++;
            }
            else
                break;
            
        }
        return c;
    }
};