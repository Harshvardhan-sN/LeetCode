class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        int ans = 0;
        vector<int> v1;
        int n = rocks.size();
        for(int i=0;i<n;i++){
            int diff = capacity[i]-rocks[i];
            if(diff==0)     ans++;
            else    v1.push_back(diff);
        }
        sort(v1.begin(),v1.end());
        for(int i=0;i<v1.size();i++){
            if(v1[i]<=k and k>0){
                k -= v1[i];
                ans++;
            }   
        }
        return ans;
    }
};