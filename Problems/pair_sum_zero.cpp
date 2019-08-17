#include<bits/stdc++.h>
using namespace std;
	void PairSum(int *input, int n) {	 
		
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Don't need to return anything. Print the desired pairs in the function itself.
     	*/
     	sort(input, input+n);
        for(int i=0; i<n; i++){
            int sum=input[i];
            for(int j=i+1; j<n; j++){
                sum=sum+input[j];
                if(sum == 0)
                    cout << input[i] << " " << input[j] << endl;
                sum=input[i];
            }
        }
     	
     	
 	}

