/* Coding challenge #451 from LeetCode */

class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        unordered_map<char,int> hashmap;
        for (int i = 0; i < s.length(); i++) {
            auto it = hashmap.find(s[i]);
            if (it == hashmap.end()) {
                hashmap.insert(make_pair(s[i], 1));   
            }
            else {
                it->second++;
            }
        }
        priority_queue<pair<int,char>> q;
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            pair<int,char> p = make_pair(it->second, it->first);
            q.push(p);
        }
        while (!q.empty()) {
            auto p = q.top();
            while (p.first > 0) {
                result += p.second;
                p.first--;
            }
            q.pop();
        }
        return result;
    }
};
