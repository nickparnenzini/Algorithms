/* O(n) solution by using two indices */
/* The input array is supposed to be sorted */
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        if (nums[left] + nums[right] == target) {
            result.push_back(left+1);
            result.push_back(right+1);
            left++; right--;
        }
        if (nums[left] + nums[right] > target) {
            right--;
        }
        if (nums[left] + nums[right] < target) {
            left++;
        }
    }
    return result;    
}
