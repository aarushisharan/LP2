#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int dst,src,weight;
};
bool compareEdges(const Edge &a, const Edge &b){
    return(a.weight<b.weight);
}
int findparent(vector<int> &parent,int u){
    if(parent[u]!=u){
        parent[u]=findparent(parent,parent[u]);
    }
    return parent[u];
}
void unionsets(vector<int> &parent,vector<int> &rank,int x,int y){
    int xroot=findparent(parent,x);
    int yroot=findparent(parent,y);
    if(rank[xroot]>rank[yroot]){
        parent[yroot]=xroot;
    }
    else if(rank[xroot]<rank[yroot]){
        parent[xroot]=yroot;
    }
    else{
       parent[yroot]=xroot;
       rank[xroot]++;
    }
}
vector<Edge> Krushkal(vector<Edge> &edges,int V){
    vector <Edge> result;
    vector <int> parent(V);
    vector <int> rank(V,0);
    sort(edges.begin(),edges.end(),compareEdges);
    for(int i=0;i<V;i++){
        parent[i]=i;
    }
    int i=0;
    while(result.size()<V-1){
        Edge next_edges=edges[i++];
        int x=findparent(parent,next_edges.src);
        int y=findparent(parent,next_edges.dst);
        if(x!=y){
            result.push_back(next_edges);
            unionsets(parent,rank,x,y);
        }
    }
    return result;
}
int main(){
    int v,e;
    cout<<"Enter no.of edges"<<endl;
    cin>>e;
    cout<<"Enter no.of vertices"<<endl;
    cin>>v;
    vector<Edge> edges;
    cout << "Enter edges in format 'source destination weight':" << endl;
    for(int i=0;i<e;i++){
        int d,s,w;
        cin>>s>>d>>w;
        edges.push_back({d,s,w});
    }
    vector<Edge> mst = Krushkal(edges, v);
    for(Edge edge:mst){
        cout << edge.src << " -- " << edge.dst << " == " << edge.weight << endl;
    }
    return 0;
}
