#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 1e5 + 2;
bool vis[N];
vector<int> adj[N];
queue<int> q;

void setVisitedtoZero(bool vis[]) {
    for(int i = 0; i < N; i++) {
        vis[i] = false;
    }
}

void DFS(int node) {
    vis[node] = true;
    cout << node << " ";

    for(int next : adj[node]) {
        if(!vis[next]) {
            DFS(next);
        }
    }
}

void BFS_recursive() {
    if(q.empty())
        return;

    int node = q.front();
    q.pop();
    cout << node << " ";

    for(int next : adj[node]) {
        if(!vis[next]) {
            vis[next] = true;
            q.push(next);
        }
    }

    BFS_recursive(); // Recur for the rest of the queue
}

void BFS(int startNode) {
    q.push(startNode);
    vis[startNode] = true;
    BFS_recursive();
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
                DFS(node);
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


