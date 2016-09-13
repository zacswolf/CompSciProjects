#include <iostream>
#include <string>
using namespace std;

int numPlus(string In){
	int num=0;
	int start=0;
	while (In.find("+",start) != -1){
		num++;
		start=In.find("+",start)+1;
	}
	return num;
}
int numMinus(string In){
	int num=0;
	int start=0;
	while (In.find("-",start) != -1){
		num++;
		start=In.find("-",start)+1;
	}
	return num;
}
int numMult(string In){
	int num=0;
	int start=0;
	while (In.find("*",start) != -1){
		num++;
		start=In.find("*",start)+1;
	}
	return num;
}
int numDiv(string In){
	int num=0;
	int start=0;
	while (In.find("/",start) != -1){
		num++;
		start=In.find("/",start)+1;
	}
	return num;
}

int* findPlusLocations(string In){
	int re[numPlus(In)];
	int start=0;
	for (int p; p<numPlus(In);p++){
		re[p]=In.find("+",start);
		start=In.find("+",start)+1;
	}
	return re;
}
int* findMinusLocations(string In){
	int re[numMinus(In)];
	int start=0;
	for (int p; p<numMinus(In);p++){
		re[p]=In.find("-",start);
		start=In.find("-",start)+1;
	}
	return re;
}
int* findMultLocations(string In){
	int re[numMult(In)];
	int start=0;
	for (int p; p<numMult(In);p++){
		re[p]=In.find("*",start);
		start=In.find("*",start)+1;
	}
	return re;
}
int* findDivLocations(string In){
	int re[numDiv(In)];
	int start=0;
	for (int p; p<numDiv(In);p++){
		re[p]=In.find("/",start);
		start=In.find("/",start)+1;
	}
	return re;
}

int numOp(string In){ 
	return numPlus(In)+ numMinus(In)+ numMult(In)+ numDiv(In);
}
int* findOpLocations(string In){
	int re[numOp(In)];
	findPlusLocations.copy(re, numPlus(In), 0);
	findMinusLocations.copy(re, numMinus(In), numPlus(In)+1);
	findMultLocations.copy(re, numMult(In), numMinus(In)+ numPlus(In)+1);
	findDivLocations.copy(re, numDiv(In), numMult(In) + numMinus(In)+ numPlus(In)+1);
	return re;
}


int main()
{
   
   string Pass = "1000";
   string In = "";
   cout << "Whats the Password?";
   while (Pass != In){
       cin >> In;
       
       if(In != Pass){
           cout << "Wrong!" << endl;
       }
   }
   In = "";
   while (!(In.compare("Power") == 0 || In.compare("power") == 0 || In.compare("Off") == 0 || In.compare("off") ==0)){
	   cin >> In;
	   while (In.find(" ") != -1){
			In.erase(In.find(" "));
	   }
	   int operation = numOp(In);
	   /*while (In.find("+") != -1 || In.find("-") != -1 || In.find("*") != -1 || In.find("/") != -1){
			operation++;
			
	   }*/
	   
	   
	   int numbers[operation];
	   if(operation >=1){
			char op[operation-1];
	   
			string remaining = In;
			int start = 0;
			for(int p =0;p<findOpLocations(In).size;p++){
				numbers[p] = In.substr(start, p).to_int_type;
				start = start +1;
			}
	   }
	   
	   cout << In << endl;
	   
	   
	   
   }
	
   return 0;
}




	
	
