class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            int row = current.first.first;
            int col = current.first.second;
            int count = current.second;

            time = count;
            
            for(int k=0;k<4;k++){
                int nr = row+dr[k];
                int nc = col + dc[k];
                if(nr >= 0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1 ){
                    grid[nr][nc] = 2;
                    q.push({{nr,nc},count+1});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return time;
    }
};
