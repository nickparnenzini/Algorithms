/* Coding challenge #460 in LeetCode */
/* All the operations are performed in O(1) time complexity */

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) { 
        auto it = hashmap.find(key);
        if (it == hashmap.end()) {
            return -1;
        }
        auto itMultimap = it->second;
        pair<int,int> p = itMultimap->second;   
        auto updated_elem = make_pair(itMultimap->first + 1, p);
        frequency_storage.erase(itMultimap);
        it->second = frequency_storage.emplace(std::move(updated_elem));        
        return p.second;
    }
    
    void put(int key, int value) { 
        if (capacity > 0) {
            auto it = hashmap.find(key);    
            if (it == hashmap.end()) {     
                if (frequency_storage.size() == capacity) {  // delete first element   
                    auto it_cache = frequency_storage.begin();    
                    pair<int,int> old_pair = it_cache->second;  
                    frequency_storage.erase(it_cache);
                    auto it_map = hashmap.find(old_pair.first);
                    hashmap.erase(it_map);
                }
                pair<int,int> p = make_pair(key,value);
                auto new_it = frequency_storage.insert(std::make_pair(1,p));
                hashmap.insert(make_pair(key, new_it));
            }
            else {
                auto it_cache = it->second;
                pair<int,int> p  = make_pair(key,value);
                auto updated_elem = make_pair(it_cache->first+1, p);
                frequency_storage.erase(it_cache);
                it->second = frequency_storage.emplace(std::move(updated_elem));   
            }
        }
    }
    
private:
    multimap<int, pair<int,int>> frequency_storage;  // key: frequency; value: pair of (key,value)
    unordered_map<int, multimap<int,pair<int,int>>::iterator> hashmap;  // key - iterator
    int capacity;
};
