#include <bits/stdc++.h>
using namespace std;

void is_connected(int** edges, int n, int sv, bool* visited){
    visited[sv]=true;
    for(int i=0; i<n; i++){
        if(i==0)
            continue;
        if(edges[sv][i] == 1 && !visited[i]){
            is_connected(edges, n, i, visited);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i=0; i<V; i++){
        edges[i]=new int[V];
        for(int j=0; j<V; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<E; i++){
        int f, s;
        cin >> f >>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    bool* visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i]=false;

    is_connected(edges, V, 0, visited);
    bool flag=true;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            flag=false;
        }
    }

    if(flag){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

}
