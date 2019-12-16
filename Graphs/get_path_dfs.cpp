#include <bits/stdc++.h>
using namespace std;

vector<int> get_dfs_path(int** edges, int n, int sv, int ev, vector<int> ans, bool* visited){
    visited[sv]=true;
    for(int i=0; i<n; i++){
        if(i == sv)
            continue;
        if(edges[sv][i] == 1 && !visited[i]){
            if(i == ev){
                ans.push_back(i);
                return ans;
            }
            ans = get_dfs_path(edges, n, i, ev, ans, visited);
        }
        if(!ans.empty()){
            ans.push_back(i);
            return ans;
        }
    }
    return ans;
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
        cout << ev << " ";
        return 0;
    }

    bool* visited= new bool[V];
    for(int i=0; i<V; i++)
        visited[i]=false;

    vector<int> ans{};
    ans=get_dfs_path(edges, V, sv, ev, ans, visited);
    if(!ans.empty()){
        ans.push_back(sv);
    }

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";
    return 0;
}
