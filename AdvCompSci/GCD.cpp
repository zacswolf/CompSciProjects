#include <iostream>

using namespace std;



int GCD(int m, int n){
	int r = m%n;
	if (r == 0){
		return n;
	}
	else{
		m=n;
		n=r;
		GCD(m,n);
	}


}





int main(){
	int num1,num2;
	cout << "num 1?" << endl;
	cin >> num1;
	cout << "num 2?" << endl;
	cin >> num2;
	cout << GCD(num1,num2);
}


