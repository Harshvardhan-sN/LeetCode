//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void dfs(int start, vector<int> &nums,  vector<int> &res, int sum){
        if(start == nums.size()){
            res.push_back(sum);
            return;
        }
        sum += nums[start];
        dfs(start + 1, nums, res, sum);
        sum -= nums[start];
        dfs(start + 1, nums, res, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N){
        // sort(nums.begin(), nums.end());
        vector<int> res;
        dfs(0, arr, res, 0);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends