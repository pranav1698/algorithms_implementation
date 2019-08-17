// very Important
#include <unordered_map>

vector<int> longestSubsequence(int* arr, int n){
	unordered_map<int, bool> hm;
	for(int i=0; i<n; i++){
		if(hm.count(arr[i]) == 0){
			hm[arr[i]] = true;
		}
	}
	vector<int> output;
	int maxCount=1;
	int startNum=arr[0];
	for(int i=0; i<n; i++){
		int count=0;
		int tempNum=arr[i];
		while(hm.count(tempNum) == 1){
			count++;
			tempNum++;
		}
		if(count >maxCount){
			maxCount=count;
			startNum=arr[i];
		}
	}
	output.push_back(startNum);
	maxCount--;
	while(maxCount != 0){
		startNum++;
		output.push_back(startNum);
		maxCount-;
	}
	return output;

}