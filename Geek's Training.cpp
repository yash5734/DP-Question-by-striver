// recursive
class Solution {
    private:
    int f(int day,int last,vector<vector<int>>& points){
        if(day == 0){
            int maxi = 0;
            for(int task=0;task<=2;task++){
                if(task!=last){
                    maxi = max(maxi,points[0][task]);
                }
            }
            return maxi;
        }
        
        int maxi =0;
        for(int task=0;task<=2;task++){
            if(task!=last){
                
                int point = points[day][task] + f(day-1,task,points);
                maxi = max(maxi,point);
            }
        }
        return maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        return f(n-1,3,points);
    }
};


// memoization
class Solution {
    private:
    int f(int day,int last,vector<vector<int>>& points,vector<vector<int>>&dp){
        if(day == 0){
            int maxi = 0;
            for(int task=0;task<=2;task++){
                if(task!=last){
                    maxi = max(maxi,points[0][task]);
                }
            }
            return maxi;
        }
        
        if(dp[day][last]!=-1) return dp[day][last];
        int maxi =0;
        for(int task=0;task<=2;task++){
            if(task!=last){
                
                int point = points[day][task] + f(day-1,task,points,dp);
                maxi = max(maxi,point);
            }
        }
        return dp[day][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp (n,vector<int>(4,-1));
        return f(n-1,3,points,dp);
    }
};

// tabulation
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,0));
        
        // initialise base case dp[day0][last]
        dp[0][0] = max(points[0][1],points[0][2]);
        dp[0][1] = max(points[0][0],points[0][2]);
        dp[0][2] = max(points[0][1],points[0][0]);
        dp[0][3] = max(points[0][1],max(points[0][0],points[0][2]));
        
        for(int day=1;day<n;day++){
            for(int last = 0;last<4;last++){
                
                int maxi =0;
                for(int task=0;task<=2;task++){
                    if(last!=task){
                        int point = points[day][task] + dp[day-1][task];
                        maxi = max(maxi,point);
                    }
                }
                dp[day][last] = maxi;
            }
        }
        return dp[n-1][3];
    }
};

// optimised code
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<int>prev(4,0);
        
        // initialise base case dp[day0][last]
        prev[0] = max(points[0][1],points[0][2]);
        prev[1] = max(points[0][0],points[0][2]);
        prev[2] = max(points[0][1],points[0][0]);
        prev[3] = max(points[0][1],max(points[0][0],points[0][2]));
        
        for(int day=1;day<n;day++){
            vector<int>temp(4,0);
            for(int last = 0;last<4;last++){
                
                int maxi =0;
                for(int task=0;task<=2;task++){
                    if(last!=task){
                        int point = points[day][task] + prev[task];
                        maxi = max(maxi,point);
                    }
                }
                temp[last] = maxi;
            }
            prev = temp;
        }
        return prev[3];
    }
};
