class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m1,m2;
        for(auto &it: arr){
            m1[it]++;
        }
        set<int> s1;
        for(auto &[l,r]: m1){
            if(s1.find(r)!=s1.end())    return false;
            s1.insert(r);
        }
        return true;
    }
};