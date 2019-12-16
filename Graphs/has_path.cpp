#include <bits/stdc++.h>
using namespace std;

bool has_path(int** edges, int n, int sv, int ev, bool* visited){
    visited[sv]=true;
    bool ans=false;
    for(int i=0; i<n; i++){
        if(i==sv)
            continue;
        if(edges[sv][i] == 1 && !visited[i]){
            if(i == ev){
                return true;
            }
            ans = (ans || has_path(edges, n, i, ev, visited));
        }
    }
    return ans;
}

int main() {
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
    int sv, ev;
    cin >> sv >> ev;
    if(edges[sv][ev] == 1){
        cout << "true" << endl;
        return 0;
    }

    bool* visited= new bool[V];
    for(int i=0; i<V; i++)
        visited[i]=false;

    if(has_path(edges, V, sv, ev, visited)){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

  return 0;
}
