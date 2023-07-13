class Solution{
    private:
    int f(int ind,int N, int arr[]){
        
        if(ind == 0){
            return N*arr[0];
        }
        
        int notTake = f(ind-1,N,arr);
        int take = -1e9;
        int rodLength = ind+1;
        if(rodLength<=N){
            take = arr[ind] + f(ind,N-rodLength,arr);
        }
        return max(take,notTake);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        return f(n-1,n,price);
    }
};

// memoization

class Solution{
    private:
    int f(int ind,int N, int arr[],vector<vector<int>>&dp){
        
        if(ind == 0){
            return N*arr[0];
        }
        if(dp[ind][N]!=-1) return dp[ind][N];
        
        int notTake = f(ind-1,N,arr,dp);
        int take = -1e9;
        int rodLength = ind+1;
        if(rodLength<=N){
            take = arr[ind] + f(ind,N-rodLength,arr,dp);
        }
        return dp[ind][N] = max(take,notTake);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};
