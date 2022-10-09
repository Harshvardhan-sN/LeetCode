class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        map<int, set<int>> m1;
        int prev = 0;
        for(auto &it: logs){
            m1[int(abs(prev - it[1]))].insert(it[0]);
            prev = it[1];
        }
        auto it = m1.rbegin();
        return  *(it->second.begin());
    }
};