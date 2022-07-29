class Solution {
private:
    string fun(string s){
        map<char,int> m1;
        char ch = 'a';
        for(auto &it: s)    m1[it] = ch++;
        for(auto &it: s)    it = m1[it];
        return s;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string newPattern = fun(pattern);
        vector<string> ans;
        for(auto &it: words){
            if(newPattern==fun(it))     ans.emplace_back(it);
        }
        return ans;
    }
};