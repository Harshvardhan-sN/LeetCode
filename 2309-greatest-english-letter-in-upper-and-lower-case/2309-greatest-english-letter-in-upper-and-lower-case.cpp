class Solution {
public:
    string greatestLetter(string s) {
        int n = s.length();
        string ans = "";
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(abs(s[i]-s[j])==32){
                    string req = "";
                    req += (s[i]>s[j]?s[j]:s[i]);
                    ans = max(ans,req);
                }    
            }
        }
        return ans;
    }
};