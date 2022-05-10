class Solution {
    vector<vector<int>> ans;
private:
    void sum(int index,int target,vector<int> &help,vector<int> &v1){
        if(index==help.size()){
            if(target==0)   ans.push_back(v1);
            return;
        }
        if(help[index]<=target){
            v1.push_back(help[index]);
            sum(index,target-help[index],help,v1);
            v1.pop_back();
        }
        sum(index+1,target,help,v1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> m1;
        sum(0,target,candidates,m1);
        return ans;
    }
};