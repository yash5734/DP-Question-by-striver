// recursive code

class Solution {
    private:
    bool f(int ind, int target, vector<int> &arr){
        if(target ==0 ) return true;
        if(ind==0) return target == arr[ind];

        int notTake = f(ind-1,target,arr);
        int take = false;
        if(arr[ind]<=target) take = f(ind-1,target-arr[ind],arr);

        return take||notTake; 
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0) return false; // it means we can not find 2 subset beacse it is odd

        else{
            return f(n-1,sum/2,nums);
        }
    }
};

// memoization code

class Solution {
    private:
    bool f(int ind, int target, vector<int> &arr,vector<vector<int>> &dp){
        if(target ==0 ) return true;
        if(ind==0) return target == arr[ind];
        if(dp[ind][target]!=-1) return dp[ind][target];

        int notTake = f(ind-1,target,arr,dp);
        int take = false;
        if(arr[ind]<=target) take = f(ind-1,target-arr[ind],arr,dp);

        return dp[ind][target] = take||notTake; 
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0) return false; // it means we can not find 2 subset beacse it is odd
        int target = sum/2;

        vector<vector<int>>dp(n,vector<int>(target+1,-1));  
        return f(n-1,target,nums,dp);
        
    }
};
