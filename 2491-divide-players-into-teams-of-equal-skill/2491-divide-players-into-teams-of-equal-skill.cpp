#define ll long long
class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(begin(s), end(s));
        unordered_set<ll> s1;
        ll ans = 0;
        int l = 0, r = s.size()-1;
        while(l<r){
            ll diff = s[l]+s[r];
            s1.insert(diff);
            ans += s[l]*s[r];
            l++,r--;
            if(s1.size()>1)     return -1;
        }
        return ans;
    }
};