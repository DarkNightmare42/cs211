#include <iostream>
using namespace std;

bool equivalent(int a[], int b[], int n){
	for (int index = 0; index < n; index++){
		for (int i = 0; i < n; i++){
			cout << b[i] << " " << a[index] << endl;
			if (a[index] == b[i]) index++;
		}
	}
	return false;
}

int main(){
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {3, 4, 5, 6, 2};
	
	cout << "Both arrays are equivalent: " << equivalent(a, b, 5);
}
