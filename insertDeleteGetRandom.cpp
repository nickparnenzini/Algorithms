/* Coding challenge #380 from LeetCode */
class RandomizedSet {
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
         count = 1;    
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = values.find(val);
        if (it != values.end())
            return false;
        
        values.insert(make_pair(val,count));
        indexToValue.insert(make_pair(count++,val));
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = values.find(val);
        if (it == values.end())
            return false;
        
        auto itMap = indexToValue.find(it->second);
        values.erase(it);
        indexToValue.erase(itMap);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        std::random_device rd;  
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> dis(1,count);    
        bool found = false;  
        while (!found) {
            int index = dis(gen);
            auto it = indexToValue.find(index);
            if (it != indexToValue.end()) {
                found = true;
                return it->second;
            }
        }
        return -1;
    }
    
private: 
    unordered_map<int,int> values;  // key: number; value: index
    unordered_map<int,int> indexToValue;  // key: index; value: number
    int count;
};
