class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi = *max_element(arr.begin(),arr.end());
        return find(arr.begin(),arr.end(),maxi)-arr.begin();
    }
};