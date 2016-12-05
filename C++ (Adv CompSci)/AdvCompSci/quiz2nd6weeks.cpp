#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Manufacturer{
	public:
      Manufacturer()
      {
         cout<<  "E \n";
      }
      Manufacturer(char code)
      {
         cout<< "D " << code << endl; 
      }
};
class LCDPanel:  public Manufacturer{
	public:
      LCDPanel(): Manufacturer('F')
      {
         cout<<  "C \n";
      }
};

class Backlight:  public Manufacturer{
	public:
      Backlight()
      {
          Manufacturer('G');
         cout << "B \n";
      }
};
class Display:  public Backlight, public LCDPanel{
	public:
      Display() : Backlight(){
		cout << "A \n";
	  }
};




class Record{
   public:
      int value;
};




class Rock
{
   int hardness;
   int size;
   public:
      Rock()
      {
         cout << "Rock contructed" << endl;
      }
};


int main(){

	int a [] = { 16, 2, 77, 40, 12071 };
	int a_length = sizeof(a) / sizeof(int);
	//cout << a_length << endl;

	
	int foo[] = {2, 4, 6, 8, 10};

	int length = 4;

	for (int i=0; i <= length; i++){
		//cout << i << " " << endl;
	}
	//Display h;
	
		Record** rec = new Record*[10];


	
	for(int i=0; i< 10; i++)
   {
      rec[i] = new Record();
      	rec[i]->value = 0;
   }
   for (int i=0; i < 10; i++){
       delete rec[i];
   }
	delete[] rec;



	Rock stone;
   Rock  *boulder;
   boulder = new Rock();

	
	return 0;
}