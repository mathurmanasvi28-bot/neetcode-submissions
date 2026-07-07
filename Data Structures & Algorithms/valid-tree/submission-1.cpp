class Solution {
public:
    bool dfs(int node, int parent,vector<int>& visited, vector<vector<int>>& adj){
        visited[node]=1;
        for(auto it : adj[node]){
            if(visited[it]==0){
                if(dfs(it,node,visited,adj)==0){return false;}
            }
            else if(it!=parent){return false;}
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges){
        vector<vector<int>>adj(n);
        vector<int> visited(n,0);
        for(auto it: edges){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        if(dfs(0,-1,visited,adj)==false){return false;}
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                return false;
            }
        }
        return true;   
    }
};
