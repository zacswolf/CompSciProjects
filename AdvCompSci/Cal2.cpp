#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(){
	
	//password stuff start
	string Pass = "1000";
	string In = "";
	cout << "Whats the Password?";
	while (Pass != In){
		cin >> In;
       
		if(In != Pass){
           cout << "Wrong!" << endl;
		}
	}
	//password stuff end
	
	
	bool equation= false;
	In = "";
	while (!(In.compare("Power") == 0 || In.compare("power") == 0 || In.compare("Off") == 0 || In.compare("off") ==0)){
		cin >> In;
		
		//shell
		equation=true;
		for (int l=0;l<In.length();l++){
			if(In.at(l) != '.' && In.at(l) != '0' && In.at(l) != '1' && In.at(l) != '2' && In.at(l) != '3' && In.at(l) != '4' && In.at(l) != '5' && In.at(l) != '6' && In.at(l) != '7' && In.at(l) != '8' && In.at(l) != '9' && In.at(l) != '+' && In.at(l) != '-' && In.at(l) != '*' && In.at(l) != '/'){
				equation =false;
				//cout<<l;
			}
			
		}
		//cout << equation;
		if (equation == true){
			//cout<< In;
			vector<double> operations;
			
			string num = "";
			for(int s=0; s<In.length(); s++){
				if(In.at(s) == '.' || In.at(s) == '0' || In.at(s) == '1' || In.at(s) == '2' || In.at(s) == '3' || In.at(s) == '4' || In.at(s) == '5' || In.at(s) == '6' || In.at(s) == '7' || In.at(s) == '8' || In.at(s) == '9'){
					num+=In.at(s);
				}
				else{
					double Num = atof(num.c_str());
					operations.push_back(Num);
					operations.push_back(In.at(s));
					//cout<<num<<endl;
					num = "";
				}
			}
			double Num = atof(num.c_str());
			operations.push_back(Num);
			
			for (int i =0; i < operations.size(); i++){
				cout << operations[i] << endl;
			}
			
			
			
		}
		
		
		
		
	}
	
	
	return 0;
}






