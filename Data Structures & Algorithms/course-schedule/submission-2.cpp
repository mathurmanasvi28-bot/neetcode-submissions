class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& adj){
        visited[node]=1;
        for(auto it : adj[node]){
            if(visited[it]==1){return false;}
            if(visited[it]==0){
                if(dfs(it,visited,adj)==false){return false;}
            }
        }
        visited[node]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(dfs(i,visited,adj)==false){return false;}
            }
        }
       
        return true;
    }
};
