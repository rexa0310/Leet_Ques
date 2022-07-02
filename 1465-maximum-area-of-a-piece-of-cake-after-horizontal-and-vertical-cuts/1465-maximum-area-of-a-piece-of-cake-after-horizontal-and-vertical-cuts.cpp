class Solution {
public:
    int maxArea(int h, int w, vector<int>& v, vector<int>& v1) {
      
      int n=v.size(), n1=v1.size();
        long long hmax,vmax;
        v.push_back(0);
        v.push_back(h);
        sort(v.begin(), v.end());
		
        
        v1.push_back(0);
        v1.push_back(w);
        sort(v1.begin(), v1.end()); 
        
        int maxh=0;
        for(int i=1; i<v.size(); i++) 
            maxh = max(maxh, v[i]-v[i-1]);
        
        
        
        int maxw=0;
        for(int i=1; i<v1.size(); i++) 
            maxw = max(maxw, v1[i]-v1[i-1]);
        
         
        
        long area = (long) maxh*maxw%1000000007;
        return area;
    
    }
};