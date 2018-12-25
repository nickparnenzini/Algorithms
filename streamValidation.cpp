/* Coding challenge "streamValidation" from CodeSignal */
std::vector<int> fromDecToBinary(int n) {
    std::vector<int> result;
    while (n > 0) {
        result.emplace_back(n%2);
        n /= 2;
    }
    int old_size = result.size();
    for (int i = 0; i < 8 - old_size; i++) {
        result.emplace_back(0);
    }
    std::reverse(result.begin(),result.end());
    return result;
}

bool isUTF8Encoding(std::vector<std::vector<int>> stream, int start, int end) {
    if (end-start == 1 && stream[start][0] == 0)
        return true; 
    
    if (end-start > 1 && stream.size() <= 1)
        return false;

    int bytes = end - start;

    for (int j = 0; j < bytes; j++) {
       if (stream[start][j] != 1) {  std::cout << "false from first if" << std::endl;
            return false;
        }
    }
    
    if (stream[start][bytes] != 0)  {   std::cout << "false from second if" << std::endl;
        return false;                              
    }
    for (int i = start+1; i <= start+bytes-1; i++) {
        if (stream[i][0] != 1) {   std::cout << "false from third if" << std::endl;
            return false;
        }                      
        if (stream[i][1] != 0)  {   std::cout << "false from fourth if" << std::endl;
            return false;
        }
    }
    return true;
}

bool streamValidation(std::vector<int> stream) {
    std::vector<std::vector<int>> bytes;
    for (int i = 0; i < stream.size(); ++i) {
        std::vector<int> tmp = fromDecToBinary(stream[i]);
        bytes.emplace_back(std::move(tmp));
    }

    int start = 0;
    int end = 1;
    int count_bytes = 0;

    while (end <= bytes.size()) {
        if (bytes[start][0] == 0) {  
            if (!isUTF8Encoding(bytes,start,end))   
                return false;
            
            start = end++;
        }
        else {    
            count_bytes = 0;
            for (int j = 0; j < 4; j++) {
                if (bytes[start][j] == 1)
                    count_bytes++;
            } 
            end = start+count_bytes;
            if (!isUTF8Encoding(bytes,start,end)) 
                return false;
    
            start = end++;
        } 
    }
    return true;
}
