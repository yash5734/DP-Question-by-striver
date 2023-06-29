//recursive code ----------------------------

class Solution {
    private:
    int f(int i, int j, int n, vector<vector<int>>&arr){
        if(i==n) return arr[i][j];

        int down = arr[i][j] + f(i+1,j,n,arr);
        int diagonal = arr[i][j] + f(i+1,j+1,n,arr);

        return min(down,diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return f(0,0,n-1,triangle);
    }
};

// memoization code ----------------------

class Solution {
    private:
    int f(int i, int j, int n, vector<vector<int>>&arr,vector<vector<int>>&dp){
        if(i==n) return arr[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int down = arr[i][j] + f(i+1,j,n,arr,dp);
        int diagonal = arr[i][j] + f(i+1,j+1,n,arr,dp);

        return dp[i][j] = min(down,diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,n-1,triangle,dp);
    }
};

// tabulation code ---------------

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        dp[0][0] = triangle[0][0];

        for(int i=1;i<n;i++){
            for(int j =0;j<triangle[i].size();j++){
                
                int down = INT_MAX,diag = INT_MAX;
                if(j<triangle[i-1].size())
                down = triangle[i][j] + dp[i-1][j];

                if(j>0)
                diag = triangle[i][j] + dp[i-1][j-1];

                dp[i][j] = min(down,diag);
            }
        }

        int mini =INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,dp[n-1][i]);
        }
        return mini;
    }
};
