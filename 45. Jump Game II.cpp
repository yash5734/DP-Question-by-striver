class Solution {
    private:
    int f(int ind,  int n, vector<int>&arr,vector<int>&dp){

        if(ind>=n){
            return 0;
        }

        if(dp[ind]!=-1) return dp[ind];

        int val = arr[ind];
        int mini = 1e5;

        for(int i=1;i<=val;i++){
          mini = min(mini, 1+f(ind+i,n,arr,dp));
        }

        return dp[ind] = mini;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(0,n-1,nums,dp);
    }
};
