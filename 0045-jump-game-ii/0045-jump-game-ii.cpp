class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        queue<pair<int, int>> q1;
        vector<int> dp(n + 1, -1);
        q1.push({0, 0});
        while(q1.size()){
            int position = q1.front().first;
            int cost = q1.front().second;
            q1.pop();
            if(position == n - 1)   return cost;
            if(dp[position] != -1)  continue;
            for(int i = nums[position]; i > 0; i--){
                if(i + position <= n - 1){
                    q1.push({position + i, cost + 1});
                    dp[position] = position + i;
                }
            }
        }
        return 0;
    }
};