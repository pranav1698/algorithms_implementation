// Very Very Important
#include<bits/stdc++.h>
using namespace std;

struct node{
  int sum, best_prefix_sum, best_suffix_sum, max_sum;
};

void buildTree(int* arr, node* tree, int start, int end, int treeNode){
  if(start == end){
    node result;
    result.sum=arr[start];
    result.max_sum=arr[start];
    result.best_prefix_sum=arr[start];
    result.best_suffix_sum=arr[start];
    tree[treeNode]=result;
    return;
  }

  int mid=(start+end)/2;
  buildTree(arr,tree,start,mid,2*treeNode);
  buildTree(arr,tree,mid+1,end,2*treeNode+1);

  node left=tree[2*treeNode];
  node right=tree[2*treeNode+1];
  node result;
  result.sum= left.sum + right.sum;
  result.best_prefix_sum = max(left.best_prefix_sum, left.sum + right.best_prefix_sum);
  result.best_suffix_sum = max(right.best_suffix_sum, right.sum + left.best_suffix_sum);
  result.max_sum = max(left.max_sum, max(right.max_sum, left.best_suffix_sum + right.best_prefix_sum));

  tree[treeNode]=result;
}

node query(int* arr,node* tree,int start,int end,int treeNode,int l,int r){
  if(start>r || end<l){
    node nullnode;
    return nullnode;
  }

  if(start>=l && end<=r){
    return tree[treeNode];
  }

  int mid=(start + end)/2;
  if(l>mid)
    return query(arr, tree,mid+1, end, 2*treeNode + 1,l, r);

  if(r<=mid)
    return query(arr, tree,start,mid,2*treeNode,l,r);


  node left=query(arr,tree,start,mid,2*treeNode,l,r);
  node right=query(arr,tree,mid+1,end,2*treeNode+1,l,r);


  node ans;
  ans.sum = left.sum + right.sum;
  ans.best_prefix_sum = max(left.best_prefix_sum, left.sum + right.best_prefix_sum);
  ans.best_suffix_sum = max(right.best_suffix_sum, right.sum + left.best_suffix_sum);
  ans.max_sum = max(left.max_sum, max(right.max_sum, left.best_suffix_sum + right.best_prefix_sum));

  return ans;
}

int main() {
  long n;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];

  node* tree=new node[4*n];
  buildTree(arr, tree, 0,n-1,1);
  // for(int i=0; i<6; i++)
  // cout << tree[i].sum << ' ' << tree[i].max_sum << ' ' << tree[i].best_prefix_sum << ' ' << tree[i].best_suffix_sum << endl;


  int q;
  cin >> q;
  while(q--){
    int l,r;
    cin >> l >> r;
    node ans = query(arr, tree, 0, n-1, 1, l-1, r-1);
    cout << ans.max_sum << endl;
  }
}
