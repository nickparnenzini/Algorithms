//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

std::vector<int> traverseTree(Tree<int> *t) {
    std::queue<Tree<int>*> nodes;
    std::vector<int> result;
    
    if (!t)
        return result;
    
    nodes.push(t);
    
    while (!nodes.empty()) {
        Tree<int>* tt = nodes.front();
        nodes.pop();
        result.push_back(tt->value);
        if (tt->left) 
            nodes.push(tt->left);
        if (tt->right)
            nodes.push(tt->right);
    }
    
    return result;
}
