#include<iostream>
using namespace std;

int power(int p, int n) { 
    if(n == 0)
        return 1;
    return p * power(p, n-1);
    
    
}

int main() { 
    int p,n;
    cin >> p >> n;
    
    cout << power(p,n) << endl;
    
}
