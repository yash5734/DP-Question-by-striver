class Solution {
    int f(int ind1, int ind2, string& str1, string& str2,vector<vector<int>>&dp){
        if(ind1<0||ind2<0){
            return 0;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int match=0;
        if(str1[ind1]==str2[ind2]){
            match = 1+f(ind1-1, ind2-1, str1, str2,dp);
        }
        int notMatch = 0+max(f(ind1-1,ind2,str1,str2,dp),f(ind1,ind2-1,str1,str2,dp));

        return dp[ind1][ind2] = max(match,notMatch);
    }
public:
    int minInsertions(string s1) {
       int n =s1.size();
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));

        int ans = f(n-1,n-1,s1,s2,dp);
        return n-ans;
    }
};
