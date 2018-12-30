
std::vector<std::string> findPaths(std::string input) {
    std::vector<std::string> result;
    int level = 0;
    std::string ss;
    std::vector<std::string> vv;
    int i = 0;
    bool found = false;
    while (i <= input.length()) {
        int count = 0;
        if ((i == input.length()) || (input[i] == '\f')) {
            if (!found) {
                ss.push_back('/');
            }
            i++;
            vv.push_back(ss);
            if (found) {
                std::string tmp("");
                for (int k = 0; k < vv.size(); k++) {
                    tmp += vv[k];
                }
                result.emplace_back(std::move(tmp));  
                found = false;
            }
            ss.clear();
            while ((i < input.length()) && (input[i] == '\t')) {
                i++;
                count++;
            }
            int diff = level - count;
            if (diff >= 0) {
                for (int k = 0; k <= diff; k++) {
                    vv.pop_back();
                }
            }
            level = count;
        }
        else {
            if(input[i]=='.') {
                found = true;
            }
            ss.push_back(input[i]);
            i++;
        }
    }
    return result;   
}

int longestPath(std::string fileSystem) {
    std::vector<std::string> result = findPaths(fileSystem);
    int max_length = 0;
    for (int i = 0; i < result.size(); i++) {  
        if (result[i].length() > max_length)
            max_length = result[i].length();
    }
    return max_length;
}
