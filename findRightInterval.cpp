/* Coding challenge #436 from LeetCode */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> result;
        if (intervals.size() == 1) {
            result.push_back(-1);
            return result;
        }
        int max_start_value = INT_MIN;
        unordered_map<int,pair<int,int>> hashmap; // key: start point; value: pair is : <end_point,index>
        for (int i = 0; i < intervals.size(); i++) {
            pair<int,int> p = make_pair(intervals[i].end, i);
            hashmap.insert(make_pair(intervals[i].start, p));
            if (intervals[i].start > max_start_value) {
                max_start_value = intervals[i].start;
            }
        }
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].end > max_start_value) {
                result.push_back(-1);
            }        
            for (int j = intervals[i].end; j <= max_start_value; j++) {
                auto it = hashmap.find(j);
                if (it != hashmap.end()) {
                    result.push_back(it->second.second);
                    break;
                }
            }
        }
        return result;
    }
};
