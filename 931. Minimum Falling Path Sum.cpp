class Solution {
private:
    int f(int i, int j, int m, vector<vector<int>>& matrix){
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[i][j];

        int up = matrix[i][j] + f(i-1,j,m,matrix);
        int leftDiagonal = matrix[i][j] + f(i-1,j-1,m,matrix);
        int rightDiagonal = matrix[i][j] + f(i-1,j+1,m,matrix);

        return min(up,min(leftDiagonal,rightDiagonal));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = INT_MAX;

        for(int j=0;j<m;j++){
            mini = min(mini,f(n-1,j,m,matrix));
        }
        return mini;
    }
};

// memoization code=---------------

class Solution {
private:
    int f(int i, int j, int m, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int up = matrix[i][j] + f(i-1,j,m,matrix,dp);
        int leftDiagonal = matrix[i][j] + f(i-1,j-1,m,matrix,dp);
        int rightDiagonal = matrix[i][j] + f(i-1,j+1,m,matrix,dp);

        return dp[i][j] = min(up,min(leftDiagonal,rightDiagonal));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int j=0;j<m;j++){
            mini = min(mini,f(n-1,j,m,matrix,dp));
        }
        return mini;
    }
};

// tabular code ------------------
class Solution {}
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<m;i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j = 0;j<m;j++){
                int up = matrix[i][j] + dp[i-1][j];
                int leftDiagonal = INT_MAX;
                if(j>0)
                leftDiagonal = matrix[i][j] + dp[i-1][j-1];
                 
                int rightDiagonal = INT_MAX;
                if(j+1<m)
                rightDiagonal = matrix[i][j] + dp[i-1][j+1]; 

                dp[i][j] = min(up,min(leftDiagonal,rightDiagonal));
            }
        }

        int mini = INT_MAX;
        for(int i=0;i<m;i++){
            mini = min(mini, dp[n-1][i]);
        }
        return mini;
    }
};
