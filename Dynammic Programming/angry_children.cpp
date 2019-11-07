// Important and unusual
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    ll x[n];
    sort(x, x+n);
    for(int i=0; i<n; i++)
        cin >> x[i];
    sort(x, x+n);
    ll cost[k];
    cost[0]=0;
    ll sum=0;
    for(int i=1; i<k; i++){
        sum = sum + x[i-1];
        cost[i] = cost[i-1] + i*x[i] - sum;
    }

    ll target=cost[k-1];
    int i=0;
    while((k + i) < n){
        ll sum2=0;
        for(int i=1; i<k; i++){
            sum2 = sum2 + x[i];
        }
        ll new_target = target - 2*sum2 + (k-1)*x[i] + (k-1)*x[k+i];
        target = min(target, new_target);
        i=i+1;
    }

    cout << target << endl;
    return 0;
}
