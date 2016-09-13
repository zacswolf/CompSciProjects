#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string In="";
	
	
	string string1;
	string string2;
	cout<<"Whats String1?";
	cin>>string1;
	cout<<"Whats String2?";
	cin>>string2;
	
	int index = string1.find(string2, 0);
	cout <<"string 2 is at string1 starting at: " << index;
	
	
	
	
	return 0;
}