class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
       map<int, int> m;
public:
    int book(int s, int e) {
        m[s]++; 
        m[e]--; 
        int c = 0, k = 0;
        for (pair<int, int> t : m)
            k = max(k, c += t.second);
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */