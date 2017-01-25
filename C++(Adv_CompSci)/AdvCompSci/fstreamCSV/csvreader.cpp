#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void csvToString(string &str, ifstream &myfile){
	while (!myfile.eof()){
		str+=myfile.get();
	}
}



void stringTo2DVector(vector< vector<string> > &vect, string &str){
	int end=0;//last char index that was processed
	int newLine;
	int newCol;
	bool skipNL= false;
	bool skipC= false;
	vector<int> quotePos;
	vector<int> newLinePos;
	vector<int> commaPos;
	vector<string> row;


	end=0;
	while(end!=-1){//marks quotes
		end = str.find('\"',end);
		if(end <str.length()){       //fixes a glitch that I had with mac gnu
			quotePos.push_back(end);
			if(str.find('\"',end)!=-1){
				end = str.find('\"',end)+1;
			}
		}
		else{
			end = -1;
		}
	}




	cout << "quotes   " << quotePos.size() << endl;

	end=0;
	while(str.find("\n", end)!=-1){//marks new lines
		skipNL=false;
		newLine=str.find("\n", end);
		for(int w=0;w<quotePos.size();w+=2){
			if (quotePos[w] < newCol && newCol < quotePos[w+1]){
				skipNL = true;
			}
		}
		if (!skipNL){
			newLinePos.push_back(newLine);
		}
		end= newLine+1;
	}
	cout <<"newline   " << newLinePos.size() << endl;


	end=0;
	while(str.find(',', end)!=-1){//marks commas
		skipC=false;
		newCol=str.find(',', end);
		for(int w=0;w<quotePos.size();w+=2){
			if (quotePos[w] < newCol && newCol < quotePos[w+1]){//makes sure , is not in quotes
				//, is in a cell
				skipC = true;
			}
		}
		if (!skipC){
			commaPos.push_back(newCol);
		}
		end= newCol+1;
	}
	cout <<"commas   " << commaPos.size() << endl;


	end=0;
	int numCol=1;
	for(int k=0; commaPos[k] < newLinePos[0];k++){
		numCol++;
	}
	cout << "Cols    " << numCol << endl;
	
	//facts there are numCol Collumns and newLinePos.size() rows
	int start=0;
	int co=0;
	for(int r=0;r<newLinePos.size(); r++){
		for(int c=0;c<numCol-1; c++){
			row.push_back(str.substr(start,commaPos[co]-start));
			start=commaPos[co]+1;
			co++;
		}
		row.push_back(str.substr(start,newLinePos[r]-start));
		start=newLinePos[r]+1;
		vect.push_back(row);
		row.clear();
	}	

	
}




int main(){
	
	string openFileName = "WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv";//change name here for file changing
	ifstream myfile (openFileName.c_str());
	remove("csvoutput.csv");
	ofstream output ("csvoutput.csv");
	string fileString;
	vector< vector<string> > fileVect;
	csvToString(fileString, myfile);
	stringTo2DVector(fileVect, fileString);


	for (int u=0; u< fileVect.size();u++){
		for (int y=0; y< fileVect[u].size();y++){
			output << fileVect[u][y]<<",";
		}
		output << endl;
	}


	myfile.close();
	output.close();
	return 0;
}