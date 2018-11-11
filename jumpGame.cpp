/* Coding challenge #55 from LeetCode */

class Solution {
public:  
    bool canJump(vector<int>& nums) {
        vector<int> good_index(nums.size(), 0);
        good_index[nums.size()-1] = 1;
        for (int i = nums.size()-2; i >= 0; i--) {
            for (int j = 0; j <= nums[i]; j++) {
                int jump = i + j;
                if (good_index[jump] == 1) {
                    good_index[i] = 1;
                    break;
                }
            }    
        } 
        return good_index[0] == 1;
    }
};
