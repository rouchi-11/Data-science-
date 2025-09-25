#include <bits/stdc++.h>
using namespace std;

void dijkstra(int source, vector<vector<pair<int,int>>> &graph, vector<int> &dist, vector<int> &parent) {
    int V = graph.size();
    dist.assign(V, INT_MAX);
    parent.assign(V, -1);
    dist[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : graph[u]) {
            int v = edge.first, w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;  // track path
                pq.push({dist[v], v});
            }
        }
    }
}


vector<int> getPath(int target, vector<int> &parent) {
    vector<int> path;
    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}


void updateEdge(vector<vector<pair<int,int>>> &graph, int u, int v, int newW) {
    for (auto &edge : graph[u])
        if (edge.first == v) { edge.second = newW; break; }

    for (auto &edge : graph[v])
        if (edge.first == u) { edge.second = newW; break; }

    cout << "Updated edge (" << u << " <-> " << v << ") to weight " << newW << "\n";
}


int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int,int>>> graph(V);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); 
    }

    vector<int> dist, parent;
    int choice;

    do {
        int source, target;
        cout << "\nEnter source node: ";
        cin >> source;
        cout << "Enter target node: ";
        cin >> target;

        dijkstra(source, graph, dist, parent);

        if (dist[target] == INT_MAX) {
            cout << "No path exists from " << source << " to " << target << "\n";
        } else {
            cout << "Shortest distance from " << source << " to " << target << " = " << dist[target] << "\n";

            vector<int> path = getPath(target, parent);
            cout << "Path: ";
            for (size_t i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i + 1 < path.size()) cout << " -> ";
            }
            cout << "\n";
        }

        cout << "Do you want to update an edge weight? (1 = yes / 0 = no): ";
        cin >> choice;
        if (choice == 1) {
            int u, v, newW;
            cout << "Enter edge (u v) and new weight: ";
            cin >> u >> v >> newW;
            updateEdge(graph, u, v, newW);
        }

        cout << "Do you want to find another shortest path? (1 = yes / 0 = no): ";
        cin >> choice;

    } while (choice == 1);

    return 0;
}


