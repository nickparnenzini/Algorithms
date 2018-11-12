/* Coding challenge #17 from LeetCode */

class Solution {
public:
    
    vector<string> subsets = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void letterCombinationsUtils(vector<int> number, int current_digit, string output, vector<string>& result) {       
        if (current_digit == number.size()) {  
            result.emplace_back(output);
            return;
        }
        for (int i = 0; i < subsets[number[current_digit]].size(); i++) {
            output[current_digit] = subsets[number[current_digit]][i];
            letterCombinationsUtils(number, current_digit+1, output, result);
            if (number[current_digit] == 0 || number[current_digit] == 1)
                return;
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<int> number;
        for (int i = 0; i < digits.length(); i++) {
            number.emplace_back(digits[i] - '0');
        }
        vector<string> result;
        if (digits.empty())
            return result;
        
        string output(digits.size(), ' ');
        letterCombinationsUtils(number, 0, output, result);
        return result;
    }
};
