class Solution {
    private:
    bool f(int ind, vector<int>&nums,vector<int>&dp){
        
    // base condition
    if(ind==nums.size()) return true;

    if(dp[ind]!=-1) return dp[ind];
    
    //condition 1;
    if(ind+1<nums.size() && nums[ind]==nums[ind+1]){
        if(f(ind+2,nums,dp)) return dp[ind] = true;

        // condition 2
        if(ind+2<nums.size() && nums[ind+2]==nums[ind]){
            if(f(ind+3,nums,dp)) return dp[ind] = true;
        }
    }

    // condition 3

    if(ind+2<nums.size() && nums[ind]+1 == nums[ind+1] && nums[ind]+2 == nums[ind+2]){
        if(f(ind+3,nums,dp)) return dp[ind] = true;
    }

    return dp[ind] = false;

    }
public:
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};
