#include <bits/stdc++.h>
using namespace std;

class edge{
    public:
        int src;
        int dst;
        int weight;
};

bool compare(edge e1, edge e2){
    return e1.weight < e2.weight;
}

int getParent(int v, int* parent){
    if(parent[v] == v){
        return v;
    }
    return getParent(parent[v], parent);
}

int main()
{
    int V, E;
    cin >> V >> E;
    edge* input = new edge[E];
    for(int i=0; i<E; i++){
        int s, d, w;
        cin >> s >> d >> w;
        input[i].src=s;
        input[i].dst=d;
        input[i].weight=w;
    }
    sort(input, input+E, compare);

    edge* output= new edge[V-1];
    int* parent = new int[V];
    for(int i=0; i<V; i++)
        parent[i]=i;

    int count=0;
    int i=0;

    while(count!=(V-1)){
        edge currEdge = input[i];
        int srcParent = getParent(currEdge.src, parent);
        int dstParent = getParent(currEdge.dst, parent);
        if(srcParent != dstParent){
            output[count] = currEdge;
            count = count + 1;
            parent[srcParent] = parent[dstParent];
        }
        i = i+1;
    }

    for(int i=0; i<V-1; i++){
         if(output[i].src < output[i].dst){
            cout << output[i].src << " " << output[i].dst << " " << output[i].weight << endl;
        } else {
            cout << output[i].dst << " " << output[i].src << " " << output[i].weight << endl;
        }
    }


    return 0;
}
