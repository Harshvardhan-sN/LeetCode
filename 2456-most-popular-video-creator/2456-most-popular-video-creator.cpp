#define ll long long
class Solution {
private:
    static bool cmp(pair<ll,string> p1, pair<ll,string> p2){
        if(p1.first==p2.first)    return p1.second<p2.second;
        return p1.first>p2.first;
    }
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& id, vector<int>& v) {
        vector<vector<string>> ans;
        int n = c.size();
        map<string, ll> m1;
        map<string, vector<pair<ll,string>>> m2;
        ll maxi = INT_MIN;
        for(int i=0; i<n; i++){
            m1[c[i]] += v[i];
            m2[c[i]].push_back(make_pair(v[i], id[i]));
            maxi = max(maxi, m1[c[i]]);
        }
        
        for(auto &[l, r]: m1){
            if(r == maxi){
                sort(m2[l].begin(), m2[l].end(), cmp);
                ans.push_back({l, m2[l].front().second});
            }
        }
        return ans;
    }
};