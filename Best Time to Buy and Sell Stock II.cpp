class Solution {
    private:
    int f(int ind, int buy, vector<int>&prices,vector<vector<int>>&dp){

        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy){
            return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,prices,dp) , 0 + f(ind+1,1,prices,dp));
        }else{
            return dp[ind][buy] = max(prices[ind] + f(ind+1,1,prices,dp) , 0 + f(ind+1,0,prices,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        // return f(0,1,prices,dp);

        dp[0][0] =0;
        dp[0][1] = 0;

        for(int i=n;i<=1;i++){
            for(int j=0;j<=1;j++){
                dp[i][j] = max(-prices[i-1] + dp[i-1][j] , ); 
            }
        }


    }
};
