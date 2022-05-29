class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m1;
        for(auto &it:s)     m1[it]++;
        multimap<int,char> s1;
        for(auto &it:m1)    s1.insert({it.second,it.first});
        string ans = "";
        for(auto it = s1.rbegin();it!=s1.rend();it++) {
            for(int i=0;i<it->first;i++){
                ans += it->second;
            }
        }
        return ans;
    }
};