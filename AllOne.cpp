/* Coding challenge #432 from LeetCode */
/* This data structure performs all the operations in O(1) */

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = hashmap.find(key);
        if ( it == hashmap.end()) {
            auto itMap = frequency_storage.insert(make_pair(1,key));
            hashmap.insert(make_pair(key,itMap));
        }
        else {
            auto it_cache = it->second;
            auto updated_elem = make_pair(it_cache->first+1, key);
            frequency_storage.erase(it_cache);
            auto new_it = frequency_storage.insert(updated_elem);
            it->second = new_it;
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = hashmap.find(key);
        if (it != hashmap.end()) {
            auto it_cache = it->second;
            auto updated_elem = make_pair(it_cache->first-1, key);
            int value = it_cache->first - 1;
            frequency_storage.erase(it_cache);
            if (value > 0) {
                auto new_it = frequency_storage.insert(updated_elem);
                it->second = new_it;    
            }
            else if (value == 0) {
                hashmap.erase(it);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (frequency_storage.size() > 0) {
            auto it = frequency_storage.rbegin(); 
            return it->second;
        }
        return "";     
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (frequency_storage.size() > 0) {
            auto it = frequency_storage.begin(); 
            return it->second;
        }
        return "";          
    }
    
private:
    multimap<int,string> frequency_storage;
    unordered_map<string,multimap<int,string>::iterator> hashmap;
};
