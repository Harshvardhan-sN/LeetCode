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