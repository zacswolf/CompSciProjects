#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;


class SalesRep
{
   public:   //change
      char rep[10];	 //change	// A character array for ‘rep’ last name.
      char region[10];	 //change	// A character array for the rep’s ‘region’
};


class ItemCatalog
{
   friend   class SALESREC; //change
   public:
      char     item[10];  //change	// character array for ‘item’ name.
   //_______
      float    unitCost;	 //change // a real number for ‘unitCost’.
     
};


class SALESREC: public SalesRep, public ItemCatalog
{
   public:
      char     date[10];
      int      units;
     
      void setUnitCost(float  cost)   //change
      {
         unitCost=cost;    //change
      }
     
      float getUnitCost()
      {
         return  unitCost;    //change
      }


      float Total()
      {
         return   unitCost * units;    //change
      }
     
      void displayRec()
      {
       cout << "Record: " << date <<", " << region << ", " << rep << ", " << item << ", " << units << ", " << unitCost << ", " << Total() << endl;
      }
	  operator<<(ostream &out){
		  out << date << ", " << rep << ", " << item << endl;
	  }
	  bool operator==(const SALESREC& a){
		bool ret = true;
		for (int i =0; i < 10; i++){
			if (date[i] != a.date[i]){
				ret = false;
			}
			if (rep[i] != a.rep[i]){
				ret = false;
			}
			if (item[i] != a.item[i]){
				ret = false;
			}
		}
		  
		return ret;
	  }
	  SALESREC operator+(const SALESREC& a){
		  SALESREC sr= *this;
		  sr.units = this->units + a.units;
		  return sr;
	  }
	  void nullIt(){
		for (int i =0; i < 10; i++){
			date[i] = '\0';
			region[i] = '\0';
			rep[i]='\0';
			item[i]='\0';
		}
		units=0;
		unitCost=0; 
	  }
};


void simpleSortTotal(SALESREC* s[], int c);


int main()
{
   ifstream infile;
   int array[20];
   char cNum[10] ;
   SALESREC* salesArr[40];
   int   salesArrayCount;
   SALESREC* s[40];
  
    infile.open ("SalesDataP5.csv");
	//cout << "a" << endl;
    if (infile.is_open())
    {
         int   c=0;
         float inputUnitCost;
         while (infile.good())
         {
			 //cout << "b" << endl;
                 salesArr[c] = new SALESREC();
				 //cout << "c" << endl;
                 infile.getline(salesArr[c]->date, 256, ',');
				 //cout << "d" << endl;
                 infile.getline(salesArr[c]->region, 256, ',');
				 //cout << "e" << endl;
                 infile.getline(salesArr[c]->rep, 256, ',');
				 
                 infile.getline(salesArr[c]->item, 256, ',');
                 infile.getline(cNum, 256, ',');
				 //cout << "f" << endl;
                 salesArr[c]->units = atoi(cNum);
                 infile.getline(cNum, 256, '\n');
                 inputUnitCost = atof(cNum);
                 salesArr[c]->setUnitCost(inputUnitCost);  //change   //store in salesArr[c]
                 
                 c++;
         }
         salesArrayCount = c-1;
         infile.close();
    }
    else
    {
         cout << "Error opening file";
    }
	
	
	
	for(int i =0; i < salesArrayCount-1; i++){
		for(int j=i+1; j < salesArrayCount; j++){
			if (*salesArr[i]==*salesArr[j]){
				*salesArr[i] = *salesArr[i] + *salesArr[j];
				salesArr[j]->nullIt();
			}
		}
	}
	
	
	
	
   for (int i=0; i < salesArrayCount; i++)
      s[i] = salesArr[i];


   cout << " Unsorted Sales Record Array\n" ;
   for (int i=0; i < salesArrayCount; i++)
      salesArr[i]->displayRec();


   simpleSortTotal (s, salesArrayCount);
   
   cout << " - - - - - - - - - - - -\n" ;
   cout << " Sorted Sales Record Array\n" ;
   
   for (int i=0; i < salesArrayCount; i++)
      s[i]->displayRec();
 
   //clean up allocated sales records
   for (int i=0; i < salesArrayCount; i++)
      delete   salesArr[i];    //change
  


}



void simpleSortTotal(SALESREC* s[], int c)
{
   SALESREC* temp;
   for (int i=0; i < c; i++)
      for (int j=i; j < c; j++){
         if (s[i]->Total() < s[j]->Total())    //change
         {
            temp = s[i];   //change
            s[i]=s[j];   //change
            s[j] = temp;   //change
         }
		 /*if (s[j]-> Total() == 0){
			 
		 }*/
	  }
}
