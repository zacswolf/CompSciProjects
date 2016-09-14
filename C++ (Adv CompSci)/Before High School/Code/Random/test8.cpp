#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int whatkey, key, length, l, i, x, v, e, r, t, y, u, o, k;
    string word, c;

cout << "What key did the encrypt use? The message will say the number which will be 1 - 5.\n";
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

cout << "What are the encrypted numbers?\n";
cin >> word;

length = word.length();

vector<string> vector3;
k = 1;
i = 1;
x = 0;
e = 1;
r = 2;
t = 3;
y = 4;
u = 5;
o = 6;
v = 7;
while ( i <= (length / 8))
{
    c = word[e];
    vector3.push_back(c);
    cout << vector3[k] << endl;
    i++;
    k++;
    x = x + 8;
    e = e + 8;
    r = r + 8;
    t = t + 8;
    y = y + 8;
    u = u + 8;
    o = o + 8;
    v = v + 8;

}
}
