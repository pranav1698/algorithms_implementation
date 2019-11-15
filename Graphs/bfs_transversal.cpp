#include <bits/stdc++.h>
using namespace std;

void print_bfs(int** edges, int n, int sv, bool* visited){
    queue <int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv]=true;

    while(!pendingVertices.empty()){
        int currentVertice=pendingVertices.front();
        cout << currentVertice << " ";
        pendingVertices.pop();
        visited[sv]=true;
        for(int i=0; i<n; i++){
            if(i == currentVertice){
                continue;
            }
            if(edges[currentVertice][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
}

void BFS(int** edges, int n){
    bool* visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i]=false;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            print_bfs(edges, n, i , visited);
        }
    }

    delete[] visited;
}

int main() {
    int V, E;
    cin >> V >> E;
    int** edges=new int*[V];
    for(int i=0; i<V; i++){
        edges[i] = new int[V];
        for(int j=0; j<V; j++)
            edges[i][j]=0;
    }

    for(int i=0; i<E; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    // Adjacency Matrix Printed

    bool* visited= new bool[V];
    for(int i=0; i<V; i++)
        visited[i]=false;

    queue <int> b_queue;
    b_queue.push(0);
    BFS(edges, V);
    return 0;
}
