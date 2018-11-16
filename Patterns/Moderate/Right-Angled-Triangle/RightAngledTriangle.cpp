#include<iostream>

using namespace std;

int main(){

	int T;
	cin >> T;
	int C[T];
	
	for(int i=0; i<T; i++)
		cin >> C[i];
	
	for(int i=0; i<T; i++){
		cout<<"Case #" <<C[i] <<endl;
		for(int j = 0; j<C[i]; j++){
			for(int space = 0; space<(C[i]-j-1); space++)
				cout<<" ";
			for(int star = 0; star <= j; star++)
				cout<<"*";
			cout<<"\n";
		}
	}
	return 0;
}
