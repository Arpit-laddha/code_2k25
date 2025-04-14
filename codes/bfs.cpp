#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[],int x,int y){ // Insertion in undirected graph
    graph[x].push_back(y);
    graph[y].push_back(x);
}
//O(V+E)
vector<int> bfsOfGraph(vector<int> graph[],int v){
    vector<int> res;
    vector<bool> vis(v,false);
    queue<int> q;
    for(int i=0;i<v;i++){ // For disconnected graphs
        if(!vis[i]){
            vis[i]=true;
            q.push(i);
            while(!q.empty()){ //Saving level to level in Queue
                int node=q.front();
                res.push_back(node);
                q.pop();
                vis[node]=true;
                for(auto j:graph[node]){ //Traversing through edges O(E)
                    if(!vis[j]){
                        vis[j]=true;
                        q.push(j);
                    }
                }
            }
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
    vector<int> res(bfsOfGraph(graph,v));
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}