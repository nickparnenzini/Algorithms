/* Coding challenge #300 from LeetCode */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int total_max = 1;
        for (int i = 1; i < nums.size(); i++) {      
            int max_so_far = 1;
            for (int j = i-1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    max_so_far = max(max_so_far, dp[j] + 1);
                }
            }
            dp[i] = max_so_far;
            total_max = max(total_max, dp[i]);
        }
        return total_max;
    }
};
