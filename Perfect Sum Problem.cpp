class Solution{
    
int helper(int arr[],int k,vector<vector<int>> &dp,int i)
    {
        if(dp[i][k]!=-1)
            return dp[i][k];
        if(i==0)
        {
            return 0;
        }
        int take=0,NotTake;
        if(arr[i]<=k)
        {
            take=helper(arr,k-arr[i],dp,i-1);
        }
        notTake=helper(arr,k,dp,i-1);
       
        return  dp[i][k]=(take+notTake)% (1000000000+7);
    }
	public:
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    if(arr[0]==0)dp[0][0]=2;
          else dp[0][0]=1;
          
        if(arr[0]!=0&&arr[0]<=sum){
              dp[0][arr[0]]=1;
          }
        
	    return helper(arr,sum,dp,n-1);
	}
	  
};
