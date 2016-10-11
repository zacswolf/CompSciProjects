#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;


struct LIFEEXPECTANCY
{
	int index;
	string variant;
	string area;
	string notes;
	int countrycode;
	int t1950;
	int t1955;
	int t1960;
	int t1965;
	int t1970;
	int t1975;
	int t1980;
	int t1985;
	int t1990;
	int t1995;
	int t2000;
	int t2005;
	int t2010;
	int t2015;
};


int main(){
	
	ifstream myfile ("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv", ios::in);//change name here for reuse
	
	remove( "output.csv" );
	ofstream output ("output.csv");
	//string title = "Life expectancy at birth for both sexes combined (years)";
	//vector<string> colV;
	//vector<vector<string> > rowV;
	
	int ROWS = 258; //1s
	int COLS = 18;//1s
	int infoRow =17;//0s
	int sortByCol = 15;//0s
	
	string in[ROWS][COLS];
	
	if (!myfile.is_open()){
		return 0;
	}
	
	//getting facts
	/*string value;
	getline(myfile, value, '\n');
	int lines =0;
	
	cout <<value << endl;
	
	while (!(myfile.eof()) && (value != "")){
		getline(myfile, value, '\n');
		lines++;
		cout << value << endl;
	}
	cout << "lines: " << lines << endl;
	
	
	
	myfile.clear();
	myfile.seekg(0);
	value ="";
	getline(myfile, value, '\n');*/
	
	//myfile.seekg(myfile.getline(title));
	string val ="";
	////////getline(myfile, val);
	//cout<< "hi\n";
	////////cout<< val;
	//colV.push_back(val);
	/*for(int row =0; !(myfile.eof()); row++){
		cout<< val;
		for(int col=0;val!="\n";col++){
			cout<< val <<endl;
			getline(myfile, val);
			//cout<< "ddasd\n";
			colV.push_back(val);
			//in[row][col]=val;
			//cout<< "qwuieio\n";
		}
		rowV.push_back(colV);
		colV.clear();
	}*/
	
	int start =0;
	for(int row =0; row <ROWS; row++){
		getline(myfile, val);
		//cout << val << endl << endl;
		for (int col = 0; col < COLS; col++){
			in[row][col] = val.substr(0, val.find(','));
			val = val.substr(val.find(',', start)+1);
			//cout << val << endl;
		}
	}
	
	/*float highest;
	int save;
	for (int sort=0; sort < ROWS-infoRow-1; sort++){
		highest=atof(in[sort+infoRow][sortByCol]);
		save = sort +infoRow;/*
		for(int sort2=sort+1; sort2 < ROWS-infoRow; sort2++){
			if(highest < atof(in[sort2 +infoRow][sortByCol])){
				highest = atof(in[sort2 +infoRow][sortByCol]);
				save = sort2 +infoRow;
			}
		}
		swap(in[sort+infoRow], in[save]);
	}*/
	
	
	//cout << in[219-1][13-1] << endl;
	
	
	
	/*double* store[ROWS-infoRow-1];
	for (int o=0;o< ROWS-infoRow-1; o++){
		store[o]=&(stringstream convert(in[o+infoRow][sortByCol]));
	}
	sort(store[0], store[ROWS-infoRow-1]);
	
	sort(store.begin(), store.end());*/
   
	
	
	
	
	string swap[COLS];
	
	for (int gg = 0; gg < ROWS-(infoRow+1)-1; gg++){ 
		
		// Last i elements are already in place   
		double a,b;
		for (int hh = 0; hh < ROWS-(infoRow+1)-gg; hh++){
			stringstream converta(in[hh+infoRow][sortByCol]);
			converta >> a;
			stringstream convertb(in[hh+1+infoRow][sortByCol]);
			convertb >> b;
			//cout << a << "    " << b<< endl;
			if (a < b){//assending/decending
				//swap(&in[hh+infoRow][sortByCol], &in[hh+1+infoRow][sortByCol]);
				for(int z=0; z< COLS; z++){
					swap[z]=in[hh+infoRow][z];
					in[hh+infoRow][z] = in[hh+1+infoRow][z];
					in[hh+1+infoRow][z] = swap[z];
				}
			}
		}
	}
	
	/*string swap[COLS];///WORK HERE
	int save;
	double a;
	double b;
	//cout << ROWS << endl;
	for (int sort = 0; sort < ROWS-infoRow-1; sort++) {
		//cout<< "call " << sort+infoRow << endl;
		stringstream converta(in[sort+infoRow][sortByCol]);
		converta >> a;
		double Max = a;
		//cout << Max << endl;
		for (int sort2 = sort+1; sort2 < ROWS-infoRow; sort2++) {
			stringstream convertb(in[sort2+infoRow][sortByCol]);
			convertb >> b;
			//cout << a << "   " << b << endl;
			if (a < b) {
				Max = b;
				save = sort2+infoRow;
			}
		}

		if(Max != a) {
			for(int z=0; z< COLS; z++){
				//cout<< "swap\n";
				swap[z]=in[sort+infoRow][z];
				in[sort+infoRow][z] = in[save][z];
				in[save][z]=swap[z];
			}
		}
		cout << endl;
	}*/
	for(int e=0;e< COLS; e++){
	cout << in[16][e] <<endl;
	}
	string re;
	for (int p = 0; p < ROWS +2; p++){
		for (int q = 0; q < COLS; q++){
			re+=in[p][q];
			re+=",";
		}
		re.erase(re.length()-1, 1);
		re+="\n";
	}
	
	
	output <<re;
	output.close();
	myfile.close();
	return 0;
}