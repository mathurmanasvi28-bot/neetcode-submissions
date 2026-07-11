class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, pair<int,int>>>q;
        vector<int>dist(n,1e9);
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        dist[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){

            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if(stops>k) continue;
            for(auto itr:adj[node]){
                int num = itr.first;
                int weight = itr.second;
                if(dis+weight<dist[num] && stops<=k){
                    dist[num] = dis+weight;
                    q.push({stops+1,{num,dis+weight}});
                }

            }

        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};
