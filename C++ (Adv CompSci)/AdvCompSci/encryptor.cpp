#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
	string strkey;
	int ascikey =0;
	string message;
	string encrypt ="";
	cout << "Whats your key?\n";
	cin >> strkey;
	cout << "Whats your message?\n";
	cin >> message;
	
	//cout << message << "\t" << strkey << endl;
	
	int k=0;
	for (int j =0; j < message.length(); j++){
		char a = message.at(j)^strkey.at(k%strkey.length());
		encrypt+= a;
		k++;
		
		//cout << a << endl;
		
		if(a < 100) {
			cout << "0";
		}
		if(a < 10) {
			cout << "0";
		}
		cout << ((int)a);
		cout << " ";
	}
	//cout << encrypt << endl;
	
	/*for (int i =0; i < strkey.length(); i++){
		int a = strkey.at(i);
		ascikey+= a;
		
		
		
		//binkey = sprintf((int)key.at(i))
		//int n = sprintf(binkey,"%04X",(int)strkey.at(i));
		cout << ascikey << endl;
	}*/
	
	
	
}