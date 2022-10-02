class Solution {
public:
    bool checkValid(vector<vector<int>>& m) {
        int n = m.size();
        for(int i=0; i<n; i++){
            vector<bool> v1(n+1, 0);
            v1[0] = 1;
            for(int j=0; j<n; j++){
                v1[m[i][j]] = 1;
            }
            if(count(begin(v1), end(v1), false))    return false;
        }
        for(int i=0; i<n; i++){
            vector<bool> v1(n+1, 0);
            v1[0] = 1;
            for(int j=0; j<n; j++){
                v1[m[j][i]] = 1;
            }
            if(count(begin(v1), end(v1), false))    return false;
        }
        return true;
    }
};