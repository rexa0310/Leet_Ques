class Solution {
public:
     vector<int>v;
    vector<int>ans;
    Solution(vector<int>& x) {
        v.assign(x.begin(),x.end());
        ans.assign(x.begin(),x.end());
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        random_shuffle(ans.begin(),ans.end());        
       return ans;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(x);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */