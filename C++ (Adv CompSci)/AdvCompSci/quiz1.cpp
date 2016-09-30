#include <iostream>
#include <string>

using namespace std;


struct movies_t {
string title;
int year;
} Cinderalla, StarWars, Sully;

struct friends_t {
string name;
string email;
movies_t *favorite_movie;
} charlie, maria;

friends_t * pfriends = &charlie;


void myFunc(int a[][3]){
	
}


void myPtrFunc(int *a)
{
   cout << "Array " << *a << endl;
}


string testFunc(string str){
	int start = str.find("star", 0);
	start = str.find("twinkle", start);
	start = str.find("twinkle", start);
	return str.erase(start, 7);
}


int main(){

	int x = 1;
	
	int &refX =x;
	
	cout << x << endl << refX << endl << &x << endl << &refX << endl;
	
	int z = 12;
	z *= 4 + 8;
	cout << "z: " << z << endl;
	
	int a = 10;
	int b = 20;
	int c= 9;
	int good = a==0 ? true : b > a ? c<b ? c : 4  : 30;
	cout << "Good: " << good << endl;

	StarWars.year = 1977;
	StarWars.title = "A New Hope";
	charlie.favorite_movie = &StarWars;
	
	cout << charlie.favorite_movie->title << endl;
	cout << pfriends->favorite_movie->title << endl;
	
	
	
	
	int myArray[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};   
	myFunc(myArray);
	
	
	
	int xa =0b10011011;    //ask Mr. shocky why
	while (xa & 1)
	{ 
		if (xa & 0b0110)
		{
			xa = xa >> 1;
			xa |= 1;
		}
		else{
			xa = xa >> 1; 
		}
		cout << (xa & 1) << endl;
	}
	
	int ab = 10;
	int ba = 10;
	cout << "a++ is " << ab++ << " ++b is " << ++ba << endl;
	
	
	string str1 = "helllllooooo";
	int loc = str1.rfind('l', str1.length());
	cout << loc << endl;
	
	int myrArray[100];
	myPtrFunc(&myrArray[0]);
	
	
	string removal = "remove aaa";
	removal.erase(7, 3);
	cout << removal << endl;
	
	
	/*int p =0;
	int n[8][3][5][6];
	for (int i=0; i < n.length(); i++){
		for (int e=0; e < n[i].size(); e++){
			for (int o=0; i < n[i][e].size(); o++){
				for (int u=0; i < n[i][e][o].size(); u++){
					p++;
				}
			}	
		
		}
	}
	cout << p<<endl;*/
	
	string str4 = "twinkle twinkle little star, how wonder where you are twinkle twinkle.  twinkle twinkle all the time.";
	string str5 = "twinkle twinkle little star, twinkle twinkle where you are.  twinkle twinkle all the time.";
	string str6 = "twinkle twinkle little star, how wonder where you are twinkle twinkle.  twinkle twinkle all the time.";
	cout << testFunc(str4) << endl;
	cout << testFunc(str5) << endl;
	cout << testFunc(str6) << endl;
	
	return 0;
}