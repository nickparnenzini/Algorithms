/* Coding challenge #352 from LeetCode */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        bool inserted = false;
        for (auto it = hashset.begin(); it != hashset.end(); ++it) {
            if ((*it).second == val-1) {
                int left = (*it).first;
                hashset.erase(it);
                hashset.emplace(std::make_pair(left,val));
                inserted = true;
                break;
            }
            if ((*it).first <= val && (*it).second >= val) {
                inserted = true;
                break;
            }
        } 
        for (auto it = hashset.begin(); it != hashset.end(); ++it) {
            if ((*it).first == val+1) {
                int right = (*it).second;
                hashset.erase(it);
                hashset.emplace(std::make_pair(val,right));
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            hashset.emplace(std::make_pair(val,val));
        }
        if (hashset.size() > 1) {
            auto it_prev = hashset.begin();
            auto it_next = it_prev++;
            for (; it_next != hashset.end(); ++it_next) {
                if ((*it_prev).second == (*it_next).first) { // merge
                    int left = (*it_prev).first;
                    int right = (*it_next).second;
                    hashset.erase(it_prev);
                    hashset.erase(it_next);
                    hashset.emplace(std::make_pair(left,right));
                    break;
                } 
                it_prev = it_next;
            }    
        }
    }
    
    vector<Interval> getIntervals() {
        std::vector<Interval> result;
        for (auto elem : hashset) {
            result.emplace_back(std::move(Interval(elem.first,elem.second)));
        }
        return result;
    }
    
private:
    
    std::set<std::pair<int,int>> hashset;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
