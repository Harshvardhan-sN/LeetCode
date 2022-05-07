class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)    return false;
        int arr[n];
        arr[0] = nums[0];
        for(int i=1;i<n;i++)    arr[i] = min(arr[i-1],nums[i]);    
        
        stack<int> st;
        for(int j=n-1;j>=0;j--){
            if(nums[j]>arr[j]){
                while(!st.empty() and st.top()<=arr[j])     st.pop();
                if(!st.empty() and nums[j]>st.top())        return 1;
            }
            st.push(nums[j]);
        }
        return 0;
    }
};