class Solution {
private:
    int sum(int n){
        int ans = 0;
        while(n>0){
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
public:
    int maximumSum(vector<int>& nums) {
        map<int,multiset<int>> m1;
        long long maxi = 0, mn = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            int s = sum(nums[i]);
            m1[s].insert(nums[i]);
        }
        
        for(auto it = m1.rbegin();it!=m1.rend();it++){
            if(it->second.size()>=2){
                maxi = 0;
                auto i = it->second.end();
                maxi += *(--i);
                maxi += *(--i);
                mn = max(maxi,mn);
            }
        }
        if(maxi==0)     return -1;
        return max(maxi,mn);
    }
};