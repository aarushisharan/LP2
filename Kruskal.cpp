#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int dst, src, weight;
};

bool compareEdges(const Edge &a, const Edge &b) {
    return (a.weight < b.weight);
}

int findparent(vector<int> &parent, int u) {
    if (parent[u] != u) {
        parent[u] = findparent(parent, parent[u]);
    }
    return parent[u];
}

void unionsets(vector<int> &parent, vector<int> &rank, int x, int y) {
    int xroot = findparent(parent, x);
    int yroot = findparent(parent, y);
    if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

vector<Edge> Krushkal(vector<Edge> &edges, int V) {
    vector<Edge> result;
    vector<int> parent(V);
    vector<int> rank(V, 0);
    sort(edges.begin(), edges.end(), compareEdges);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    int i = 0;
    while (result.size() < V - 1) {
        Edge next_edge = edges[i++];
        int x = findparent(parent, next_edge.src);
        int y = findparent(parent, next_edge.dst);
        if (x != y) {
            result.push_back(next_edge);
            unionsets(parent, rank, x, y);
        }
    }
    return result;
}

// Function to convert a string vertex name to its corresponding integer index
int vertexNameToIndex(const string& vertexName, unordered_map<string, int>& vertexIndices) {
    if (vertexIndices.count(vertexName) == 0) {
        // Assign a new index for the unseen vertex name
        int newIndex = vertexIndices.size();
        vertexIndices[vertexName] = newIndex;
    }
    return vertexIndices[vertexName];
}

int main() {
    int v, e;
    cout << "Enter the number of edges:" << endl;
    cin >> e;
    cout << "Enter the number of vertices:" << endl;
    cin >> v;

    unordered_map<string, int> vertexIndices; // Map vertex names to integer indices

    vector<Edge> edges;
    cout << "Enter edges in format 'source destination weight':" << endl;
    for (int i = 0; i < e; i++) {
        string src, dst;
        int w;
        cin >> src >> dst >> w;

        int sourceIndex = vertexNameToIndex(src, vertexIndices);
        int destinationIndex = vertexNameToIndex(dst, vertexIndices);

        edges.push_back({destinationIndex, sourceIndex, w}); // Adjust order for compatibility
    }

    vector<Edge> mst = Krushkal(edges, vertexIndices.size());
    for (Edge edge : mst) {
        // Retrieve vertex names from the map for output
        string sourceName = "";
        string destinationName = "";
        for (auto const& entry : vertexIndices) {
            string name=entry.first;
            int index= entry.second;
            if (index == edge.src) {
                sourceName = name;
            }
            if (index == edge.dst) {
                destinationName = name;
            }
        }
        cout << sourceName << " -- " << destinationName << " == " << edge.weight << endl;
    }
    return 0;
}
