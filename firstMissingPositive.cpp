/* Coding challenge #41 from LeetCode */
class Solution {
public:
    int splitNumbers(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) {
                std::swap(nums[i],nums[j]);
                j++;
            }            
        }
        return j;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        int shift = splitNumbers(nums);
        int size = nums.size() - shift;
        vector<int> arr(size, 0);
        for (int i = 0; i < size; i++) {
            arr[i] = nums[i + shift];
        }
        for (int i = 0; i < size; i++) {
            int current = abs(arr[i]) - 1;
            if (current < size && arr[current] > 0) {
                arr[current] *= -1;
            }
        }
        for (int i = 0; i < size; i++) {
            if (arr[i] > 0) {
                return i + 1;
            }
        }
        return size + 1;
    }  
};
