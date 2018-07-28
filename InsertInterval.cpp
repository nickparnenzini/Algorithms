/* Coding challenge #57 from LeetCode */

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
    
    static bool compare(const Interval& i, const Interval& j) {
        return i.start < j.start;
    }    
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty())
            return result;
        
        std::sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals[0]);
        int j = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= result[j].end) {
                if (intervals[i].end > result[j].end) {
                    result[j].end = intervals[i].end;
                } 
            }
            else {
                result.push_back(intervals[i]);
                j++;
            }
        }
        return result;
    }   
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        if (intervals.empty()) {
            result.push_back(newInterval);
            return result;
        }
        if (newInterval.start <= intervals[0].start) {
            intervals.emplace(intervals.begin(), newInterval);
            result = merge(intervals);
            return result;
        }
        if (newInterval.start >= intervals[intervals.size()-1].start) {
            intervals.push_back(newInterval);
            result = merge(intervals);
            return result;
        }
        for (int i = 0; i < intervals.size()-1; i++) {
            if (compare(intervals[i],newInterval) && !compare(intervals[i+1], newInterval)) {                 
                intervals.emplace(intervals.begin()+i+1, newInterval);
                break;
            }    
        }
        result = merge(intervals);
        return result;
    }
};
