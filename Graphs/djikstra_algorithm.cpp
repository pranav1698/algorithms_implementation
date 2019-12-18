#include <bits/stdc++.h>
using namespace std;

int getMinVertex(bool* visited, int n, int* distance){
    int minVertex=-1;
    for(int i=0; i<n; i++){
        if(!visited[i] && ((minVertex==-1) || distance[minVertex]>distance[i])){
            minVertex=i;
        }
    }
    return minVertex;
}

void djikstra(int** edges, int n){
    bool* visited= new bool[n];
    int* distance = new int[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }

    distance[0]=0;

    for(int i=0;i<n-1;i++){
        int minVertex = getMinVertex(visited, n, distance);
        visited[minVertex]=true;

        for(int i=0;i<n;i++){
            if(!visited[i] && edges[minVertex][i]!=0){
                if(distance[i] > (distance[minVertex] + edges[minVertex][i])){
                    distance[i] = distance[minVertex] + edges[minVertex][i];
                }
            }
        }
    }

    for(int i=0; i<n; i++)
        cout << i <<  " " << distance[i] << endl;

    delete[] distance;
    delete[] visited;
    return;
}

int main()
{
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
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    djikstra(edges, n);

    return 0;
}
