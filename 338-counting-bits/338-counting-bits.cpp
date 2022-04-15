class Solution {
public:
    vector<int> countBits(int n) {
        long i = 0;
        vector<int> v1;
        while(i<=n){
            v1.push_back(__builtin_popcountll(i));
            i++;
        }
        return v1;
    }
};