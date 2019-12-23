#include <bits/stdc++.h>
using namespace std;

struct coder{
    int index;
    int x;
    int y;
};


bool compare(coder s1, coder s2){
    if(s1.x == s2.x){
        return s1.y < s2.y;
    }
    return s1.x < s2.x;
}


void update(int y, int* bit){
    while(y<=10000){
        bit[y]=bit[y] + 1;
        y = y + (y&(-y));
    }
}

int query(int y, int* bit){
    int value = 0;
    while(y>0){
        value = value + bit[y];
        y = y - (y&(-y));
    }
    return value;
}


int main()
{
    int n;
    cin >> n;
    coder* arr = new coder[n];
    for(int i=0;i<n;i++){
        int o, h;
        cin >> o >> h;
        arr[i].index=i;
        arr[i].x=o;
        arr[i].y=h;
    }
    sort(arr, arr+n, compare);
    int* bit= new int[100001];
    int* ans = new int[n];

    for(int i=0;i<n;){
        int endIndex = i;

		while(endIndex <n && arr[endIndex].x == arr[i].x && arr[endIndex].y == arr[i].y){
			endIndex++;
		}
		
		for(int j=i;j<endIndex;j++){
			ans[arr[j].index] = query(arr[j].y);
		}

		for(int j=i;j<endIndex;j++){
			update(arr[j].y);
		}

		i = endIndex;

    }


    for(int i=0;i<n;i++){
		cout << ans[i] <<endl;
    }
    return 0;
}
