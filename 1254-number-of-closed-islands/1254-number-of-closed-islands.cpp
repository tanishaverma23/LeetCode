class Solution {
    bool dfs(int r,int c, vector<vector<int>>&grid){
        int rows=grid.size();
        int cols=grid[0].size();

        if(r<0 || r>=rows || c<0 || c>=cols){
            return false;
        }

        if (grid[r][c] == 1) {
            return true;
        }

        grid[r][c] = 1;

       bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        bool up = dfs(r - 1, c, grid);
        bool down = dfs(r + 1, c, grid);

        return left && right && up && down;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int closedIslands=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    if(dfs(i,j,grid)){
                        closedIslands++;
                    }
                }
            }
        }
        return closedIslands;
    }
};