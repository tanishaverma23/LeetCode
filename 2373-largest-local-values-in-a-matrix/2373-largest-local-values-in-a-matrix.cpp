class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size() - 2;
        int m = grid[0].size() - 2;
        vector<vector<int>> maxLocal(n, vector<int>(m));

        for (int i = 0; i < grid.size() - 2; i++) {
        for(int j=0;j<grid.size()-2;j++){

            int maxi=INT_MIN;
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    maxi=max(maxi,grid[k][l]);
                }
            }
            maxLocal[i][j]=maxi;
        }
        }

        return maxLocal;
    }
};