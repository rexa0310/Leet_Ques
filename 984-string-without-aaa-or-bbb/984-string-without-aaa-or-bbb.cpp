class Solution {
public:
    string strWithout3a3b(int x, int y) 
    {
        string res;
        while (x && y)
        {
            if (y > x)
            {
                res += "bba";
                y--;
            } 
            
            else if (x > y) 
            {
                res += "aab";
                x--;
            } 
            
            else
                res += "ab";
            
            x--;
            y--;
        }
        while (x--) 
            res += "a";
        while (y--) 
            res += "b";
        return res;
    }
};