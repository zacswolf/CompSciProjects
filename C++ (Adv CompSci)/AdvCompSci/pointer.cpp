#include <iostream>
#include <string>

using namespace std;
int main(){
	//int testing
	int num =1;
	int* intaddress = &num;
	cout << &num << endl << intaddress<<endl;
	int aa = *intaddress;
	
	cout << aa <<endl<< "end of int test\n";
	
	//string testing
	string str = "Hi";
	string* straddress = &str;
	cout << &str << endl << straddress<<endl;
	string ab = *straddress;
	
	cout << ab <<endl << "end of string test\n";
	
	
	//int[] testing
	int arr[5] = {1,2,3,4,5};
	int* arraddress = arr;
	cout << &arr << endl << arraddress<<endl;
	int* ac = arraddress;
	
	cout << ac[0]<<" "<<ac[1]<<" "<<ac[2]<<" "<<ac[3]<<" "<<ac[4] << endl << "end of int test\n";
	
	
	
}