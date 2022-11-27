class Solution {
public:
    int bestClosingTime(string c) {
        int total = count(c.begin(), c.end(), 'Y');
        int ans = total, curr, k = 0, j = 0;
        for(int i=0; i<c.size(); i++){
            if(c[i]=='Y'){
                k++;
                curr = total - k;
                if(ans>curr){
                    ans = curr;
                    j = i+1;
                }
            }
            else    k--;
        }
        return j;
    }
};