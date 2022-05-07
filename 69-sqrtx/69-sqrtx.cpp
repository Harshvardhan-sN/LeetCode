class Solution {
public:
    int mySqrt(int n) {
        int l = 1;
        int r = n;
        long long ans = INT_MIN;
        if(n<=1)    return n;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(mid*mid<=n){
                ans = max(ans,mid);
                l = mid+1;
            }
            else        r = mid-1;
        }
        return ans;
    }
};