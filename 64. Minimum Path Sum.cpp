// recursive code

class Solution {
    private:
    int f(int i, int j, vector<vector<int>>grid){
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0) return 1e9;

        int up = grid[i][j] + f(i-1,j,grid);
        int left = grid[i][j] + f(i,j-1,grid);

        return min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return f(n-1,m-1,grid);
    }
};

// memoization code

class Solution {
    private:
    int f(int i, int j, vector<vector<int>>&grid,vector<vector<int>> &dp){
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];

        int up = grid[i][j] + f(i-1,j,grid,dp);
        int left = grid[i][j] + f(i,j-1,grid,dp);

        return dp[i][j] = min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
};

// tabulation code

class Solution {
     return dp[i][j] = min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        // return f(n-1,m-1,grid,dp);

        dp[0][0] = grid[0][0];
        for(int i=0;i<n;i++){
            int up =0,left=0;
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[0][0];
                    continue;
                }
                
                if(i>0)
                up = grid[i][j] + dp[i-1][j];
                else
                up = 1e9;

                if(j>0)
                left = grid[i][j] + dp[i][j-1];
                else
                left =1e9;

                dp[i][j] = min(up,left);
            }
        }
        return dp[n-1][m-1];
    }
};

