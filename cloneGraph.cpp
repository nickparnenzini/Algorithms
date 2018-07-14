/* Code challenge #133 from LeetCode */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode* DFS(UndirectedGraphNode* node, std::unordered_map<int, UndirectedGraphNode*>& hashmap) {
        if (hashmap.find(node->label) != hashmap.end())
          return hashmap[node->label];
      
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        hashmap.insert(make_pair(new_node->label, new_node));
        for (auto neighbor : node->neighbors) {
            new_node->neighbors.push_back(DFS(neighbor, hashmap));
        }
        return new_node;
    }
  
  
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
          return nullptr;
        
        std::unordered_map<int, UndirectedGraphNode*> hashmap;
        return DFS(node, hashmap);
    }
};
