// Good Question
#include<bits/stdc++.h>
using namespace std;

struct Triangle{
	long a,b,c, perimeter;
};

bool compare(struct Triangle t, struct Triangle tr){
	return t.perimeter > tr.perimeter;
}

int main() {
	long n;
	cin >> n;
	long arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	sort(arr,arr+n, greater<int>());
	vector<Triangle> triangles;
	long a,b,c;
	for(int i=0; i<n-2; i++){
		a=arr[i];
		for(int j=i+1;j<n-1;j++){
			b= arr[j];
			c= arr[j+1];
			if((b+c>a) && (a+b>c) && (c+a>b)){
				Triangle tri= {a,b,c,a+b+c};
				triangles.push_back(tri);
			}
		}
		if(!triangles.empty())
			break;
	}
	if(triangles.empty()){
		cout << -1 << endl;
		return 0;
	}
	sort(triangles.begin(), triangles.end(), compare);
	// for(int i=0; i<triangles.size(); i++){
	// 	Triangle tri = triangles[i];
	// 	cout << tri.a << " " << tri.b << " " << tri.c << " " << tri.perimeter << endl;
	// }

	// vector<Triangle> tri;
	// long max = triangles[0].perimeter;
	// for(int i=0; i<triangles.size(); i++)
	// 	if(triangles[i].perimeter==max)
	// 		tri.push_back(triangles[i]);

	a = triangles[0].a;
	b = triangles[0].b;
	c = triangles[0].c;

	cout << c << " " << b << " " << a << endl;


}