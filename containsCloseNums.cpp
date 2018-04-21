/* Coding challenge "containsCloseNums" from CodeFights */

bool containsCloseNums(std::vector<int> nums, int k) {
    if (k == 0) 
        return false;
    
    std::map<int,std::vector<int>> distNumbers;
    for (int i = 0; i < nums.size(); ++i) {
        auto itMap = distNumbers.find(nums[i]);
        if (itMap != distNumbers.end()) {  
            for (int j = 0; j < itMap->second.size(); ++j) {
                int distance = abs(itMap->second[j] - i);  
                if (distance <= k)
                    return true;
            }
            itMap->second.push_back(i);
        }
        else {
            distNumbers.insert(std::pair<int,std::vector<int>>(nums[i],{i}));
        }
    }
    return false;
}
