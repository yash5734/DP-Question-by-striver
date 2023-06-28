// recursion code

class Solution {
    int f(int n,int m, vector<vector<int>>obstacleGrid){
        if(n == 0 && m==0 && obstacleGrid[n][m]!=1) return 1;
        if(n<0||m<0) return 0;
        if(obstacleGrid[n][m]==1) return 0;

        int left = f(n,m-1,obstacleGrid);
        int up = f(n-1,m,obstacleGrid);
        return left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        return f(n-1,m-1,obstacleGrid);
    }
};

// memoization code

class Solution {
    int f(int n,int m, vector<vector<int>>obstacleGrid, vector<vector<int>> &dp){
        if(n == 0 && m==0 && obstacleGrid[n][m]!=1) return 1;
        if(n<0||m<0) return 0;
        if(obstacleGrid[n][m]==1) return 0;
        if(dp[n][m]!=-1) return dp[n][m];

        int left = f(n,m-1,obstacleGrid,dp);
        int up = f(n-1,m,obstacleGrid,dp);
        return dp[n][m] = left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
    }
};

// tabular code

class Solution {
    int f(int n,int m, vector<vector<int>>obstacleGrid, vector<vector<int>> &dp){
        if(n == 0 && m==0 && obstacleGrid[n][m]!=1) return 1;
        if(n<0||m<0) return 0;
        if(obstacleGrid[n][m]==1) return 0;
        if(dp[n][m]!=-1) return dp[n][m];

        int left = f(n,m-1,obstacleGrid,dp);
        int up = f(n-1,m,obstacleGrid,dp);
        return dp[n][m] = left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        // return f(n-1,m-1,obstacleGrid,dp);
        dp[0][0] = 0;
        for(int i=0;i<n;i++){
            int left =0;
            int up =0;
            for(int j=0;j<m;j++){
                if(i==0&&j==0 && obstacleGrid[i][j]!=1){
                    dp[i][j] =1;
                    continue;
                }
                if(obstacleGrid[i][j]!=1){
                    if(j>0)
                    left = dp[i][j-1];
                    if(i>0)
                    up = dp[i-1][j];
                    dp[i][j] = left+up;
                }
            }
        }
        return dp[n-1][m-1];
    }
};
