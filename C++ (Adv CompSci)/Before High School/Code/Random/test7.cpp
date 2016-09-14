#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

int main()
{
    int product, whatkey, bin, key, newbin;
    char letter, digit;
    string EorU, word, newword;

    cout << "Do you want to encrypt 'e' or unencrypt 'u'\n";
    cin >> EorU;

if ( EorU == "e" )
{

cout << "What key do want to use? 'say a number between 1 and 5'\n";
cin >> whatkey;

if ( whatkey == 1 )
{
    key = 11100101.0;
}

else if ( whatkey == 2 )
{
    key = 1100100.0;
}

else if ( whatkey == 3 )
{
    key = 10010101.0;
}

else if ( whatkey == 4 )
{
    key = 11001001.0;
}

else if ( whatkey == 5 )
{
    key = 10001101.0;
}
cout << "What is your word or phrase? Note we support all most every character but use underscore _ instead of space, also note that the numbering system is kinda false so we can do more with it in the future. \n";
cin >> word;

int length = word.length();

char array1[length];
int i = 1, n = 0;

while ( i <= length )
{
    array1[n] = word[n];
    i++;
    n++;
}
//
int b = 0;
//int array2[length]
char array2[8];
while( b < length )
{

int f = 1;
int h = 1;

    switch (array1[b])
    {
        case 'A':
            //newword = 01000001.0 + key;
            int bin = 01000001.0;
            newbin = bin + key;
            string strenc = to_string(newbin);
            int length2 = strenc.length();
            while ( f <= length2  )
            {
            array2[h] = strenc[h];
            digit = array2[h];
            if ( digit == 2 )
            {
            array2[h] = 0;
            }
            cout << array2[0];
            cout << "hi\n";
            cout << array2[h] << endl;
            h++;
            f++;
            }
            h = 1;
            f = 1;
        break;
    }
    b++;
}
}
}
