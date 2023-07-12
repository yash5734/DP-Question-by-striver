class Solution {
    private:
    int f(int ind, int target, vector<int>& arr,vector<vector<int>> &dp){

        if(ind == 0){
            if(target % arr[0] == 0){
                return target/arr[0];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][target] != -1)return dp[ind][target];

        int notTake = 0+f(ind-1,target,arr,dp);
        int take = 1e9;
        if(arr[ind]<=target)
            take = 1 + f(ind,target-arr[ind],arr,dp);
         

        return dp[ind][target] = min(take,notTake);
        
    }
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = f(n-1,amount,coins,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

// tabulation 
class Solution {
public:
    int coinChange(vector<int>& arr, int amount) {

        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));

        for(int i=0;i<=amount;i++){
            if(i % arr[0] == 0){
                dp[0][i] = i/arr[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }

        for(int ind = 1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notTake = 0+dp[ind-1][target];
                int take = 1e9;
                if(arr[ind]<=target)
                    take = 1 + dp[ind][target-arr[ind]];
                
                dp[ind][target] = min(take,notTake); 
            }    
        }

        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};
