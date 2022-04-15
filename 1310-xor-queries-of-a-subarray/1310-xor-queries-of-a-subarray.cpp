class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> v1;
        int ans = 0;
        int n = arr.size();
        
        for(int i = 1;i<n;i++){
            arr[i] = (arr[i]^arr[i-1]);  
        }
        for(auto &it:queries){
            int i = it[0];
            int j = it[1];
            if(i>0){
                v1.push_back((arr[j]^arr[i-1]));
            }
            if(i==0)    v1.push_back(arr[j]);
        }
        return v1;
    }
};