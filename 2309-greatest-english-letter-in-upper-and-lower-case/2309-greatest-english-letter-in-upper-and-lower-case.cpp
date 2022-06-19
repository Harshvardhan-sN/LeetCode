class Solution {
public:
    string greatestLetter(string s) {
        int n = s.length();
        string ans = "";
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // Diff of lower and upper is 32
                if(abs(s[i]-s[j])==32){
                    string req = "";
                    req += (s[i]>s[j] ? s[j] : s[i]);  // Checking lower and upper
                    ans = max(ans,req);     // greatest Char
                }    
            }
        }
        
        return ans;
    }
};