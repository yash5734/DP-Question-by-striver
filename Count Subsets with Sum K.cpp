
int f(int ind, vector<int> &arr, int target, vector<vector<int>> &dp){
	if(target == 0) return 1;
	if(ind==0) return arr[0]==target;
	if(dp[ind][target]!=-1) return dp[ind][target];

	int notTake = f(ind-1,arr,target,dp);
	int take = 0;
	if(target>=arr[ind]){
		take = f(ind-1,arr,target-arr[ind],dp);
	}

	return dp[ind][target] = take+notTake;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));

	return f(n-1,arr,k,dp);
}
