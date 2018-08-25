/* Coding challenge #128 from LeetCode */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        set<int> hashset;
        
        for (int i = 0; i < nums.size(); ++i) {
            hashset.insert(nums[i]);
        }
        
        int max_count = 1;
        int prev = *hashset.begin();
        int count = 1;
        
        if (nums.size() == 1)
            return 1;    
        
        auto it = hashset.begin();
        it++;
        
        for ( ; it != hashset.end(); ++it) { 
            if (*it != prev + 1) {  
                max_count = max(max_count, count);
                count = 0;
            }        
            prev = *it;
            count++;
        } 
        max_count = max(max_count, count);
        return max_count;
    }
};
