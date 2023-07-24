class Solution {
   public
    int min(int n1,int n2){
        if(n1<n2) return n1;
        return n2;
    }
    int max(int n1,int n2){
        if(n1<n2) return n2;
        return n1;
    }
   
    int maxProfit(int[] prices) {
        int mini = prices[0];
        int maxi = 0;
        int n = prices.length;

        for(int i=1;i<n;i++){

            int cost = prices[i]-mini;
            maxi = max(cost,maxi);

            mini = min(mini,prices[i]);
        }
        return maxi;
    }
}
