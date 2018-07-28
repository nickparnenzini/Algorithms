/* Coding challenge #34 from LeetCode */

class Solution {
public:
    
    int binarySearch(vector<int> nums, int start, int end, int x) {
        if (start > end)
            return -1;
        
        int current = (start+end)/2;
        if (nums[current] == x)
            return current;
        
        if (nums[current] > x)
            return binarySearch(nums, start, current-1, x);
        
        return binarySearch(nums, current+1, end, x);
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int index = binarySearch(nums, 0, nums.size()-1, target);
        if (index == -1) {
            result.push_back(-1);
            result.push_back(-1);
        }
        else {
            int low = index;
            int high = index;
            while (low >= 0 && nums[low] == target) {low--;}
            while (high < nums.size() && nums[high] == target) {high++;}
            result.push_back(low+1);
            result.push_back(high-1);
        }
        return result;
    }
};
