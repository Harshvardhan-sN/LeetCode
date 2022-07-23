class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int n = ranks.size();
        int all_same = count(begin(suits), end(suits), suits[0]);       
        vector<int> v1(14, 0);
        for(int i = 0; i < n; i++)    v1[ranks[i]]++;
        int maxi = *max_element(begin(v1), end(v1));
        if (all_same == n)     return "Flush";
        if (maxi >= 3)      return "Three of a Kind";
        if (maxi == 2)      return "Pair";
        return "High Card";
    }
};