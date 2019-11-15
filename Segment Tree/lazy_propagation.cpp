#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr, int* tree, int start, int end, int treeNode){
    if(start==end){
        tree[treeNode] = arr[start];
        return;
    }

    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    tree[treeNode]=min(tree[2*treeNode], tree[2*treeNode+1]);
}

void updateSegmentTreeLazy(int* tree, int* lazy, int low, int high, int start, int end, int currPos, int inc){
    if(low > high)
        return;

    if(lazy[currPos] != 0){
        tree[currPos] = tree[currPos] + lazy[currPos];
        if(low!=high){
            lazy[2*currPos] = lazy[2*currPos] + lazy[currPos];
            lazy[2*currPos + 1] = lazy[2*currPos + 1] + lazy[currPos];
        }
        lazy[currPos] = 0;
    }

    if(start>high || end<low){
        return;
    }

    if(start<=low && high<=end){
        tree[currPos] = tree[currPos] + inc;
        if(low != high){
            lazy[2*currPos] = lazy[2*currPos] + inc;
            lazy[2*currPos+1] = lazy[2*currPos + 1] + inc;
        }
        return;
    }

    int mid = (low+high)/2;
    updateSegmentTreeLazy(tree,lazy,low,mid,start,end,2*currPos,inc);
    updateSegmentTreeLazy(tree,lazy,mid+1,high,start,end,2*currPos+1,inc);
    tree[currPos] = min(tree[2*currPos], tree[2*currPos+1]);
}

int query(int* tree,int* lazy, int low, int high, int treeNode, int start, int end){
    if(lazy[treeNode] !=0){
        tree[treeNode] = tree[treeNode] + lazy[treeNode];
        if(low!=high){
            lazy[2*treeNode] = lazy[2*treeNode] + lazy[treeNode];
            lazy[2*treeNode+1] = lazy[2*treeNode+1] + lazy[2*treeNode + 1];
        }
        lazy[treeNode]=0;
    }

    if(start>high || end<low){
        return INT_MAX;
    }

    if(start<=low && end>=high){
        return tree[treeNode];
    }

    int mid=(low+high)/2;
    if(start>mid)
      return query(tree,lazy,mid+1,end,2*treeNode+1, start, end);

    if(end<=mid)
      return query(tree,lazy,start,mid,2*treeNode,start,end);

    int q1=query(tree,lazy,low,mid,2*treeNode,start,end);
    int q2=query(tree,lazy,mid+1,end,2*treeNode+1,start,end);
    cout << q1 << " " << q2;
    return min(q1,q2);
}

int main(){
    int arr[]={1,3,-2,4};
    int* tree = new int[16];
    int* lazy = new int[16];
    buildTree(arr,tree,0,3,1);
    updateSegmentTreeLazy(tree,lazy,0,3,0,3,1,3);
    updateSegmentTreeLazy(tree,lazy,0,3,0,1,1,2);

    cout << "Segment Tree" << endl;
    for(int i=0; i<16; i++)
        cout << tree[i] << endl;
    cout << endl;
    for(int i=0;i<16; i++)
        cout << lazy[i] << endl;

    int ans=query(tree,lazy,0,3,1,2,1);
    cout << ans << endl;
}
