class Solution {
    vector<vector<int>> ans;
private:
    void solve(int i, int max, int k,vector<int> &v1){
        if(v1.size()==k and max==0){
            ans.push_back(v1);
            return;
        }
        for(int index = i;index<=9;index++){
            v1.push_back(index);
            solve(index+1,max-index,k,v1);
            v1.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v1;
        solve(1,n,k,v1);
        return ans;
    }
};