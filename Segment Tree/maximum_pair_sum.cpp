// Very Important
#include<bits/stdc++.h>
using namespace std;

struct node{
  int max;
  int smax;
};

void buildTree(int* arr, node* tree, int treeNode, int start, int end){
  if(start == end){
    tree[treeNode].max=arr[start];
    tree[treeNode].smax=INT_MIN;
    return;
  }

  int mid=(start + end)/2;
  buildTree(arr,tree,2*treeNode,start,mid);
  buildTree(arr,tree,2*treeNode+1,mid+1,end);

  node left = tree[2*treeNode];
  node right = tree[2*treeNode + 1];
  tree[treeNode].max = max(left.max, right.max);
  tree[treeNode].smax = min(max(left.max, right.smax), max(right.max, left.smax));
}

void updateTree(int* arr, node* tree, int treeNode, int start, int end, int index, int value){
  if(start == end){
    arr[index]=value;
    tree[treeNode].max=value;
    tree[treeNode].smax=INT_MIN;
    return;
  }

  int mid=(start + end)/2;
  if(index > mid){
    updateTree(arr,tree,2*treeNode+1,mid+1,end,index,value);
  } else {
    updateTree(arr,tree,2*treeNode,start,mid,index,value);
  }

  node left = tree[2*treeNode];
  node right = tree[2*treeNode + 1];
  tree[treeNode].max = max(left.max, right.max);
  tree[treeNode].smax = min(max(left.max, right.smax), max(right.max, left.smax));
}

node query(int* arr, node* tree, int treeNode, int start, int end, int left, int right){
  if(start>right || end<left){
    node nullNode;
    return nullNode;
  }

  if(start>=left && end<=right){
    return tree[treeNode];
  }

  int mid=(start + end)/2;
  if(left>mid)
    return query(arr, tree,2*treeNode+1,mid + 1, end, left, right);

  if(right<=mid)
    return query(arr, tree, 2*treeNode, start,mid,left,right);

  node left_ans=query(arr,tree,2*treeNode, start,mid,left,right);
  node right_ans=query(arr,tree,2*treeNode+1, mid+1,end,left,right);
  node ans;
  ans.max=max(left_ans.max, right_ans.max);
  ans.smax= min(max(left_ans.max,right_ans.smax),
            max(left_ans.smax,right_ans.max)
            );
  return ans;
}

int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++)
    cin>>arr[i];

  node* tree=new node[4*n];
  buildTree(arr,tree,1,0,n-1);

  int q;
  cin >> q;
  for(int i=0; i<q; i++){
    char c;
    int l, r;
    cin >> c >> l >> r;
    if(c == 'U'){
      updateTree(arr, tree, 1, 0, n-1, l-1, r);

    } else {
      node ans = query(arr, tree, 1, 0, n-1, l-1, r-1);
      cout << ans.max + ans.smax << endl;
    }
  }
}
