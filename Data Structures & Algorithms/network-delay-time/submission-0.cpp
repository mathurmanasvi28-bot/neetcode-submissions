class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        set<pair<int,int>>st;
        vector<int>dis(n+1,1e9);
        st.insert({0,k});
        dis[k]=0;
        int mintime = 0;
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dist = it.first;
            st.erase(it);
            for(auto it: adj[node]){
                int neigh = it.first;
                int weight = it.second;
                if(dist+weight < dis[neigh]){

                    if(dis[neigh] != 1e9)
                        st.erase({dis[neigh],neigh});

                    dis[neigh] = dist+weight;
                    st.insert({dis[neigh],neigh});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9)
                return -1;

            mintime=max(mintime,dis[i]);
        }
        return mintime;
       
    }
};
