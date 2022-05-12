class Solution {
public:
    bool bs(int l, int r,vector<int> &v1,int element,int d){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(abs(element-v1[mid])<=d)   return 0;
            else if(v1[mid]<element)  l = mid+1;
            else                r = mid-1;
        }
        return 1;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(),arr2.end());
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += bs(0,m-1,arr2,arr1[i],d);
        }
        return ans;
    }
};