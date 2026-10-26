class Solution {
    long long dfs(int r, int c,vector<vector<int>>& grid){
        int row=grid.size();
        int col=grid[0].size();
        
       


        if(r<0 || r>=row || c<0 || c>=col || grid[r][c]==0){
            return 0;
        }
        
        long long curr_val=grid[r][c];
        grid[r][c]=0;
        

        curr_val+=dfs(r-1,c,grid);
        curr_val+=dfs(r+1,c,grid);
        curr_val+=dfs(r,c-1,grid);
        curr_val+=dfs(r,c+1,grid);

        return curr_val;

    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) {
                    
                    long long val=dfs(i, j,grid);
                    if(val%k==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};