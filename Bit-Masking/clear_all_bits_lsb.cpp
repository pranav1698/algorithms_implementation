void clearAllBitsFromLSB(int n, int i){
	int M= ~((1 << i+1) - 1);
	cout << (N & M) << endl; 
}