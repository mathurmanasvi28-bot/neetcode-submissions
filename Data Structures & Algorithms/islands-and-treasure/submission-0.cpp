class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto[row,col] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr = row+dr[k];
                int nc = col + dc[k];
                if(nr >= 0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == INT_MAX ){
                    grid[nr][nc] = grid[row][col] + 1;
                    q.push({nr,nc});
                }
            }
        }
    }
};
