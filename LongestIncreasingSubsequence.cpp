#include <vector>

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if ( n == 0 )
            return 0;
        vector<int> dp(n);
        dp[0] = 1;
        int totalMax = 0;
        for ( int i = 0; i < n; i++ ) {
            int relMax = 0;
            for ( int j = 0; j < i; j++ ) {
                if ( nums[i] > nums[j] ) {
                    relMax = max(relMax, dp[j]);   
                }
            }
            dp[i] = relMax + 1;
            totalMax = max(dp[i],totalMax);
        }
        return totalMax;
    }
