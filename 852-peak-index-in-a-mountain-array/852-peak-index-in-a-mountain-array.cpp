class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // return max_element(arr.begin(),arr.end()) - arr.begin();
        int l = 0;
        int r = arr.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid]<arr[mid+1]){
                l = mid+1;
            }
            else    r = mid-1;
        }
        return l;
    }
};