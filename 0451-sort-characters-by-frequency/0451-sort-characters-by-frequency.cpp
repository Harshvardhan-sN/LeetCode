class Solution {
public:
    static bool cmp(pair<char, int> p1, pair<char, int> p2){
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int> m1;
        vector<pair<char, int>> v1;
        for(char &ch: s)    m1[ch]++;
        for(auto &[l,r]: m1)    v1.emplace_back(l,r);
        sort(begin(v1), end(v1), cmp);
        string ans = "";
        for(auto &[l,r]: v1){
            int k = r;
            while(r--)      ans += l;
        }
        return ans;
    }
};
// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> m1;
//         for(auto &it:s)     m1[it]++;
//         multimap<int,char> s1;
//         for(auto &it:m1)    s1.insert({it.second,it.first});
//         string ans = "";
//         for(auto it = s1.rbegin();it!=s1.rend();it++) {
//             for(int i=0;i<it->first;i++){
//                 ans += it->second;
//             }
//         }
//         return ans;
//     }
// };