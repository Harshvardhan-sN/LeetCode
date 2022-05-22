class Solution {
    int dp[1007][1007];
private:
    int result(int i,int j,string &h){
        if(i>=j)    return 1;
        if(dp[i][j])    return dp[i][j];
        if(h[i]!=h[j])   return 0;
        return dp[i][j] = result(i+1,j-1,h);
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                ans += result(i,j,s);
            }
        }
        return ans;
    }
};