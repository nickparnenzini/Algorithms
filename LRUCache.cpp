/* Coding challenge #146 from LeetCode */
/* get() and put() are both O(1) time complexity */

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) { 
        auto it = hashmap.find(key);  
        if (it == hashmap.end()) {  
            return -1;
        }
        auto itList = it->second;
        int value = itList->second;  
        cache.erase(it->second);   
        pair<int,int> p = make_pair(key,value);
        cache.push_front(p);
        itList = cache.begin();
        it->second = itList;
        return value;
    }
    
    void put(int key, int value) {  
        auto it = hashmap.find(key);
        if (it == hashmap.end()) {   
            pair<int,int> p = make_pair(key,value);
            cache.push_front(p);
            auto itList = cache.begin();
            hashmap.insert(make_pair(key,itList));                      
            if (cache.size() > capacity) {   
                pair<int,int> old_pair = cache.back();
                auto itMap = hashmap.find(old_pair.first);
                hashmap.erase(itMap);
                cache.pop_back();                  
            }
        }
        else {
            auto itList = it->second;
            cache.erase(itList);
            pair<int,int> p  = make_pair(key,value);
            cache.push_front(p);
            itList = cache.begin();
            it->second = itList;
        }
    }
    
private:
    list<pair<int,int>> cache;   // key-value pair
    unordered_map<int,list<pair<int,int>>::iterator> hashmap;
    int capacity;
};
