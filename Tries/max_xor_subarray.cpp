#include<bits/stdc++.h>
using namespace std;

class trieNode{
public:
    trieNode* left;
    trieNode* right;
};

void insert(int n, trieNode* head){
    cout << n << endl;
    trieNode* curr=head;
    for(int i=31; i>=0; i--){
        int b=(n>>i)&1;
        if(b==0){
            if(!(curr->left)){
                curr->left=new trieNode();
            }
            curr=curr->left;
        }else{
            if(!(curr->right)){
                curr->right=new trieNode();
            }
            curr=curr->right;
        }
    }
}

int findMaxXorSubarray(trieNode* head, int* arr, int n){
    int max_xor=INT_MIN;
    for(int i=0; i<n; i++){
        int value=arr[i];
        trieNode* curr=head;
        int curr_xor=0;
        for(int j=31;j>=0; j--){
            int b=(value>>j)&1;
            if(b==0){
                if(curr->right){
                    curr_xor = curr_xor + pow(2,j);
                    curr = curr->right;
                } else{
                    curr = curr->left;
                }
            }else{
                if(curr->left){
                    curr_xor = curr_xor + pow(2,j);
                    curr=curr->left;
                } else{
                    curr=curr->right;
                }
            }
        }
        trieNode* head=new trieNode();
        insert(curr_xor, head);
        max_xor=max(curr_xor, max_xor);
    }
    return max_xor;
}

int main(){
    int n;
    cin >> n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        //cout << arr[i] << endl;
    }
    trieNode* head = new trieNode();
    for(int i=0; i<n; i++){
        insert(arr[i], head);
    }
    cout << findMaxXorSubarray(head,arr,n) << endl;
    return 0;
}
