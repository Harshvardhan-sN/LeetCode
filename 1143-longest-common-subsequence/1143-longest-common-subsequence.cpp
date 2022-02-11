class Solution {
public:
    int dp[1007][1007];

    int f(int i,int j,string &s1,string &s2){
        if(i<0 || j<0)  return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int ans = f(i-1,j,s1,s2);
        ans = max(ans,f(i,j-1,s1,s2));
        ans = max(ans,f(i-1,j-1,s1,s2)+(s1[i]==s2[j]));
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n = text1.length();
        int m = text2.length();
        return f(n-1,m-1,text1,text2);
    }
};