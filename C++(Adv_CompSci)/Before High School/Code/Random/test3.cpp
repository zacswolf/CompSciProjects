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
    key = 10100101.0;
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
            while ( f <= length2 )
            {
            array2[h] = strenc[h];
            digit = array2[h];
            if ( digit = 2 )
            {
            array2[h] = 0;
            }
            cout << array2[h];
            h++;
            f++;
            }
            h = 1;
            f = 1;
        break;

        case 'B':
            newword = 01000010.0 + key;
            cout << newword << endl;
        break;

        case 'C':
            newword = 01000011.0 + key;
            cout << newword << endl;
        break;

        case 'D':
            newword = 01000100.0 + key;
            cout << newword << endl;
        break;

        case 'E':
            newword = 01000101.0 + key;
            cout << newword << endl;
        break;

        case 'F':
            newword = 01000110.0 + key;
            cout << newword << endl;
        break;

        case 'G':
            newword = 01000111.0 + key;
            cout << newword << endl;
        break;

        case 'H':
            newword = 01001000.0 + key;
            cout << newword << endl;
        break;

        case 'I':
            newword = 01001001.0 + key;
            cout << newword << endl;
        break;

        case 'J':
            newword = 01001010.0 + key;
            cout << newword << endl;
        break;

        case 'K':
            newword = 01001011.0 + key;
            cout << newword << endl;
        break;

        case 'L':
            newword = 01001100.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'M':
            newword = 01001101.0 + key;
            cout << newword << endl;
            cout << "01001101\n";
            newword = "0";
        break;

        case 'N':
            newword = 01001110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'O':
            newword = 01001111.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'P':
            newword = 01010000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'Q':
            newword = 01010001.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'R':
            newword = 01010010.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'S':
            newword = 01010011.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'T':
            newword = 01010100.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'U':
            newword = 01010101.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'V':
            newword = 01010110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'W':
            newword = 01010111.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'X':
            newword = 01011000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'Y':
            newword = 01011001.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'Z':
            newword = 01011010.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'a':
            newword = 01100001.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'b':
            newword = 01100010.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'c':
            newword = 01100011.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'd':
            newword = 01100100.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'e':
            newword = 01100101.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'f':
            newword = 01100110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'g':
            newword = 01100111.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'h':
            newword = 01101000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'i':
            newword = 01101001.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'j':
            newword = 01101010.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'k':
            newword = 01101011.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'l':
            newword = 01101100.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'm':
            newword = 01101101.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'n':
            newword = 01101110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'o':
            newword = 01101111.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'p':
            newword = 01110000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'q':
            newword = 01110001.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'r':
            newword = 01110010.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 's':
            newword = 01110011.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 't':
            newword = 01110100.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'u':
            newword = 01110101.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'v':
            newword = 01110110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'w':
            newword = 01110111.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'x':
            newword = 01111000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'y':
            newword = 01111001.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case 'z':
            newword = 01111010.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '_':
            newword = 01011111.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '!':
            newword = 00100001.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '@':
            newword = 01000000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '#':
            newword = 00100011.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '$':
            newword = 00100100.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '%':
            newword = 00100101.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '^':
            newword = 01011110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '&':
            newword = 00100110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '*':
            newword = 00101010.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '-':
            newword = 00101101.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '=':
            newword = 00111101.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '+':
            newword = 00101011.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '\(':
            newword = 00101000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '\)':
            newword = 00101001.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '\[':
            newword = 01011011.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '\]':
            newword = 01011101.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '\{':
            newword = 01111011.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '\}':
            newword = 01111101.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '\\':
            newword = 01011100.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '|':
            newword = 01111100.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case ';':
            newword = 00111011.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case ':':
            newword = 00111010.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '\'':
            newword = 00100111.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '\"':
            newword = 00100010.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case ',':
            newword = 00101100.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '.':
            newword = 00101110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '/':
            newword = 00101111.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '?':
            newword = 00111111.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '<':
            newword = 00111100.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '>':
            newword = 00111110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '`':
            newword = 01100000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '~':
            newword = 01111110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case ' ':
            newword = 00000000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '0':
            newword = 10000000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '1':
            newword = 00000001.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '2':
            newword = 00000010.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '3':
            newword = 00000011.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '4':
            newword = 00000100.0 + key;
            cout << newword << endl;
            cout << "00000100\n";
            newword = "0";
        break;

        case '5':
            newword = 00000101.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '6':
            newword = 00000110.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '7':
            newword = 00000111.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '8':
            newword = 00001000.0 + key;
            cout << newword << endl;
            newword = "0";
        break;

        case '9':
            newword = 00001001.0 + key;
            cout << newword << endl;
            newword = "0";
        break;


        default:
            cout << "Not supported\n";
    }

b++;




}
cout << "The key is: " << whatkey << " make sure you remember it."<< endl;
}







else if ( EorU == "u" )
{
int word;

cout << "What is the text? note that you will get the encryped text with indentations but you have to put in each line 1 at a time\n";
cin >> word;

cout << "What is the key to the encrypted text? 'say a number which will be between 1 and 5'\n";
cin >> whatkey;

if ( whatkey == 1 )
{
    key = 10100101.0;
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

int c = 0;

while ( c == 0 )
{
    switch ( word )
    {

    }



}







}


    return 0;
}
