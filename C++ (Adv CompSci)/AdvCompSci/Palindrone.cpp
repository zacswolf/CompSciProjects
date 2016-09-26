#include <iostream>
#include <string>


using namespace std;

int main(){
	string word= "hiih";
	bool palindrone = true;
	for (int i = 0; i< word.length()/2; i++){
		if (word.at(i) != word.at(word.length() -1 -i)){
			palindrone = false;
			continue;
		}
	}
	if(palindrone){
		cout << word << " is a palindrone\n";
	}
	else{
		cout << word << " is not a palindrone\n";
	}



	return 0;
}