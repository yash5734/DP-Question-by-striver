// recursive solution tc - O(n*k) sc - O(n)

class Solution {
    private:
    int f(int ind, int k, vector<int>& arr) {
        if (ind == 0) return 0;
        int mini = INT_MAX;
        for (int i = 1; i <= k; i++) {
            if( ind - i >= 0){
            int sum = f(ind - i, k, arr) + abs(arr[ind] - arr[ind - i]);
            mini = min(mini, sum);
            }
        }
        return mini;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        // int mini = INT_MAX;
        return f(n-1,k,height);
    }
};

// memoization code 

class Solution {
    private:
    int f(int ind, int k, vector<int>& arr,vector<int>&dp) {
        if (ind == 0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int mini = INT_MAX;
        for (int i = 1; i <= k; i++) {
            if( ind - i >= 0){
            int sum = f(ind - i, k, arr,dp) + abs(arr[ind] - arr[ind - i]);
            mini = min(mini, sum);
            }
        }
        return mini;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        // int mini = INT_MAX;
        vector<int>dp(n,-1);
        return f(n-1,k,height,dp);
    }
};

// tabulation

class Solution {
    private:
    int f(int ind, int k, vector<int>& arr,vector<int>&dp) {
        if (ind == 0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int mini = INT_MAX;
        for (int i = 1; i <= k; i++) {
            if( ind - i >= 0){
            int sum = f(ind - i, k, arr,dp) + abs(arr[ind] - arr[ind - i]);
            mini = min(mini, sum);
            }
        }
        return mini;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        // int mini = INT_MAX;
        vector<int>dp(n,0);
        dp[0] =0;
        
        for(int i=1;i<n;i++){
            int mini = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                   int jumps = dp[i-j] + abs(height[i]-height[i-j]);
                    mini = min(mini,jumps);
                }
            }
            dp[i] = mini;
        }
        return dp[n-1];
        
    }
};
