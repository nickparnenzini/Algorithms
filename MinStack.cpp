/* Coding challenge #155 from LeetCode */
/* All the operations are performed in O(1) complexity time */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() { 
    }
    
    void push(int x) {
        stack.push_back(x);
        ordered_values.insert(x);
    }
    
    void pop() {
        if (!stack.empty()) {
            int top_value = stack.back();
            stack.pop_back();
            auto it = ordered_values.find(top_value);
            if (it != ordered_values.end()) {
                ordered_values.erase(it);        
            }
        }
    }
    
    int top() {
        if (stack.empty()) {
            return -1;
        }
        return stack.back();
    }
    
    int getMin() {
        if (!ordered_values.empty()) {
            return *ordered_values.begin();
        }    
        return -1;
    }
    
private:
    multiset<int> ordered_values;
    list<int> stack;
};
