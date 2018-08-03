/* Coding challenge #398 from LeetCode */

class Solution {
public:
    Solution(vector<int> nums) {
        arr = nums;     
    }
    
    int pick(int target) {
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dis(0, arr.size()-1);
        int index = dis(gen); 
        while (arr[index] != target) {
            index = dis(gen); 
            if (arr[index] == target) {
                return index;
            }
        }
        return index;
    }
    
private:
    vector<int> arr;    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
