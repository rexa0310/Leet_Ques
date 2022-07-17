class Solution {
public:
    bool judgeCircle(string s) {
        int x=0,y=0;
        for(auto i:s)
        {
            if(i=='U')
                x+=2;
            else if(i=='D')
                x-=2;
            else if(i=='R')
                y+=2;
            else
                y-=2;
        }
        if(x==0 && y==0)
            return true;
        return false;
    }
};