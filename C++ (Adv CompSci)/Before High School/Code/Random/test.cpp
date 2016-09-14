#include <iostream>
//#include <string>

using namespace std;

int main()
{
    int number, key, product;

    cout << "Whats your number\n";
    cin >>  number;
    cout << "Whats you key\n";
    cin >> key;
    product = number + key;
    cout << "Your new encrypted number is: " << product << " Your encrypted key is: " << key << endl;

    return 0;
}
