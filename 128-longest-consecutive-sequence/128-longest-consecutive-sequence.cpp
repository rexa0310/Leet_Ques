 class DSU{
public:
     vector<int>rank;
    vector<int>par;
    DSU(int n)
    {
        rank.resize(n,1);
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i]=i;
    }
    void merge(int x , int y) //Using Union By Rank
    {
        int xset = find(x);
        int yset = find(y);
 
        if (xset == yset) 
            return;
 
        if (rank[xset] < rank[yset])
        {
            par[xset] = yset;
            rank[yset]+=rank[xset];
        }
        else
        {
            par[yset] = xset;
            rank[xset]+=rank[yset];
        }
    }
    int find(int x)
    {
        if(x==par[x])
            return x;
        return par[x] = find(par[x]);
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();
        
        DSU obj(n);
        
        unordered_map<int,int>pos;
        for(int i=0; i<n; i++)
        {
            int curr = nums[i] , prev = nums[i]-1 , next = nums[i]+1;
            
            if(pos.count(curr))
                continue;
            
            pos[curr] = i;
            
            if(pos.count(prev))
                obj.merge(pos[prev] , pos[curr]);
            
            if(pos.count(next))
                obj.merge(pos[curr] , pos[next]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, obj.rank[i]);
        
        return ans;
    }
};