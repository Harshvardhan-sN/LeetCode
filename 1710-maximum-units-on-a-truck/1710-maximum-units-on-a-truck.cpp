class Solution {
private:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[1]>v2[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        
        for(auto &it : boxTypes){
            if(truckSize<=0)    break;
            int x = min(truckSize, it[0]);
            ans += x*it[1];
            truckSize -= x;
        }
        
        return ans;
    }
};