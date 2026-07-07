class Solution {
public:
    bool dfs(int node, vector<int>& visited, stack<int>& st, vector<vector<int>>& adj){
        visited[node]=1;
        for(auto it : adj[node]){
            if(visited[it]==1){return false;}
            if(visited[it]==0){
                if(dfs(it,visited,st,adj)==0){return false;}
            }
        }
        st.push(node);
        visited[node]=2;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses,0);
        stack<int> st;
        vector<int>ans;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(dfs(i,visited,st,adj)==false){return {};}
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};
