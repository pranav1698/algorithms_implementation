#include<bits/stdc++.h>
using namespace std;

bool is_possible(unordered_set<unordered_set<int>*>* components, int* p, int* q){
    bool ans = true;
    unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
    while(it1 != components->end()){
        unordered_set<int>* component = *it1;
        unordered_set<int>::iterator it2= component->begin();
        vector<int> p_subset;
        vector<int> q_subset;
        while(it2 != component->end()){
            p_subset.push_back(p[*it2]);
            q_subset.push_back(q[*it2]);
            it2++;
        }
        sort(p_subset.begin(), p_subset.end());
        sort(q_subset.begin(), q_subset.end());
        if(p_subset == q_subset){
            ans = ans && true;
        } else {
            ans = ans && false;
        }
        it1++;
    }
    return ans;
}

void dfs(vector<int>* edges, int sv, bool* visited, unordered_set<int>* component){
    visited[sv]=true;
    component->insert(sv);
    for(int i=0; i<edges[sv].size(); i++){
        int next = edges[sv][i];
        if(!visited[next]){
            dfs(edges, next, visited, component);
        }

    }
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n){
    bool* visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i]=false;

    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for(int i=0; i<n; i++){
        if(!visited[i]){
            unordered_set<int>* component = new unordered_set<int>();
            dfs(edges,i,visited, component);
            output->insert(component);
        }
    }
    return output;
}


int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int* p = new int[n];
        for(int i=0; i<n; i++)
            cin >> p[i];

        int* q = new int[n];
        for(int i=0; i<n; i++)
            cin >> q[i];
        vector<int>* edges = new vector<int>[n];
        for(int i=0; i<m; i++){
            int j, k;
            cin >> j >> k;
            edges[j-1].push_back(k-1);
            edges[k-1].push_back(j-1);
        }
        unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
        
        if(is_possible(components, p, q)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
