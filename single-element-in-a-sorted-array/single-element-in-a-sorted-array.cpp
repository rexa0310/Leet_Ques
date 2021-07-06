class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int l=0,h=v.size()-1;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(mid%2 ==1 && v[mid]==v[mid-1])
                l=mid+1;
            else if(mid%2==0 && v[mid]==v[mid+1])
                l=mid+1;
            else 
                h=mid;
            cout<<l<<" "<<h<<endl;
        }
        return v[l];
    }
};