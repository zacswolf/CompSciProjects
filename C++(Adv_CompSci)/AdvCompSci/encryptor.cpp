#include <iostream>
#include <string>
#include <vector>

using namespace std;

string toBase16(int base10, vector<int> &rem){
    char dic[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    rem.push_back(dic[base10 % 16]);
    base10=base10/16;
    
    if(base10 ==0){
        string re="";
        for (int i =rem.size()-1; i >= 0;i--){
            re += rem[i];
            
        }
        return re;
        
    }
    else
    {
        return toBase16(base10, rem);
    }
}

int toBase10(string base16){
    int num[2];
    //cout << "base16 is " << base16 << endl;
    for (int i =0; i< base16.length(); i++){
        switch (base16.at(i)) {
            case 'A':
                num[i]=10;
                break;
            case 'B':
                num[i]=11;
                break;
            case 'C':
                num[i]=12;
                break;
            case 'D':
                num[i]=13;
                break;
            case 'E':
                num[i]=14;
                break;
            case 'F':
                num[i]=15;
                break;
            default:
                char c = '1';
                num[i] = base16.at(i) - '0';// turns a 'int' to a int
        }
        //cout << "Number " << i << " is " << num[i] << endl;
    }
    
    return num[0]*16+num[1];
}






int main(){
    cout<< "Do you want to \"E\" (Encrypt) or \"D\" (Decrypt)" << endl;
    string operation;
    getline(cin,operation);
    
    
    
    if(operation == "E"){
        string strkey;
        string message;
        vector<int> rem;
        
        cout << "Whats your encryption key? Type it then press enter when done.\n";
        getline(cin,strkey);
        
        cout << "Whats your message? Type it then type ` and press enter when done.\n";
        getline(cin,message, '`');
        
        
        int k=0;
        for (int j =0; j < message.length(); j++){
            char a = message.at(j)^strkey.at(k%strkey.length());
            k++;
            rem.clear();
            string re = toBase16(a, rem);
            
            if(re.length() < 2) {
                cout << "0";
            }
            
            cout << re;
        }
    }
    
    else if(operation == "D"){
        string strkey;
        string message;
        
        
        cout << "What was your encryption key? Type it then press enter when done.\n";
        getline(cin,strkey);
        
        cout << "Whats your encrypted message? Type it then press enter when done.\n";
        getline(cin,message);
        
        //cout << "EK: " << strkey<< endl<< "EM: "<<message<<endl;
        
        int k=0;
        for (int j =0; j < message.length(); j+=2){
            string a;
            a.push_back(message.at(j));
            a.push_back(message.at(j+1));
            //cout << "a: " << a <<endl;
            char re = toBase10(a);
            //cout << "re: " << re <<endl;
            re = re^strkey.at(k%strkey.length());
            
            k++;
            cout << re;
        }
    }
    
    else{
        cout<<"Invalid operation, next time type \"E\" or \"D\"\n";
    }
    

    cout << endl << endl;
    return 0;
}