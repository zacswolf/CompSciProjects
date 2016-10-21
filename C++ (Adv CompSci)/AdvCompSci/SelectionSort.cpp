#include <iostream>
using namespace std;

void selectionSort(int arr[], int size){
	int first;
	int temp;
	for (int i = size-1;i>0; i--){
		first =0;
		for (int j = 1; j <=i; ++j){
			if (arr[j] < arr[first]){
				first = j;
			}
			temp = arr[first];
			arr[first] = arr[i];
			arr[i] = temp;
		}
	}
	
}

int main(){
	int a[5] = {5,3,1,4,2};
	selectionSort(a, 5);
	for (int k = 0; k < 5; k++){
		cout << a[k] << endl;
	}
}

