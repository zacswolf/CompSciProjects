#include <fstream>
#include <iostream>
using namespace std;

int main(){
	ofstream myfile ("example.txt");
	if (myfile.is_open()){
		cout << "good file\n";
		myfile.close(); // end it
	}
	else{
		cout << "bad file\n";
	}
	
	
	
	return 0;
}