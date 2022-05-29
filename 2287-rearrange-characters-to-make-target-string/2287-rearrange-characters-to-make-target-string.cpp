// **We will make a map of given target string characters and will also sort the target string**
// ***Then we will make a string for every iteration (in map) till we have required number  of characters***
// ***As the map is already sorted ( so will be the new string obtained ) and we have sorted the target string , So we can compare them after every iteration***
// ```
#define all(x) x.begin(),x.end()
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int> m1;
        
		for(auto &it : s){
            // taking only target string characters
			if (count( all(target) , it )>0)     m1[it]++;
        }
		
        // answer variable
		int ans = 0;
        
		// sorting array 
		sort( all(target) );
        
		while(true){
            string help = "";
			
            for(auto &it : m1){
                // number of charaters req.
				int need = count( all(target) , it.first);
                
				// if req. count of char is availabe or not
				if( it.second >= need){
                    it.second -= need;
                    while(need--)   help += it.first;
                }
            }
			
			// checking the string is same or not  // We have sorted the string and map is already sorted
            if( target == help )    ans++;
            else                break;
        }
        return ans;
    }
};
// ```