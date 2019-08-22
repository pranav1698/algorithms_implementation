#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int curr=0;
    while(arr[curr]!=0){
        for(int i=0; i<n; i++)
            if(arr[i]!=0)
                arr[i]--;
        curr++;
        if(curr == n)
            curr=0;
    }
    cout << curr+1 << endl;
    return 0;
}
