class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcountll(n);
        // int count = 0;
        // while(n!=0){
        //     n &= n-1;
        //     count++;
        // }
        // return count;
    }
};