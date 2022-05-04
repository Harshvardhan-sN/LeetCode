class Solution {
public:
    int maxOperations(vector<int>& v1, int k) {
        sort(v1.begin(),v1.end());
        
        int count = 0;
        int start = 0, end = v1.size()-1;
        
        while(start<end){
            if(v1[start]==-1)   start++;
            if(v1[end]==-1)     end--;
            else{
                long x = v1[start]+v1[end];
                if(k==x){
                    count++;
                    v1[start++] = -1;
                    v1[end--]   = -1;
                }
                else if(x<k)    start++;
                else            end--;
            }
        }
        return count;
    }
};