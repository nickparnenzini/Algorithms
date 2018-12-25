/* Coding challenge "sort by string" from Code Signal */

std::string sortByString(std::string s, std::string t) {
    std::unordered_map<char,int> hashmap;
    for (int i = 0; i < t.length(); i++) {
        hashmap.emplace(std::make_pair(t[i],i));
    }
    std::multimap<int,char> pairs;
    for (int i = 0; i < s.length(); i++) {
        auto it = hashmap.find(s[i]);
        pairs.emplace(std::make_pair(it->second,s[i]));
    }
    std::string result("");
    for (auto it = pairs.begin(); it != pairs.end(); ++it) {
        result += it->second;
    }
    return result;
}
