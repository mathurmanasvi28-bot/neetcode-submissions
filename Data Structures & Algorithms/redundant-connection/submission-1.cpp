class Solution {
public:
    int find(int node, vector<int>& parent){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find(parent[node],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1);
        for(int i = 0; i<edges.size(); i++){
            parent[i] = i;
        }
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int pu = find(u,parent);
            int pv = find(v,parent);
            if(pu==pv){
                return edge;
            }
            parent[pu]=pv;
        }
        return {};
    }
};
