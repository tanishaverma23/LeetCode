class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int i=0;
        int j=0;

        while(i>=0 && i<n && j>=0 && j<m && !visited[i][j]){
            visited[i][j]=true;
            int next_i=i;
            int next_j=j;
            if(grid[i][j]=='L'){
                next_j--;
            }else if(grid[i][j]=='R'){
                next_j++;
            }else if(grid[i][j]=='U'){
               next_i--;
            }else if(grid[i][j]=='D'){
              next_i++;
            }
            if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m || visited[next_i][next_j]) {
                break; 
            }
            i=next_i;
            j=next_j;
        }
        return {i,j};
    }
};