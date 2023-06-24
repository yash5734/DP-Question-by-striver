// method 1 -> memoization 

class Solution {
    private:
    int f(vector<int>& height, int n, vector<int>&dp){
        if(n == 0) return 0;
        if(dp[n]!=-1) return dp[n];
        int left = f(height,n-1,dp) + abs(height[n]-height[n-1]);
        int right = INT_MAX; // if n = 1 then n-2 reaches -1 so to handle this 
        if(n>1){ //we take a condn that if and only if n-2 run if n>1 so it can not reaches out less then 0
        right = f(height,n-2,dp) + abs(height[n]-height[n-2]);
        }
        return dp[n]=min(left,right);
        
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return f(height,n-1,dp);
    }
};

// Using Tabulation Form 

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,0);
        
        dp[0] =0;
        for(int i=1;i<n;i++){
            int left = dp[i-1] + abs(height[i]-height[i-1]);
            int right = INT_MAX;
            if(i>1)
            right = dp[i-2] + abs(height[i]-height[i-2]);
            
            dp[i] = min(left,right);
        }
        return dp[n-1];
    }
};

// optimise way


class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,0);
        // return f(height,n-1,dp);
        
        int prev2 =0;
        int prev =0;
        for(int i=1;i<n;i++){
            int left = prev + abs(height[i]-height[i-1]);
            int right = INT_MAX;
            if(i>1)
            right = prev2 + abs(height[i]-height[i-2]);
            
            int curr = min(left,right);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
