//Important
#include<bits/stdc++.h>
using namespace std;

struct Item{
	int value, weight;
};

bool compare(struct Item a, struct Item b){
	double value1 = ((double) a.value)/(a.weight);
	double value2 = ((double) b.value)/(b.weight);
	return value1 > value2;
}

double fKnapsnack(struct Item arr[], int W, int n){
	sort(arr, arr+n, compare);
	int currW=0;
	double finalValue=0;

	for(int i=0; i<n; i++){
		if(currW + arr[i].weight <= W){
			currW += arr[i].weight;
			finalValue += arr[i].value;
		} else {
			int rWeight = W-currW;
			finalValue += arr[i].value * ((double)(rWeight)/arr[i].weight);
			break;
		}
	}
}

int main(){
	int W=70;
	Item arr[]={{60,20}, {70,15}, {80,40}};
	cout << "Maximum value i " << fKnapsnack(arr, W, 3);
}