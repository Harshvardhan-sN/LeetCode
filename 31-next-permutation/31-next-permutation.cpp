class Solution {
public:
    void nextPermutation(vector<int>& v1) {
        int n = v1.size();
        int i,l;
        for(i=n-2;i>=0;i--){
            if(v1[i]<v1[i+1])   break;
        }
        if(i<0){
            reverse(v1.begin(),v1.end());
        }
        else{
            for(l=n-1;l>i;l--){
                if(v1[l]>v1[i])     break;
            }
            swap(v1[i],v1[l]);
            reverse(v1.begin()+i+1,v1.end());
        }
    }
};