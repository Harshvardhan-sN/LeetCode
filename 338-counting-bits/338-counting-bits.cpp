class Solution {
public:
    long f(long i){
        long c = 0;
        while(i){
            c++;
            i &= (i-1);
        }
        return c;
    }
    vector<int> countBits(int n) {
        long i = 0;
        vector<int> v1;
        while(i<=n){
            v1.push_back(f(i));
            i++;
        }
        return v1;
    }
};