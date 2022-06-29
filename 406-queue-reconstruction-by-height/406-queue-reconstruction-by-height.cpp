class Solution {
public:
   static bool sortPeople(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] > b[0];
    }
        
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
        sort(people.begin(), people.end(), sortPeople);
        vector<vector<int>> q;
        
        for(vector<int> p : people){
            q.insert(q.begin()+p[1],p);
        }
        
        return q;
    }
};