#include <iostream>
#include <string>

void message(int x){
	if(x>2){
		std::cout << x << " bottles of beer on the wall, " << x << " bottles of beer.\n";
		std::cout << "Take one down and pass it around, " << (x-1) << " bottles of beer on the wall.\n";
	
	}
	else if(x==2){
		std::cout << x << " bottles of beer on the wall, " << x << " bottles of beer.\n";
		std::cout << "Take one down and pass it around, " << (x-1) << " bottle of beer on the wall.\n";
	}
	if(x==1){
		std::cout << x << " bottle of beer on the wall, " << x << " bottle of beer.\n";
		std::cout << "Take one down and pass it around, " << "no more" << " bottles of beer on the wall.\n";
	}
	if(x==0){
		std::cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
		std::cout << "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
	}
}


void normalRecursion(int x){
	if (x == 99){
		message(x);
	}
	else{
		normalRecursion(x+1);
		message(x);
	}
	
}

int main(){
	normalRecursion(0);
	return 0;
}