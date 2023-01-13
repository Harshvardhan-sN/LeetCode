class DataStream {
    map<int, int> m1;
    int val, size;
public:
    DataStream(int value, int k) {
        val = value, size = k;
        m1[value] = k;
    }
    
    bool consec(int num) {
        if(num==val)    m1[val]--;
        else            m1[val] = size;
        return m1[val]<=0;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */