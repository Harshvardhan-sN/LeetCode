class Solution {
public:
    int minDeletions(string s) {
        int arr[26] = {0};
        for(auto &it:s)     arr[it-'a']++;
        sort(arr,arr+26);
        set<int> s1;
        int ans = 0;
        for(int i=0;i<26;i++){
            while(arr[i]>0 and s1.count(arr[i])){
                arr[i]--;
                ans++;
            }
            s1.insert(arr[i]);
        }
        return ans;
    }
};