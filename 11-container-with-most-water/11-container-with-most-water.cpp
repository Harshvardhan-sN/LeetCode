class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int low=min(height[i],height[j]);
            int volume=low*(j-i);
            maxi=max(maxi,volume);
            if(height[i]<height[j]) i++;
            else    j--;
        }
        return maxi;
    }
};