class SmallestInfiniteSet {
public:
    set<int> s1;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)    s1.insert(i);
    } 
    int popSmallest() {
        int it = *s1.begin();
        s1.erase(it);
        return it;
    }
    
    void addBack(int num) {
        if(s1.count(num)==0)    s1.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */