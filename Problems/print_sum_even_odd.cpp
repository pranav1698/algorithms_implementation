#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i =0; i <n; i++){
        arr[i] = 0;
        cin >> arr[i];
    }
    int esum=0, osum=0;
    for(int i =0; i < n; i++){
        if(i % 2 == 0){
            if(arr[i] % 2 == 0){
                esum += arr[i];
            }
        } else {
            if(arr[i] % 2 != 0){
                osum += arr[i];
            }
        }
    }

    cout << esum << " " << osum << endl;
	return 0;
}
