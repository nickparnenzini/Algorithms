/* Coding challenge "findSubstrings" from Code Signal */

class Trie 
{
    struct TrieNode {
        TrieNode* children[58];   
        bool is_word{false};
    };
    
public:
    Trie() {
        root = new TrieNode;
        for (int i = 0; i < 58; i++) {
            root->children[i] = nullptr;
        }
    }
    
    void init(TrieNode* trie_node) {
        for (int i = 0; i < 58; i++) {
            trie_node->children[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) { 
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) {   
            if (cur->children[word[i]-'A'] == nullptr) {   
                cur->children[word[i]-'A'] = new TrieNode;  
                init(cur->children[word[i]-'A']);
            }            
                                                   
            if (i == word.length()-1) {     
                cur->children[word[i]-'A']->is_word = true;        
            }            
            cur = cur->children[word[i]-'A'];    
        }                           
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {  
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++) {
            if (cur->children[word[i]-'A'] == nullptr) {
                return false;
            }
            if (i == word.length()-1 && !cur->children[word[i]-'A']->is_word) {
                return false;
            }
            cur = cur->children[word[i]-'A'];
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) { 
        TrieNode* cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (cur->children[prefix[i]-'A'] == nullptr) {
                return false;
            }
            cur = cur->children[prefix[i]-'A'];
        }
        return true;
    }
    
private:
    TrieNode* root{nullptr};
    
};


std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) {
    Trie* root = new Trie();
    std::vector<std::string> result;
    
    for (int i = 0; i < parts.size(); i++) {  
        root->insert(parts[i]);
    }

    for (int i = 0; i < words.size(); i++) {
        int max_length = INT_MIN;
        std::string final_string("");
        int max_length_so_far = 0;
        int position = -1;
        for (int j = 0; j < words[i].length(); j++) {  
            std::string letter = words[i].substr(j,1);      
            if (root->startsWith(letter)) {         
                std::string final_value_for_letter("");
                for (int k = 1; k <= words[i].length()-j; k++) {
                    std::string tmp = words[i].substr(j,k);  
                    if (root->search(tmp)) {  
                        if (max_length_so_far < k) {  
                            max_length_so_far = k;   
                            final_string = words[i].substr(j,k);
                            position = j;
                        }
                    } 
                }
                max_length = max(max_length,max_length_so_far);
            }
        }
        if (final_string.empty()) {
            result.emplace_back(words[i]);    
        }
        else {
            int end = words[i].length() - (position+final_string.length());
            std::string tmp = words[i].substr(0,position) + "[" + final_string + "]" + words[i].substr(position+final_string.length(),end);
            result.emplace_back(tmp);
        }
    }
    return result;
}
