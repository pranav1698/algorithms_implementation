#include <bits/stdc++.h>
using namespace std;

int turnOnIthBit(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	int Z = 1 << i;
	return (n | Z);    
}

int main(){
	cout << turnOnIthBit(4,4) << endl;

}

