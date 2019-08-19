#include<bits/stdc++.h>
using namespace std;
int main()
{
    int shops;
    cin >> shops;
    int rates[shops];
    for(int i=0; i<shops; i++){
        cin >> rates[i];
    }
    int days;
    cin >> days;
    while(days--){
        int money;
        cin >> money;
        int j=0;
        int sum=0;
        int count=0;
        while(sum <= money){
            sum = sum + rates[j];
            count = count +1;
            j++;
        }
        sum = sum - rates[j-1];
        cout << count-1 << " " << (money-sum) << endl; 
    }
    
	return 0;
}
