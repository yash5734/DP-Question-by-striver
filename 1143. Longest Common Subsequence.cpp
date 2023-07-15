// recursive code

class Solution {
    private:
    int f(int ind1, int ind2, string& str1, string& str2){
        if(ind1<0||ind2<0){
            return 0;
        }
        int match=0;
        if(str1[ind1]==str2[ind2]){
            match = 1+f(ind1-1, ind2-1, str1, str2);
        }
        int notMatch = 0+max(f(ind1-1,ind2,str1,str2),f(ind1,ind2-1,str1,str2));

        return max(match,notMatch);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return f(text1.size()-1,text2.size()-1,text1,text2);
    }
};

// memoization

class Solution {
    private:
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
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,text1,text2,dp);
    }
};
