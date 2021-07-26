class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& v) {
         if(v.empty())return {};
        vector<int>ans;
        for(int i=0;i<v.size();i++)
        {
            if(v[abs(v[i])-1]>0)
            v[abs(v[i])-1]=-v[abs(v[i])-1];
        }
        for(int i=0;i<v.size();i++)
            if(v[i]>0)
                ans.push_back(i+1);
                
        return ans;
    }
};
   