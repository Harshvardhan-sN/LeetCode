class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& ma) {
        unordered_map<int,int> two;
        set<int> s1;
        for(auto &it: ma){
            two[it[1]]++;
            s1.insert(it[0]);
            s1.insert(it[1]);
        }
        vector<int> a1,a2;
        for(auto &it: s1){
            if(two.find(it)==two.end())     a1.push_back(it);
            if(two[it]==1)                  a2.push_back(it);
        }
        return {a1,a2};
    }
};