/* Coding challenge #228 from LeetCode */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int i = 1;
        int start = 0;
        int end = 0;
        
        if (nums.size() == 1) {
            result.push_back(std::to_string(nums[0]));
            return result;
        }
        
        while (i < nums.size()) {
            string st = std::to_string(nums[start]); 
            while (nums[i] == nums[i-1] + 1) {
                i++;
            }
            
            end = i - 1;
            if (start != end) {
                st += "->";
                st += std::to_string(nums[end]);
            }
            result.push_back(st);
            start = i;  
            end = i;
            i++;
            if (start == nums.size()-1) {
                result.push_back(std::to_string(nums[start]));    
            }
        }
        return result;
    }
};
