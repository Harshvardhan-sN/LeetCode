class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> v1(5,1);
        while(--n){
            for(int i=3;i>=0;i--){
                v1[i] += v1[i+1];
            }
        }
        return accumulate(v1.begin(),v1.end(),0);
    }
};

// class Solution {
// public:
//     int countVowelStrings(int n) {
//         int a=1,e=1,i=1,o=1,u=1;
//         while(--n){
//             o+=u;
//             i+=o;
//             e+=i;
//             a+=e;
//         }
//         return a+e+i+o+u;
//     }
// };