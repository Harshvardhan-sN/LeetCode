class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int p) {
        vector<int> v1,v2,ans;
        int cc = 0;
        for(auto &it:a){
            if(it<p)   v1.push_back(it);
            else if (it==p)   cc++;
            else        v2.push_back(it);
        }
        ans.insert(ans.begin(),v1.begin(),v1.end());
        int m1 = ans.size();
        while(cc--){
            ans.push_back(p);
        }
        ans.insert(ans.end(),v2.begin(),v2.end());
        
        return ans;
    }
};