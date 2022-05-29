class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> m1;
        int maxi = 0;
		
        for(int i=0;i<senders.size();i++){
			// min. no. of words per sender
            int req = 1;
			
			// count spaces
            for(auto &it:messages[i])   if(it==' ') req++;
            
			// insert it into map
			m1[senders[i]] += req;
			
			// get the max value in map
            maxi = max(maxi,m1[senders[i]]);
        }
		// using set for highest order string
		set<string> s1;
		
        for(auto &it:m1){
		
            // string correponding to max value of map
			if(it.second==maxi){
                s1.insert(it.first);
            }
        }
		
		// last element of set
        return *(--s1.end());
    }
};