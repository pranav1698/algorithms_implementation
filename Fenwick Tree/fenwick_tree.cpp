#include <bits/stdc++.h>
using namespace std;

void update(int index, int value, int* bit, int n){
    while(index<=n){
        bit[index] = bit[index] + value;
        index = index + (index&(-index));
    }
}

int query(int index, int* bit){
    int sum=0;
    while(index>0){
        //cout << index << endl;
        sum = sum + bit[index];
        index = index - (index&(-index));
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int* arr=new int[n+1]();
    int* bit=new int[n+1]();

    for(int i=1;i<=n;i++){
        cin >> arr[i];
        update(i,arr[i],bit, n);
    }

    cout << "Sum of first 5 elements" << query(5, bit) << endl;
    cout << "Sum of elements from 2 index to 6 index" << query(6,bit) - query(1,bit) <<endl;
    return 0;
}
