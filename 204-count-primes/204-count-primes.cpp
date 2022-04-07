#define ll long long
class Solution {
public:
    
    int countPrimes(int n) {
        if(n<=1)    return 0;
        bool prime[n+1];
        memset(prime,0,sizeof prime);
        prime[0] = prime[1] = 1;

        for(ll i = 2;i*i<=n; i++){
            if(!prime[i]){
                for(ll j = i*i;j<=n;j+=i){
                    prime[j] = 1;
                }
            }
        }
    
        int ans = 0;
        for(int i=2;i<n;i++){
            if(!prime[i])   ans++;
        }
        return ans;
    }
};