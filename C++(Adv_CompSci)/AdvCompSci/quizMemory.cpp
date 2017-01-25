#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct vegetable
{
string name;
double weight;/*ounces*/
bool AMA;
};

int main(){
	int theArray1[] = {1,2,3,4,5};
	int theArray2[] {1,2,3,4,5};
	//int theArray3[] (1,2,3,4,5);
	//int theArray4[] <1,2,3,4,5>;
	double depth[5][24];
	ofstream infile;
	//infile = stream.open("bricabrac.txt",stream::in);
	infile.open ("bricabrac.txt");
	//infile = open("bricabrac.txt",in);
	//infile.open ("bricabrac.txt", stream::in);



	return 0;
}