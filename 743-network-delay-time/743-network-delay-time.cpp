class Solution {
    const int N = 1007;
    const int i_max = 7001;
private:
    int dijkstra(int source,int n,vector<pair<int,int>> v1[]){
        vector<int> visit(N,0);
        vector<int> distance(N,i_max);
        
        multiset<pair<int,int>> s1;
        
        s1.insert({0,source});
        distance[source] = 0;
        
        while(s1.size()>0){
            auto node = *s1.begin();
            int v = node.second;
            int v_dist = node.first;
            s1.erase(s1.begin());
            if(visit[v])    continue;
            visit[v] = 1;
            for(auto &it:v1[v]){
                int child = it.first;
                int  wt = it.second;
                if(distance[v]+wt<distance[child]){
                    distance[child] = distance[v]+wt;
                    s1.insert({distance[child],child});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(distance[i]==i_max)  return -1;
            ans = max(ans,distance[i]);
        }
        return ans;
        
    }
public:
    int networkDelayTime(vector<vector<int>>& v1, int n, int k) {
        vector<pair<int,int>> help[N];
        for(auto it:v1){
            help[it[0]].push_back({it[1],it[2]});
        }
        return dijkstra(k,n,help);
    }
};