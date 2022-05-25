class Solution {   
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& m1) {
        int n = m1.size();
        sort(m1.begin(),m1.end(),cmp);
        vector<int> help;
        int len = 0;
        for(int i=0;i<n;i++){
            int k1 = m1[i][1];
            int ind = lower_bound(help.begin(),help.end(),k1) - help.begin();
            if(ind>=help.size()){
                help.push_back(k1);
                len++;
            }
            else            help[ind] = k1;
        }
        return len;
    }
};