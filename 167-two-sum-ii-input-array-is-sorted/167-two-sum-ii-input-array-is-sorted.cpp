class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int T) {
        int n = arr.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int req = T-arr[i];
            if(binary_search(arr.begin()+i+1,arr.end(),req)){
                int index = lower_bound(arr.begin()+i+1,arr.end(),req) - arr.begin();
                ans.push_back(i+1);
                ans.push_back(index+1);
                break;
            }
        }
        return ans;
    }
};