#include <string>
#include <bitset>
#include <iostream>
using namespace std;
int main(){
  string myString = "Hi";
  int i = 0;
  //change i for the letter start with 0
  //for (size_t i = 0; i < myString.size(); ++i)
  //{
      long array1[5];

      //array1[5] = bitset<8>(myString.c_str()[i]);
      bitset<8>(myString.c_str()[i]).to_ulong();
        array1[0] = bitset<8>(myString.c_str()[i]).to_ulong();
        cout << array1[0];
      //cout << bitset<8>(myString.c_str()[i]) << endl;


 long dec,rem,k=1,sum=0;
   dec = array1[0];
    do
    {
        rem=dec%2;
        sum=sum + (k*rem);
        dec=dec/2;
        k=k*10;
    }while(dec>0);
    cout<<"The binary of the given number is:"<<sum<<endl;
    cin.get();
    cin.get();




  //}
}

