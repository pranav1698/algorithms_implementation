#include<bits/stdc++.h>
using namespace std;

void swap(int* x, int* y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int* input, int left, int right){
	int x=input[left];
	cout << x << endl;
	int count=0;
	for(int i=left; i<=right; i++){
		if(input[i] < x)
			count++;
	}
	int index=left+count;
	swap(&input[left], &input[index]);

	int i=left;
	int j=right;
	while(i<index && j>index){
		if(input[i] < x){
			i++;
		} else if(input[j] >= x){
			j--;
		} else {
			swap(&input[i], &input[j]);
		}
	}

	return index;
}

void quicksort(int* input, int left, int right){
	if(left>=right)
		return;

	int c=partition(input, left, right);

	quicksort(input, left, c-1);
	quicksort(input, c+1, right);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    int start=0;
    int end=size-1;

    quicksort(input, start, end);
}

int main(){
	int arr[]={2, 6, 8, 5, 4, 3};
	quickSort(arr,6);

	for(int i=0; i<6; i++){
		cout << arr[i] << " ";
	}
	return 0;
}