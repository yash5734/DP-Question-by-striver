class Solution {
public:
    int f(int ind1,int ind2, string &str1,string &str2,vector<vector<int>>&dp){
        if(ind2 <0){
            return 1;
        }
        if(ind1<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int match =0;
        if(str1[ind1]==str2[ind2]){
            return dp[ind1][ind2] = f(ind1-1,ind2-1,str1,str2,dp)+f(ind1-1,ind2,str1,str2,dp);    
        }
        return dp[ind1][ind2] = f(ind1-1,ind2,str1,str2,dp);
        
        
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};
