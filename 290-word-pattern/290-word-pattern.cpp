class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> m1;
        unordered_map<string,int> m2;
        vector<string> v1;
        int n = pattern.length();
        s += ' ';
        string  word = "";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                v1.emplace_back(word);
                word="";
            }
            else{
                word+=s[i];
            }
        }
        
        // string word;
        // stringstream s1(s);
        // while(s1>>word){
        //     v1.emplace_back(word);
        // }
        if(n!=v1.size())    return false;
        
        for(int i=0;i<n;i++){
            if(m1[pattern[i]]!=m2[v1[i]]){
                return false;
            }
            m1[pattern[i]] = i+1;
            m2[v1[i]] = i+1;
        }
        
        return true;
    }
};