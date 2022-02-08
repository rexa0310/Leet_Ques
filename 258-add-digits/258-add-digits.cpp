class Solution {
public:
    int addDigits(int num) {
        int s=0;
        while(num>0)
        {
            s+=num%10;
            num/=10;
        }  
        if(s%9==0 && s!=0)
            return 9;
        return s%9;
    }
};