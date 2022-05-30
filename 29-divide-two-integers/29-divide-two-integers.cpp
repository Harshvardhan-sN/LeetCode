class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = ((dividend>0 ^ divisor>0) ? -1 : 1);
        if( dividend==INT_MIN and divisor==-1 ){
            return INT_MAX;
        }
        long a = labs(dividend);
        long b = labs(divisor);
        long ans = 0;
        while(a>=b){
            long temp = b;
            long m = 1;
            while( (temp<<1) <= a){
                temp <<= 1;
                m <<= 1;
            }
            a -= temp;
            ans += m;
        }
        return sign*ans;
    }
};