#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[],int x,int y){ // Insertion in undirected graph
    graph[x].push_back(y);
    graph[y].push_back(x);
}
//O(V+E)
void dfs(vector<int> &res,vector<bool> &vis,vector<int> graph[],int node){
    vis[node]=true;
    res.push_back(node);
    for(int i:graph[node]){ //Traveling through edges O(E)
        if(!vis[i]) dfs(res,vis,graph,i);
    }
}
//O(V+E)
vector<int> dfsOfGraph(vector<int> graph[],int v){
    vector<int> res;
    vector<bool> vis(v,false);
    //Taking 0 node as first node
    for(int i=0;i<v;i++){ //For disconnected graphs
        if(!vis[i]){
            dfs(res,vis,graph,i);
        }
    }
    return res;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> graph[v]; //Adjacency List - Array of Vectors
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        addEdge(graph,x,y);
    }
    vector<int> res(dfsOfGraph(graph,v));
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}