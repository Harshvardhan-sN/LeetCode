class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)    return false;
        int temp = log2(n);
        int ans = pow(2,temp);
        if( ans==n )    return true;
        return false;
        // if(n<=0 || (n&(n-1)))    return false;
        // return true;
    }
};