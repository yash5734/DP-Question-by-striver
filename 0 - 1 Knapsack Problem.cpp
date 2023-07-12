// recursive code tc - 2^n

class Solution
{
    private:
    int f(int ind, int w, int wt[], int val[]){
        
        if(ind==0){
            if(wt[0]<=w){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        int notTake = 0 + f(ind-1,w,wt,val);
        int take = INT_MIN;
        if(wt[ind]<=w){
            take = val[ind] + f(ind-1,w-wt[ind],wt,val);
        }
        
        return max(take,notTake);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return f(n-1,W,wt,val);
    }
};


// memoization code  tc - o(n*w)

class Solution
{
    private:
    int f(int ind, int w, int wt[], int val[],vector<vector<int>>&dp){
        
        if(ind==0){
            if(wt[0]<=w){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[ind][w] !=-1) return dp[ind][w];
        
        int notTake = 0 + f(ind-1,w,wt,val,dp);
        int take = INT_MIN;
        if(wt[ind]<=w){
            take = val[ind] + f(ind-1,w-wt[ind],wt,val,dp);
        }
        
        return dp[ind][w] = max(take,notTake);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>((W+1),-1));
       return f(n-1,W,wt,val,dp);
    }
};

// tablation 

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}

    
};
