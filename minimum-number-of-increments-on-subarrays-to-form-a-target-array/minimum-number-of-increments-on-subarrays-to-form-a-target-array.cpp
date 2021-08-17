class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int s=0,p=0;
        for(int i=0;i<target.size();i++)
            s+=max(target[i]-p,0),p=target[i];
        
        return s;
    }
};