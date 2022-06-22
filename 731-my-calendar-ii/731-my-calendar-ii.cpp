class MyCalendarTwo {
public:
    
    MyCalendarTwo() {
        
    }
    map<int,int>m;
    bool book(int st, int end) {
       m[st]++;
        m[end]--;
        int c = 0;
        for(auto& x : m)
        {
            c += x.second;
            if(c==3)
            {
                m[st]--;  
                m[end]++;  
                return false;
            }
        }
    
        return true;  
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(st,end);
 */