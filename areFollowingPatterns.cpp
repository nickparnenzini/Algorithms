/* Coding challenge "areFollowingPatterns from CodeFights */

struct Info {
    int count;
    int index;
    int lastIndex;
};

bool areFollowingPatterns(std::vector<std::string> strings, std::vector<std::string> patterns) {
    std::map<std::string,std::string> matchingHashmapStrings;
    std::map<std::string,std::string> matchingHashmapPatterns;
    for (int i = 0; i < strings.size(); ++i) {
        auto itMap = matchingHashmapStrings.find(strings[i]);
        if (itMap != matchingHashmapStrings.end()) {
            if (itMap->second != patterns[i])
                return false;
        }
        else {
            matchingHashmapStrings.insert(std::make_pair(strings[i],patterns[i]));
        }
    }
    for (int i = 0; i < patterns.size(); ++i) {
        auto itMap = matchingHashmapPatterns.find(patterns[i]);
        if (itMap != matchingHashmapPatterns.end()) {
            if (itMap->second != strings[i])
                return false;
        }
        else {
            matchingHashmapPatterns.insert(std::make_pair(patterns[i],strings[i]));
        }
    }        
    return true;
}
