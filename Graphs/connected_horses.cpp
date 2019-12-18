#include<bits/stdc++.h>
using namespace std;

class horse{
public:
    int row;
    int column;
};

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
        int n, m, q;
        cin >> n >> m >> q;
        int** board = new int*[n];
        for(int i=0; i<n; i++){
            board[i] = new int[m];
            for(int j=0; j<m; j++){
                board[i][j]=0;
            }
        }

        vector<int>* edges= new vector<int>[100000000];
        horse* horses = new horse[q];
        for(int i=0; i<q; i++){
            int r,c;
            cin >> r >> c;
            horses[i].row = r;
            horses[i].column = c;
            board[r][c] = i+1;
        }


        for(int i=0; i<q; i++){
            int p,q;
            p = horses[i].row;
            q = horses[i].column;

            int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
            int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

            for (int j = 0; j < 8; j++) {
                int x = p + X[j];
                int y = q + Y[j];

                if (x >= 0 && y >= 0 && x < n && y < m){
                    if(board[x][y] != 0){
                        int position = board[x][y];
                        edges[i].push_back(position);
                    }
                }
            }
        }

        // unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
        // unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
        // while(it1 != components->end()){
        //     unordered_set<int>* component = *it1;
        //     unordered_set<int>::iterator it2= component->begin();
        //     while(it2 != component->end()){
        //         cout << (*it2+1) << " ";
        //         it2++;
        //     }
        //     cout << endl;
        //     it1++;
        // }

    }

    return 0;
}
