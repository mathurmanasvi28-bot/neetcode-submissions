class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int count = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                vis[i] = 1;
                queue<int>q;
                q.push(i);
                vector<int>bfs;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            vis[it] =1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return count;
    }
};
