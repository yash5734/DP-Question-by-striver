class Solution{
public:
    int minDifference(int arr[], int n) {
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        int k = totalSum;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (arr[0] <= k)
            dp[0][arr[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTaken = dp[ind - 1][target];

                bool taken = false;
                if (arr[ind] <= target)
                    taken = dp[ind - 1][target - arr[ind]];

                dp[ind][target] = notTaken || taken;
            }
        }

        int mini = 1e9;
        for (int s1 = 0; s1 < totalSum; s1++) {
            if (dp[n - 1][s1] == true) {
                mini = min(mini, abs(s1 - (totalSum - s1)));
            }
        }
        return mini;
    }
};
