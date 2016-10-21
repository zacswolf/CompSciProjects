//uses csv reader code

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;



class Data {
		string OrderDate;
		string Region;
		string Rep;
		string Item;
		string Units;
		string UnitCost;
		double total;
	public:
	Data(){//default constructor
		OrderDate="";
		Region="";
		Rep="";
		Item="";
		Units="0";
		UnitCost="0.0";
		total= atof(Units.c_str()) * atof(UnitCost.c_str());
	}
	Data(string OD, string Reg, string Re, string It, string Un, string UC){//default constructor
		OrderDate=OD;
		Region=Reg;
		Rep=Re;
		Item=It;
		Units=Un;
		UnitCost=UC;
		total= atof(Units.c_str()) * atof(UnitCost.c_str());
	}
		void set_value(string, string, string, string, string, string);
		string ret();
		double Total();
};

void Data::set_value(string OD, string Reg, string Re, string It, string Un, string UC){
	OrderDate=OD;
	Region=Reg;
	Rep=Re;
	Item=It;
	Units=Un;
	UnitCost=UC;
	total= atof(Units.c_str()) * atof(UnitCost.c_str());
}
double Data::Total(){
	return total;
}
string Data::ret(){
	return OrderDate+","+Region+","+Rep+","+Item+","+Units+","+UnitCost+"\n";
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

	Data sales[fileVect.size()-1];
	string buffer[fileVect[0].size()];
	//cout << "A\n";
	for (int q=1;q < fileVect.size(); q++){
		for (int l=0; l < fileVect[q].size(); l++){
			buffer[l]=fileVect[q][l];
			//cout << "fileVect: " << fileVect[q][l] << endl;
		}
		sales[q-1].set_value(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
		//cout << sales[q-1].Total() << endl;
	}
	//cout << "B\n";
	
	//manipulate
	Data temp;
	int first;
	
	for (int i = fileVect.size()-2;i>0; i--){
		first =0;
		for (int j = 1; j <=i; ++j){
			if (sales[j].Total() < sales[first].Total()){
				first = j;
			}
			//cout << "switched\n";
			temp = sales[first];
			//cout << "dasdhasjkdhasjkdh "<< sales[i].ret();
			sales[first] = sales[i];
			sales[i] = temp;
			//cout << "dasdhasjkdhasjkdh "<< sales[i].ret();
		}
	}
	
	for (int u=0; u< fileVect.size()-1;u++){
		//cout << sales[u].Total() << endl;
	}
	///////////////////NEED TO SET UP OUTPUT!!!!!!!!!!!!!!!!////////
	
	for (int y=0; y< fileVect[0].size();y++){
		output << fileVect[0][y]<<",";
	}
	output << endl;
	
	for (int u=0; u< fileVect.size()-1;u++){
		output<<sales[u].ret();
	}

	myfile.close();
	output.close();
	return 0;
}