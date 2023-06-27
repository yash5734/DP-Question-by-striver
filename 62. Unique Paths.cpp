// recursive code

class Solution {
    private:
    int f(int i,int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        int up = f(i-1,j);
        int down = f(i,j-1);

        return up+down;
    }
public:
    int uniquePaths(int m, int n) {
        return f(m-1,n-1);
    }
};

// memoization code

class Solution {
    private:
    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int up = f(i-1,j,dp);
        int down = f(i,j-1,dp);

        return dp[i][j] = up+down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0] = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){

                 dp[i][j]=1;
                 continue;
                }
                
                    int up=0,down=0;
                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j>0){
                        down = dp[i][j-1];
                    }
                    dp[i][j] = up+down;
            }
        }
        return dp[m-1][n-1];
    }
};

// tabular code
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                
                int up = 0, down = 0;
                if (i > 0) {
                    up = dp[i - 1][j];
                }
                if (j > 0) {
                    down = dp[i][j - 1];
                }
                
                dp[i][j] = up + down;
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
