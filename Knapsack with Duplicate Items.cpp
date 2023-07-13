class Solution{
    private:
    int f(int ind,int maxWt,int val[], int wt[]){
        
        if(ind ==0){
            
            return (maxWt/wt[0]) * val[0];
        }
        
        int notTake = 0 + f(ind-1,maxWt,val,wt);
        int take =-1e9;
        if(maxWt>=wt[ind]){
            take = val[ind] + f(ind,maxWt-wt[ind],val,wt);
        }
        return max(take,notTake);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
       return f(N-1,W,val,wt);
    }
};

// memoization

class Solution{
    private:
    int f(int ind,int maxWt,int val[], int wt[],vector<vector<int>> &dp){
        
        if(ind ==0){
            
            return (maxWt/wt[0]) * val[0];
        }
        
        if(dp[ind][maxWt]!=-1) return dp[ind][maxWt];
        
        int notTake = 0 + f(ind-1,maxWt,val,wt,dp);
        int take =-1e9;
        if(maxWt>=wt[ind]){
            take = val[ind] + f(ind,maxWt-wt[ind],val,wt,dp);
        }
        return dp[ind][maxWt] = max(take,notTake);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
       return f(N-1,W,val,wt,dp);
    }
};
