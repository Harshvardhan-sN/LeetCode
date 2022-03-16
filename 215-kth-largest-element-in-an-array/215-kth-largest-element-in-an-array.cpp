class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int> pq;
    	for(int i:arr)  pq.push(i);
	    k--;
	    while(k--){
		    pq.pop();
	    }
	
	    return pq.top();
    }
};