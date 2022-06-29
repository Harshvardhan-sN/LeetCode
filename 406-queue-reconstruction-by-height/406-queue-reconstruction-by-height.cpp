class Solution {
private:
    static bool cmp(vector<int> &v1,vector<int> &v2){
        if(v1[0] > v2[0])     return true;
        if(v1[0] == v2[0] and v1[1] < v2[1])    return true;
        return false;
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(begin(people), end(people), cmp);
        
        vector<vector<int>> ans;
        for(auto &v1 : people){
            ans.insert(begin(ans) + v1[1], v1);
        }
        
        return ans;
    }
};