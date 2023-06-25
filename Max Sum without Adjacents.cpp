// recursive solution

class Solution{
    private:
    int f(int *arr,int ind){
        if(ind==0) return arr[ind];
        if(ind<0) return 0;
        
        int pick = arr[ind]+f(arr,ind-2);
        int non_pick = 0+f(arr,ind-1);
        return max(pick,non_pick);
        
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   return f(arr,n-1);
	}
};

// memoization solution

class Solution{
    private:
    int f(int *arr,int ind,vector<int>&dp){
        if(ind==0) return arr[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int pick = arr[ind]+f(arr,ind-2,dp);
        int non_pick = 0+f(arr,ind-1,dp);
        return dp[ind] = max(pick,non_pick);
        
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n,-1);
	   return f(arr,n-1,dp);
	}
};

//tabulation

public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n,0);
	    dp[0] = arr[0];
	    for(int ind =1;ind<n;ind++){
	        int pick =  arr[ind];
	        if(ind>1) pick += dp[ind-2];
	        int notPick = dp[ind-1] + 0;
	        dp[ind] = max(pick,notPick);
	    }
	    return dp[n-1];
	    
	}
};


// optimise solution

public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int prev =arr[0];
	    int prev2 = 0;
	    for(int ind =1;ind<n;ind++){
	        int pick =  arr[ind];
	        if(ind>1) pick += prev2;
	        int notPick = prev + 0;
	        int curr = max(pick,notPick);
	        prev2 = prev;
	        prev = curr;
	    }
	    return prev;
	    
	}
};
