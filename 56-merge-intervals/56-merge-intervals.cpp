class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> v1;
        vector<int> help = a[0];
        for(auto &it:a){
            if(it[0]<=help[1]){
                help[1] = max(help[1],it[1]);
            }
            else{
                v1.emplace_back(help);
                help = it;
            }
        }
        v1.emplace_back(help);
        return v1;
    }
};