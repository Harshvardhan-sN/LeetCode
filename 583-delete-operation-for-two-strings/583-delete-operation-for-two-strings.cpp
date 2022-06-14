class Solution {
public:
    int lcs(string &s1,string &s2,int i,int j,vector<vector<int>> &v1){
        if(i==s1.length() || j==s2.length())    return 0;
        if(v1[i][j]!=-1)    return v1[i][j];
        if(s1[i]==s2[j])    v1[i][j] = 1 + lcs(s1,s2,i+1,j+1,v1);
        else{
            v1[i][j] = max(lcs(s1,s2,i+1,j,v1),lcs(s1,s2,i,j+1,v1));
        }
        return v1[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> v1(n,vector<int>(m,-1));
        return (n+m)-(lcs(word1,word2,0,0,v1)<<1);
    }
};