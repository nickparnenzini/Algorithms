typedef pair<int, int> iPair;

std::vector<int> dijkstra(std::vector<std::vector<int>> graph, int src) {
    std::vector<int> distances(graph.size(),INT_MAX);
    std::vector<int> sptSet(graph.size(),0);
    
    distances[src] = 0;
    
    int V = graph.size();
    
    std::priority_queue<iPair, vector <iPair> , greater<iPair>> pq;
    pq.push(std::make_pair(distances[src],src));
    
    while (!pq.empty()) {
        int u = pq.top().second;   std::cout << "u: " << u << std::endl;
        pq.pop();
        
        sptSet[u] = 1;
        
        for (int v = 0; v < V; v++) {  
                if ((sptSet[v] == 0) && (graph[u][v] >= 0) && (distances[u] != INT_MAX)) {
                    int dist_tmp = distances[u] + graph[u][v];
                    if (dist_tmp < distances[v]) {
                        distances[v] = dist_tmp;
                        pq.push(std::make_pair(distances[v],v));
                    }
                }
        }
    }
    return distances;
}

std::vector<int> graphDistances(std::vector<std::vector<int>> g, int s) {
    return dijkstra(g,s);
}
