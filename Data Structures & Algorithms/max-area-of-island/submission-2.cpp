class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int count = 1;
        queue<pair<int,int>> q;
        q.push({row, col});
        grid[row][col] = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] == 1){
                    grid[nr][nc] = 0;
                    count++;
                    q.push({nr, nc});
                }
            }
        }
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        int most = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    islands++;
                    int z =bfs(i, j, grid);
                    most = max(most,z);
                }
            }
        }
        return most;
    }
};