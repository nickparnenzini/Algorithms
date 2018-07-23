/* Coding challenge #295 from LeetCode */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
       arr.insert(num);
    }
    
    double findMedian() {
        double result = 0.0;
        int n = arr.size();
        int half = n/2;
        vector<int> values(n,0);
        int i = 0;
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            values[i++] = *it;
            if (i > half)
                break;
        }
        if (n % 2 == 0) {
            result = (values[half-1] + values[half])/2.0;
        }
        else {
            result = (double)(values[half]);
        }
        return result;
    }
    
private:
    multiset<int> arr;
};
