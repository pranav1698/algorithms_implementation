#include<bits/stdc++.h>
using namespace std;

void merge(int* A, int left, int mid, int right){
    //Store the lefting position of both parts in empty array
    int i=left, j=mid, k=0;
    int temp[right-left+1];
    
    while(i<mid && j<=right){
        if(A[i] <= A[j]){
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
    }
    while(i<mid){
        temp[k++] = A[i++];
    }
    while(j<=right){
        temp[k++] = A[j++];
    }

    for(int i=left, k=0; i<=right; i++,k++){
        A[i]=temp[k];
    }
}

void mergeSort(int* A, int left, int right){
    int mid= left + (right-left)/2;

    mergeSort(A, left, mid);
    mergeSort(A, mid+1, right);

    merge(A, left, mid+1, right);
}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int A[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(A)/sizeof(A[0]); 
  
    printf("Given array is \n"); 
    printArray(A, n); 
  
    mergeSort(A, 0, n-1); 
  
    printf("\nSorted array is \n"); 
    printArray(A, n); 
    return 0; 
} 