#include <bits/stdc++.h>
using namespace std;

vector<int> print(int** edges, int n, int sv, vector<int> ans, bool* visited){
    ans.push_back(sv);
    visited[sv]=true;
    for(int i=0; i<n; i++){
        if(i==sv)
            continue;
        if(edges[sv][i]==1 && !visited[i]){
            ans = print(edges, n, i, ans, visited);
        }
    }
    return ans;
}

void DFS(int** edges, int n){
    bool* visited= new bool[n];
    for(int i=0; i<n; i++)
        visited[i]=false;

    for(int i=0; i<n; i++){
        vector<int> ans{};
        if(!visited[i]){
            ans=print(edges, n, i, ans, visited);
            sort(ans.begin(), ans.end());
            for (auto i = ans.begin(); i != ans.end(); ++i)
                cout << *i << " ";

            cout << endl;
        }
    }

}

int main(){
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i]=new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++){
        int f, s;
        cin >> f >>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    DFS(edges, n);

}
