class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int sum =0;

        for(int i=1;i<prices.size();i++){
            int cost = prices[i]-mini;
            if(cost>0)
            sum+=cost;
            mini = prices[i];

        }
        return sum;
    }
};
