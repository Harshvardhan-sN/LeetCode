class Solution {
public:
    void sortColors(vector<int>& v1) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for(auto &it:v1){
            if(it==0)   zero++;
            else if(it==1)  one++;
            else        two++;
        }
        int i = 0;
        while(i<zero)   v1[i++] = 0;
        while(i<one+zero)    v1[i++] = 1;
        while(i<one+zero+two)   v1[i++] = 2;
    }
};