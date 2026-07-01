class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int islands = 0;
        int dr[] = {-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] ==  '1' && !visited[i][j]){
                    islands++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j];
                    while(!q.empty()){
                        auto[row,col] = q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr = row+dr[k];
                            int nc = col + dc[k];
                            if(nr >= 0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == '1' && !visited[nr][nc]){
                                visited[nr][nc] = true;
                                q.push({nr,nc});
                            }
                        }
                    }

                }
            }
        }
        return islands;
    }
};
