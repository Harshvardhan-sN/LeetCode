class Solution {
public:
    long long smallestNumber(long long num) {
        vector<long long> v1;
        long long n = num,l1 = 0,l2 = 0;
        while(abs(num)>0){
            v1.push_back(num%10);
            num/=10;
        }
        long long m1 = v1.size();               // 0 0 0 1 2 3 
        if(n==0)    return 0;
        if(n>0){
            sort(v1.begin(),v1.end());
            long long cc = count(v1.begin(),v1.end(),0);
            if(cc>0){
                l1 = v1[cc];
                l1 = double(l1 * (pow(10,cc)) );
                cc++;
                for(long long i=cc;i<m1;i++){
                    l1 = l1*10 + v1[i];
                }
                return l1;
            }
            for(long long i=0;i<m1;i++){
                l1 = l1*10 + v1[i];
            }
            return l1;
        }
        sort(v1.begin(),v1.end());
        l1 = v1[0];
        for(long i=1;i<m1;i++){
            l1 = l1*10 + v1[i];
        }
        return l1;
    }
};