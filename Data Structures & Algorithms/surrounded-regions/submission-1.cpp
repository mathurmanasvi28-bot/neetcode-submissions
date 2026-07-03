class Solution {
public:
    void bfs(int m, int n, queue<pair<int,int>>& q, vector<vector<char>>& grid){
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        while(!q.empty()){
            auto[row,col] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr = row+dr[k];
                int nc = col + dc[k];
                if(nr >= 0 && nr<m && nc>=0 && nc<n && grid[nr][nc] =='O'){
                    grid[nr][nc] ='*';
                    q.push({nr,nc});
                }
            }
            
        }
             
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>>q;
        for(int i = 0; i < m; i++){
            if(board[i][0]=='O'){
                board[i][0]='*';
                q.push({i,0});     
            }   
            if(board[i][n-1] == 'O'){
                board[i][n-1]='*';
                q.push({i,n-1});
            }
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                board[0][j]='*';
                q.push({0,j});     
            }  
            if(board[m-1][j] == 'O'){
                board[m-1][j]='*';
                q.push({m-1,j});
            }
        }
        bfs(m,n,q,board);
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};
