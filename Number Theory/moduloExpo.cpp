#include <bits/stdc++.h>
using namespace std;

int modExpo(int a, int b, int c){
     if(a == 0)
        return 0;
    if(b == 0)
        return 1;

    long ans;
    if(b%2==0){
        long smallAns = modExpo(a, b/2,c);
        ans= (smallAns*smallAns)%c;
    } else {
        long smallAns= modExpo(a, b-1, c);
        ans = (a%c);
        ans = (ans*smallAns)%c;
    }
    return int((ans + c)%c);
}

int modExpoI(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y%2 != 0)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;

}


int main(){
    int a=2;
    int b=10;
    int c=5;
    cout << modExpo(a, b, c) << endl;
    return 0;
}
