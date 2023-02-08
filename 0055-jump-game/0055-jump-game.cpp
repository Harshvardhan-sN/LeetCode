class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0, n = nums.size();
        if(n > 1 and nums[0] == 0)  return 0;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == 0)    continue;
            if(i > reachable)   return 0;
            if(nums[i] + i > reachable)
                reachable = nums[i] + i;
        }
        return reachable >= n - 1;
    }
};

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         queue<int> q1;
//         int n = nums.size();
//         vector<int> dp(n + 1, -1);
//         q1.push(0);
//         while(q1.size()){
//             int position = q1.front();
//             q1.pop();
//             if(dp[position] != -1)   continue; 
//             for(int i = nums[position]; i > 0; i--){
//                 if(i + position == nums.size() - 1)  return 1;
//                 if(i + position < nums.size() and nums[i + position]!=0){
//                     q1.push(i + position);
//                     dp[position] = i + position;
//                 }
//             }
//         }
//         return 0;
//     }
// };