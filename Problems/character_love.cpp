#include<bits/stdc++.h>
using namespace std;
int main()
{
    int length;
    cin >> length;
    string s;
    cin >> s;
    
    map<char, int> frequencyChar;
    for(int i=0; i<length; i++){
        frequencyChar[s[i]] = frequencyChar[s[i]] + 1;
    }
    
    map<char, int>::iterator it;
    
    cout << frequencyChar['a'] << " ";
    cout << frequencyChar['s'] << " ";
    cout << frequencyChar['p'] << endl;
    
    cout << endl;
	return 0;
}
