#include <bits/stdc++.h>
using namespace std;

map<int, int> get_bfs_path(int** edges, int n, int sv, int ev, bool* visited){
    queue <int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv]=true;
    map<int, int> ans;

    while(!pendingVertices.empty()){
        int currentVertice = pendingVertices.front();
        pendingVertices.pop();
        for(int i=0; i<n; i++){
            if(i == currentVertice)
                continue;
            if(edges[currentVertice][i] == 1 && !visited[i]){
                ans[i] = currentVertice;
                if(i == ev){
                    return ans;
                }
                pendingVertices.push(i);
                visited[i]=true;
            }
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
    int sv, ev;
    cin >> sv >> ev;
    if(sv == ev){
        cout << ev << endl;
        return 0;
    }
    bool* visited= new bool[V];
    for(int i=0; i<V; i++)
        visited[i]=false;

    map<int, int> ans;
    ans = get_bfs_path(edges, V, sv, ev, visited);
    if(ans.size() == 0){
        return 0;
    }
    cout << ev << " ";
    int curr = ans[ev];
    while(curr != sv){
        cout << curr << " ";
        curr = ans[curr];
    }
    cout << sv << endl;
    return 0;
}
