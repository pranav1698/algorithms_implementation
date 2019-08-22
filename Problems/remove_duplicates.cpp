#include<bits/stdc++.h>
using namespace std;


void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
	if(s[0] == '\0')
		return;

	if(s[0]==s[1]){
		int i=1;
		for(;input[i]!='\0';i++)
			input[i] = input[i+1];
		input[i] = input[i+1];
		removeConsecutiveDuplicates(input);
	} else{
		removeConsecutiveDuplicates(input+1);
	}
}