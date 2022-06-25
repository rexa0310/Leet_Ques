    bool comp(vector<int> &a,vector<int> &b) 
    {
	return a[1]<b[1];
}
class Solution {

public:
	int eraseOverlapIntervals(vector<vector<int>>& v) {
		int ans=-1;      
		if(v.size()==0) 
            return 0;       
		sort(v.begin(),v.end(),comp);     
		vector<int> prev= v[0];

		for(vector<int> i: v) 
        {
			if(prev[1]>i[0]) 
            {
				ans++;              
			}
            else 
                prev=i;         
		}
		return ans;       
    }
};