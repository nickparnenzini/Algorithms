/* Coding challenge #239 from LeetCode */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty())
            return result;
        
        int left_limit = 0;
        std::multiset<int> hashset;
        for (int i = 0; i < k; ++i) {
            hashset.emplace(nums[i]);
        }
        result.emplace_back(*hashset.rbegin());
        for (int i = k; i < nums.size(); ++i) {
            auto it = hashset.find(nums[left_limit++]);  
            hashset.erase(it);
            hashset.emplace(nums[i]);
            result.emplace_back(*hashset.rbegin());
        }
        return result;
    }
};
