class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        //  finding 1st occurance of 1
        auto first = find(seats.begin(),seats.end(),1);
        int ind = first-seats.begin();
        
        // Size of vector
        int n = seats.size();
        
        // if 1st occurnace of 1 is at last index
        // return n-1 lenght that is no. of zeros
        if(ind==n-1)    return n-1;
      
        int ans1=0,ans2=0;
        int currentpos = ind;
        
        // looping through 1st occurance of 1
        // and finding maximum distance between 1's
        for(int i=ind+1;i<n;i++){
            if(seats[i]==1){
                ans2 = i - currentpos;
                currentpos = i;
            }
            ans1= max(ans2,ans1);
        }
        
        // if last element of vector is not 1
        // take the count of zeros after last occurance of 1
        int l1 = n - currentpos -1;
        
        // max of 
                // 1st element is not 1  ----> ind 
                // last element is not 1 ----> l1
                // dis. between 1st    ------> ans1/2
        
        return max({l1,ind,ans1/2});
    }
};