class Solution {
public:
    static bool cmp(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int> m1;
        int ans = 1;
        for(auto &it:words){
            m1[it] = 1;
            for(int i=0;i<it.length();i++){
                string prev = it.substr(0,i) + it.substr(i+1);
                if(m1.find(prev)!=m1.end()){
                    m1[it] = m1[prev] + 1;
                    ans = max(ans,m1[it]);
                }
            }
        }
        return ans;
    }
};