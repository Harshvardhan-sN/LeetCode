class Solution {
public:
    string intToRoman(int n) {
	    string ans = "";
        vector<string> v1{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> m1{1000,900,500,400,100,90,50,40,10,9,5,4,1};
	    for(int i = 0;i<13;i++){
            while(n>=m1[i]){
                n -= m1[i];
                ans += v1[i];
            }
        }
        return ans;
    }
};