class Solution {
public:
    int wateringPlants(vector<int>& v1, int c) {
        int ans = 0;
        int need = c;
        for(int i=0;i<v1.size();i++){
            if(need<v1[i]){
                ans += ((i+1)<<1)-1;
                need = c-v1[i];
            }
            else{
                ans++;
                need -= v1[i];
            }
        }
        return ans;
    }
};