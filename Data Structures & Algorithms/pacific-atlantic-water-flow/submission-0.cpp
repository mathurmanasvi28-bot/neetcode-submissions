class Solution {
public:
    vector<vector<bool>> bfs(int m, int n, queue<pair<int,int>>& q, vector<vector<int>>& grid){
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        while(!q.empty()){
            auto[row,col] = q.front();
            q.pop();
            visited[row][col] = true;
            for(int k=0;k<4;k++){
                int nr = row+dr[k];
                int nc = col + dc[k];
                if(nr >= 0 && nr<m && nc>=0 && nc<n && grid[nr][nc] >= grid[row][col] && !visited[nr][nc]){
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int,int>> p;
        queue<pair<int,int>> a;
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            p.push({i,0});     
            a.push({i,n-1});   
        }
        for(int j = 0; j < n; j++){
            p.push({0,j});     
            a.push({m-1,j});  
        }
        vector<vector<bool>> visited_p = bfs(m,n,p,heights);
        vector<vector<bool>> visited_a = bfs(m,n,a,heights);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited_p[i][j] == true && visited_a[i][j]== true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
