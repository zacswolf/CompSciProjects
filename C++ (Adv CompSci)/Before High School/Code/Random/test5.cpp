#include <iostream>
#include <string>

using namespace std;

int main()
{
string word;



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

while( b < length )
{

    switch (array1[b])
    {

        case 'A':
            cout << "01000001\n";
        break;

        case 'B':
            cout << "01000010\n";
        break;

        case 'C':
            cout << "01000011\n";
        break;

        case 'D':
            cout << "01000100\n";
        break;

        case 'E':
            cout << "01000101\n";
        break;

        case 'F':
            cout << "01000110\n";
        break;

        case 'G':
            cout << "01000111\n";
        break;

        case 'H':
            cout << "01001000\n";
        break;

        case 'I':
            cout << "01001001\n";
        break;

        case 'J':
            cout << "01001010\n";
        break;

        case 'K':
            cout << "01001011\n";
        break;

        case 'L':
            cout << "01001100\n";
        break;

        case 'M':
            cout << "01001101\n";
        break;

        case 'N':
            cout << "01001110\n";
        break;

        case 'O':
            cout << "01001111\n";
        break;

        case 'P':
            cout << "01010000\n";
        break;

        case 'Q':
            cout << "01010001\n";
        break;

        case 'R':
            cout << "01010010\n";
        break;

        case 'S':
            cout << "01010011\n";
        break;

        case 'T':
            cout << "01010100\n";
        break;

        case 'U':
            cout << "01010101\n";
        break;

        case 'V':
            cout << "01010110\n";
        break;

        case 'W':
            cout << "01010111\n";
        break;

        case 'X':
            cout << "01011000\n";
        break;

        case 'Y':
            cout << "01011001\n";
        break;

        case 'Z':
            cout << "01011010\n";
        break;

        case 'a':
            cout << "01100001\n";
        break;

        case 'b':
            cout << "01100010\n";
        break;

        case 'c':
            cout << "01100011\n";
        break;

        case 'd':
            cout << "01100100\n";
        break;

        case 'e':
            cout << "01100101\n";
        break;

        case 'f':
            cout << "01100110\n";
        break;

        case 'g':
            cout << "01100111\n";
        break;

        case 'h':
            cout << "01101000\n";
        break;

        case 'i':
            cout << "01101001\n";
        break;

        case 'j':
            cout << "01101010\n";
        break;

        case 'k':
            cout << "01101011\n";
        break;

        case 'l':
            cout << "01101100\n";
        break;

        case 'm':
            cout << "01101101\n";
        break;

        case 'n':
            cout << "01101110\n";
        break;

        case 'o':
            cout << "01101111\n";
        break;

        case 'p':
            cout << "01110000\n";
        break;

        case 'q':
            cout << "01110001\n";
        break;

        case 'r':
            cout << "01110010\n";
        break;

        case 's':
            cout << "01110011\n";
        break;

        case 't':
            cout << "01110100\n";
        break;

        case 'u':
            cout << "01110101\n";
        break;

        case 'v':
            cout << "01110110\n";
        break;

        case 'w':
            cout << "01110111\n";
        break;

        case 'x':
            cout << "01111000\n";
        break;

        case 'y':
            cout << "01111001\n";
        break;

        case 'z':
            cout << "01111010\n";
        break;

        case '_':
            cout << "01011111\n";
        break;

        case '!':
            cout << "00100001\n";
        break;

        case '@':
            cout << "01000000\n";
        break;

        case '#':
            cout << "00100011\n";
        break;

        case '$':
            cout << "00100100\n";
        break;

        case '%':
            cout << "00100101\n";
        break;

        case '^':
            cout << "01011110\n";
        break;

        case '&':
            cout << "00100110\n";
        break;

        case '*':
            cout << "00101010\n";
        break;

        case '-':
            cout << "00101101\n";
        break;

        case '=':
            cout << "00111101\n";
        break;

        case '+':
            cout << "00101011\n";
        break;

        case '\(':
            cout << "00101000\n";
        break;

        case '\)':
            cout << "00101001\n";
        break;

        case '\[':
            cout << "01011011\n";
        break;

        case '\]':
            cout << "01011101\n";
        break;

        case '\{':
            cout << "01111011\n";
        break;

        case '\}':
            cout << "01111101\n";
        break;

        case '\\':
            cout << "01011100\n";
        break;

        case '|':
            cout << "01111100\n";
        break;

        case ';':
            cout << "00111011\n";
        break;

        case ':':
            cout << "00111010\n";
        break;

        case '\'':
            cout << "00100111\n";
        break;

        case '\"':
            cout << "00100010\n";
        break;

        case ',':
            cout << "00101100\n";
        break;

        case '.':
            cout << "00101110\n";
        break;

        case '/':
            cout << "00101111\n";
        break;

        case '?':
            cout << "00111111\n";
        break;

        case '<':
            cout << "00111100\n";
        break;

        case '>':
            cout << "00111110\n";
        break;

        case '`':
            cout << "01100000\n";
        break;

        case '~':
            cout << "01111110\n";
        break;

        case ' ':
            cout << "00000000\n";
        break;

        case '0':
            cout << "10000000\n";
        break;

        case '1':
            cout << "00000001\n";
        break;

        case '2':
            cout << "00000010\n";
        break;

        case '3':
            cout << "00000011\n";
        break;

        case '4':
            cout << "00000100\n";
        break;

        case '5':
            cout << "00000101\n";
        break;

        case '6':
            cout << "00000110\n";
        break;

        case '7':
            cout << "00000111\n";
        break;

        case '8':
            cout << "00001000\n";
        break;

        case '9':
            cout << "00001001\n";
        break;


        default:
            cout << "Not supported\n";
    }

b++;




}

    return 0;
}
