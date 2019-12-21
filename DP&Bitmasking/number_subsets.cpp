#include <bits/stdc++.h>
using namespace std;

int main(){
    int k=9;
    int arr[]= {2, 5, 4, 3, 1};

    int limit = (1<<5) - 1;
    for(int mask=0; mask<limit; mask++){
        int sum=0;
        vector<int> mat{};
        for(int j=0; j<5; j++){
            if((mask & (1<<j)) != 0){
                sum = sum + arr[j];
                mat.push_back(arr[j]);
            }
        }
        if(sum == k){
            vector<int>::iterator it;
            for(it=mat.begin(); it!=mat.end(); it++){
            	cout << *it << " ";
            }
            cout << endl;
        }
    }

}
