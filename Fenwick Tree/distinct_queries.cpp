#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct query {
    int index;
    int f;
    int s;
};

bool compare(query q1, query q2){
    return q1.s < q2.s;
}

void update(int index, int value, int* bit, int n){
    while(index<=n){
        bit[index] = bit[index] + value;
        index = index + (index&(-index));
    }
}

int calculate(int index, int* bit){
    int total=0;
    while(index>0){
        total = total + bit[index];
        index = index - (index&-index);
    }
    return total;
}

int main()
{
    int n;
    cin >> n;
    ll* arr=new ll[n+1]();
    for(int i=1; i<=n; i++)
        cin >> arr[i];

    ll q;
    cin >> q;
    query* queries = new query[n];
    for(ll i=0; i<q; i++){
        cin >> queries[i].f >> queries[i].s;
        queries[i].index = i;
    }

    sort(queries, queries+q, compare);

    int* bit = new int[n+1]();
    int* ans=new int[q];
    int* last=new int[100001];
    int total=0;
    int k=0;
    for(int i=0; i<=100001; i++){
        last[i]=-1;
    }
    for(int i=1; i<=n; i++){
        if(last[arr[i]] != -1){
            update(last[arr[i]], -1, bit, n);
        } else {
            total++;
        }
        update(i,1,bit,n);
        last[arr[i]]=i;
        while(k<q && queries[k].s==i){
            ans[queries[k].index] = total - calculate(queries[k].f-1, bit);
            k++;
        }
    }

    for(int i=0; i<q; i++){
        cout << ans[i] << endl;
    }



    return 0;
}
