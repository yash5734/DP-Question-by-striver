class Solution{
    

int f(int ind, int arr[], int target, vector<vector<int>> &dp){
    
	if(ind==0){
	    if(arr[0] == 0 && target ==0) return 2;
	    if(target==0) return 1;
	    if(arr[0] == target) return 1;
	    return 0;
	} 
	if(dp[ind][target]!=-1) return dp[ind][target];

	int notTake = f(ind-1,arr,target,dp);
	int take = 0;
	if(target>=arr[ind]){
		take = f(ind-1,arr,target-arr[ind],dp);
	}

	return dp[ind][target] = (take+notTake)% (1000000000+7);
}


	public:
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    
	    return f(n-1,arr,sum,dp);
	}
	  
};
