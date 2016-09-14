// this method requires you to have your binary with a  * between each case

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{


 int asd = 10010;
  string asdf = "pi is " + to_string(asd);
  string perfect = to_string(1+2+4+7+14) + " is a perfect number";
  cout << asdf << '\n';


int array5[2];
array5[1] = 5;
array5[2] = 6;
cout << array5[1];
cout << array5[2];

cout << array5[1];
cout << array5[2];




int word;
string wordv2;
cout << "What is your encrypt?\n";
cin >> wordv2;


size_t q = count(wordv2.begin(), wordv2.end(), '*');

cout << q << endl;

int length = wordv2.length();

char array1[length];
int i = 1, n = 0;
while ( i <= length )
{
    array1[n] = wordv2[n];
    i++;
    n++;
}
int whatkey;
cout << "What is your key number?";
cin >> whatkey;
string key;

if ( whatkey == 1 )
{
    key = "10100101";
}

else if ( whatkey == 2 )
{
    key = "1100100";
}

else if ( whatkey == 3 )
{
    key = "10010101";
}

else if ( whatkey == 4 )
{
    key = "11001001";
}

else if ( whatkey == 5 )
{
    key = "10001101";
}

int keylength = key.length();

char array2[keylength];
int x = 1, z = 0;
while ( x <= length )
{
    array1[z] = key[z];
    x++;
    z++;
}
int f = 1001;
//string test = 0010 + f;
cout << f << endl;

return 0;
}
