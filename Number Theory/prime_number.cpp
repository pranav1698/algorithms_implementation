#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkPrime(ll n){
    int countFactors=0;
    for(int j=1; j<=n; j++){
        if((n%j)==0){
            if((j*j)==n){
                count=count+1;
            } else {
                countFactors = countFactors + 2;
            }
        }
    }
    if(countFactors == 2){
        return true;
    }
    return false;
}

int main(){
	// Write your code here
    ll n;
    cin >> n;
    int count=0;
    for(ll i=2;i<=n;i++){
        if(checkPrime(i)){
            //cout << i << endl;
            count=count+1;
        }
    }

    cout << count << endl;
	return 0;
}
