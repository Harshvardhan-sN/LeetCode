class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i=0;
        int j=n-1;
        vector<int> v1;
        while( ( numbers[i]+numbers[j] ) != target ){
            if(numbers[i]+numbers[j]>target){
                j--;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
        }
        v1.emplace_back(i+1);
        v1.emplace_back(j+1);
        return v1;
    }
};