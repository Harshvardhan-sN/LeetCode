class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        long maxi = *max_element(arr.begin(),arr.end());
        return find(arr.begin(),arr.end(),maxi)-arr.begin();
    }
};