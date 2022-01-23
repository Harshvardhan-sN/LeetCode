class Solution {
public:
    vector<int> findLonely(vector<int>& a) {
        unordered_map<int,int> m1;
        for(auto &it:a){
            m1[it]++;
        }
        vector<int> v1;
        for(auto &it:a){
            if(m1[it]==1 && m1.count(it+1)==0 && m1.count(it-1)==0){
                v1.emplace_back(it);
            }
        }
        
        return v1;
    }
};