// Important and Unusual
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m;
    cin >> n >> m;
    ll arr[2][m];
    ll row[2][m];
    ll Min[n+1];
    Min[0]=1;
    int flag=1;

    for(int j=0; j<m; j++){
        cin >> arr[0][j];
        row[0][j]=1;
    }

    ll min_r;
    for(int i=1; i<n; i++){
        min_r = LLONG_MAX;
        for(int j=0; j<m; j++){
            cin >> arr[flag][j];
        }
        for(int j=0; j<m; j++){
            if(arr[flag][j] >= arr[flag^1][j]){
                row[flag][j] = row[flag^1][j];
            } else {
                row[flag][j] = i+1;
            }
        }
        for(int j=0; j<m; j++){
            min_r = min(min_r, row[flag][j]);
        }
        Min[i]=min_r;
        flag=flag^1;
    }

    int q;
    cin >> q;
    while(q--){
        int l , r;
        cin >> l >> r;
        //cout << Min[r-1] << endl;
        if(Min[r-1] <= l){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
