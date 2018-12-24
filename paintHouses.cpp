/* Coding challenge "paintHouses" from CodeSignal */

int minPaintCost(std::vector<std::vector<int>> cost) 
{
    int N = cost.size();
    
    std::vector<std::vector<int>> dp(N,std::vector<int>(3));
 
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];
 
    for (int i = 1; i < dp.size(); ++i) {
        int first_previous_min = min(dp[i-1][1],dp[i-1][2]);
        int second_previous_min = min(dp[i-1][0],dp[i-1][2]);
        int third_previous_min = min(dp[i-1][0],dp[i-1][1]);
        
        dp[i][0] = min(first_previous_min+cost[i][0], first_previous_min+cost[i][0]);
        dp[i][1] = min(second_previous_min+cost[i][1], second_previous_min+cost[i][1]);
        dp[i][2] = min(third_previous_min+cost[i][2], third_previous_min+cost[i][2]);
    }
    
    return min(dp[N-1][0],
               min(dp[N-1][1],dp[N-1][2])); 
    
}

int paintHouses(std::vector<std::vector<int>> cost) {
    return minPaintCost(cost);
}
