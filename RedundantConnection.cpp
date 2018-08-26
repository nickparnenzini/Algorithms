/* Coding challenge #684 from LeetCode */

class DisjointSet {
public:
    DisjointSet(int size) {
        parent.resize(size);
        for (int i = 1; i < size; ++i) {
            parent[i] = i;
        }
        rank.resize(size);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool merge(int x, int y) {
        int x_rank = find(x);
        int y_rank = find(y);
        
        if (x_rank == y_rank) {
            return false;
        } 
        else if (rank[x_rank] < rank[ y_rank]) {
            parent[x_rank] =  y_rank;
        } 
        else if (rank[x_rank] > rank[ y_rank]) {
            parent[ y_rank] = x_rank;
        } 
        else {
            parent[ y_rank] = x_rank;
            rank[x_rank]++;
        }
        return true;
    }
    
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int> vertices;
        vector<int> result;        
        
        for (int i = 0; i < edges.size(); i++) {
             vertices.insert(edges[i][0]);
             vertices.insert(edges[i][1]);
        }
        
        DisjointSet disjoint_set(vertices.size()+1);
        
        for (auto edge : edges) {
            if (!disjoint_set.merge(edge[0], edge[1])) return edge;
        }
        
        return result;
    }
};
