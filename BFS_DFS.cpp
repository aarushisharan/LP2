#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 1e5 + 2;
bool vis[N];
vector<int> adj[N];

void setVisitedtoZero(bool vis[]) {
    for(int i = 0; i < N; i++) {
        vis[i] = false;
    }
}

void DFS(int node, int level) {
    vis[node] = true;
    cout << "Node: " << node << ", Level: " << level << endl;

    for(int next : adj[node]) {
        if(!vis[next]) {
            DFS(next, level + 1); // Increment level for the next node
        }
    }
}

void BFS_recursive(queue<pair<int, int>>& q) {
    if (q.empty())
        return;

    pair<int, int> current = q.front();
    q.pop();
    int node = current.first;
    int level = current.second;

    cout << "Node: " << node << ", Level: " << level << endl;

    for(int next : adj[node]) {
        if (!vis[next]) {
            vis[next] = true;
            q.push({next, level + 1}); // Increment level for the next node
        }
    }

    BFS_recursive(q); // Recur for the rest of the queue
}

void BFS(int startNode) {
    queue<pair<int, int>> q;
    q.push({startNode, 0}); // Start node with level 0
    vis[startNode] = true;
    BFS_recursive(q);
}

int main() {
    int n, m;
    cout << "Enter the number of edges and vertices of the graph: ";
    cin >> n >> m;

    cout << "Enter starting and ending vertices of the edges:\n";
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int choice;
    do {
        cout << "\n----MENU----\n";
        cout << "1. DFS\n2. BFS\n3. Exit\n";
        cout << "Enter the choice: ";
        cin >> choice;

        int node;
        switch(choice) {
            case 1:
                cout << "Enter the node to start with: ";
                cin >> node;
                cout << "\nDFS:\n";
                setVisitedtoZero(vis);
                DFS(node, 0); // Start with level 0
                break;

            case 2:
                cout << "Enter the node to start with: ";
                cin >> node;
                cout << "\nBFS:\n";
                setVisitedtoZero(vis);
                BFS(node);
                break;
        }
    } while(choice != 3);

    return 0;
}
