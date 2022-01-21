class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        auto first = find(seats.begin(),seats.end(),1);
        int ind = first-seats.begin();
        int n = seats.size();
        
        if(ind==n-1)    return n-1;
        // if(count(seats.begin(),seats.end(),1)==1){
        //     int cc=0,flag=0;
        //     for(int i=0;i<n;i++){
        //         if(seats[i]==0){
        //             cc++;
        //             flag = cc;
        //         }
        //         else{
        //             cc=0;
        //         }
        //         flag = max(flag,cc);
        //     }
        //     return flag;
        // }
        int ans1=0,ans2=0;
        int currentpos = ind;
        
        for(int i=ind+1;i<n;i++){
            if(seats[i]==1){
                ans2 = i - currentpos;
                currentpos = i;
            }
            ans1= max(ans2,ans1);
        }
        int l1 = n - currentpos -1;
        return max({l1,ind,ans1/2});
    }
};