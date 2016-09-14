#include <iostream>
#include <string>
using namespace std;

int main()
{
    string newold;

    cout << "Wellcome to the Bank of Zac\n";
    cout << "Would you like to open a new account (new), or get into a old account (old)\n";
    cin >> newold;

    if (newold == "new")
    {

    }
    else if (newold == "old")
    {

    }
    else
    {
        cout << "Not a choice\n";
        return 0;
    }


    return 0;
}
