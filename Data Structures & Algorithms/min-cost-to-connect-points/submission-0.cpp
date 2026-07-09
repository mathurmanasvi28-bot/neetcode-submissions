class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        set<pair<int,int>>st;
        vector<int>dis(n+1,1e9);
        vector<int> vis(n,0);
        st.insert({0,0});
        dis[0]=0;
        int mintime = 0;
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dist = it.first;
            st.erase(it);
            if(vis[node])
                continue;
            vis[node]=1;
            mintime += dist;
            for(auto it: adj[node]){
                int neigh = it.first;
                int weight = it.second;
                if(!vis[neigh] && weight < dis[neigh]){
                    if(dis[neigh] != 1e9)
                        st.erase({dis[neigh],neigh});

                    dis[neigh] = weight;
                    st.insert({dis[neigh],neigh});
                }
            }
        }
        return mintime;
        
    }
};
