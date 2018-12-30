/*
You are given a recursive notation of a binary tree: each node of a tree is represented as a set of three elements:
value of the node;
left subtree;
right subtree.
So, a tree can be written as (value left_subtree right_subtree). 
It is guaranteed that 1 ≤ value ≤ 109. If a node doesn't exist then it is represented as an empty set: ()
Your task is to obtain a list of nodes, that are the most distant from the tree root, in the order from left to right.
*/

int computeMaxLevel(std::string str) {
    int level = -1;
    int max_level = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            level++;
        }
        else if (str[i] == ')') {
            level--;
        }
        max_level = std::max(max_level, level); 
    }
    return max_level;
}

std::vector<int> nodesAtMaxLevel(std::string str, int k) {
    int level = 0;
    std::vector<int> result;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            level++;
        }
        else if (str[i] == ')') {
            level--;
        }
        else {
            if (level == k) {
                std::string num("");
                while (str[i] >= '0' && str[i] <= '9') {
                    num = num + str[i++];
                }
                if (!num.empty()) {
                    int x = std::stoi(num);
                    result.emplace_back(x);    
                }    
            }
        }
    }
    return std::move(result);
}

std::vector<int> treeBottom(std::string tree) {
    int max_level = computeMaxLevel(tree);  
    std::vector<int> result = nodesAtMaxLevel(tree, max_level);
    return result;
}
