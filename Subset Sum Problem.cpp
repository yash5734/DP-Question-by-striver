// recursive code

class Solution{ 
    private:
     bool f(int ind, int target, vector<int>&arr){
         
         // base case
         if(target == 0) return true;
         if(ind==0) return arr[0] == target;
         
         // stuff
         bool notTake = f(ind-1,target,arr);
         bool take = false;
         if(arr[ind]<=target) take = f(ind-1,target-arr[ind],arr);
         
         // return if any of the true;
         return notTake || take;
     }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        return f(arr.size()-1,sum,arr);
    }
};

// memoization

class Solution{ 
    private:
     bool f(int ind, int target, vector<int>&arr,vector<vector<int>>&dp){
         
         // base case
         if(target == 0) return true;
         if(ind==0) return arr[0] == target;
         if(dp[ind][target] != -1) return dp[ind][target]; // it is 0 or 1
         
         // stuff
         bool notTake = f(ind-1,target,arr,dp);
         bool take = false;
         if(arr[ind]<=target) take = f(ind-1,target-arr[ind],arr,dp);
         
         // return if any of the true;
         return dp[ind][target] = notTake || take; // it return true or false ans dp array take 0 or 1 bcz we intialse a dp array by int we can intialise it by bool but in this case ewwe can note check for -1 that it is previously solved on not
     }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(arr.size()-1,sum,arr,dp);
    }
};

// tabulation code

class Solution{ 
public:
    bool isSubsetSum(vector<int>arr, int k){
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}
};
