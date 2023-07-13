class Solution {
    private:
    int f(int ind,int target, vector<int>& nums){

        if(ind ==0){
            return target % nums[0] == 0;
        }

        int notTake = f(ind-1,target,nums);
        int take = 0;
        if(nums[ind]<=target){
            take = f(ind,target-nums[ind],nums);
        }
        return take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        return f(coins.size()-1,amount,coins);
    }
};

// memoization
class Solution {
    private:
    int f(int ind,int target, vector<int>& nums,vector<vector<int>>&dp){

        if(ind ==0){
            return target % nums[0] == 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];

        int notTake = f(ind-1,target,nums,dp);
        int take = 0;
        if(nums[ind]<=target){
            take = f(ind,target-nums[ind],nums,dp);
        }
        return dp[ind][target] = take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return f(coins.size()-1,amount,coins,dp);
    }
};Unbounded Knapsack
