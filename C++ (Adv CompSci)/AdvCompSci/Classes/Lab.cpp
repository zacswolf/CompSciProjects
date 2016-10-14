//uses csv reader code

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



class Data {
		string OrderDate;
		string Region;
		string Rep;
		string Item;
		int Units;
		double UnitCost;
	public:
	Data(){//default constructor
		OrderDate="";
		Region="";
		Rep="";
		Item="";
		Units=0;
		UnitCost=0.0;
	}
	Data(string OD, string Reg, string Re, string It, int Un, double UC){//default constructor
		OrderDate=OD;
		Region=Reg;
		Rep=Re;
		Item=It;
		Units=Un;
		UnitCost=UC;
	}
		void set_value(string, string, string, string, int, double);
}Unit1,Unit2, Unit3, Unit4;

void Data::set_value(string OD, string Reg, string Re, string It, int Un, double UC){
	OrderDate=OD;
	Region=Reg;
	Rep=Re;
	Item=It;
	Units=Un;
	UnitCost=UC;
}









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
	end=0;
	int numCol=1;
	for(int k=0; commaPos[k] < newLinePos[0];k++){
		numCol++;
	}
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
	string openFileName = "SalesDataP2.csv";//change name here for file changing
	ifstream myfile (openFileName.c_str());
	remove("csvoutput.csv");
	ofstream output ("csvoutput.csv");
	string fileString;
	vector< vector<string> > fileVect;
	csvToString(fileString, myfile);
	stringTo2DVector(fileVect, fileString);

	for (int i=0; i <5; i++){
		
	}
	
	Unit1.set_value(fileVect[1][0], fileVect[1][1], fileVect[1][2], fileVect[1][3], fileVect[1][4]);
	Unit2.set_value(fileVect[2][0], fileVect[2][1], fileVect[2][2], fileVect[2][3], fileVect[2][4]);
	Unit3.set_value(fileVect[3][0], fileVect[3][1], fileVect[3][2], fileVect[3][3], fileVect[3][4]);
	Unit4.set_value(fileVect[4][0], fileVect[4][1], fileVect[4][2], fileVect[4][3], fileVect[4][4]);
	
	
	
	//manipulate
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