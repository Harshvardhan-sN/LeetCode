class RandomizedSet {
public:
    map<int,int> m1;
    vector<int> v1;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(m1[val]==0){
            m1[val]++;
            v1.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it = find(v1.begin(), v1.end(), val);
        if(m1[val]==1){
            m1.erase(val);
            v1.erase(it);
            return true;
        }
        else if(m1[val]>1){
            m1[val]--;
            v1.erase(it);
            return true;
        }
        m1.erase(val);
        return false;
    }
    
    int getRandom() {
        return v1[rand()%v1.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */