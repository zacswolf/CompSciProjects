//allows use of input and output stuff
#include <iostream>

//makes is so you can type 'cout' instead of 'std::cout'
using namespace std;

//starts the main task
int main()
{
    // makes a variable
    int age;
    // prints out
    cout << "How old are you?\n";
    // note that: "something\n"; can be replaced with: "something" << endl;
    // stores user impute into the interger age
    cin >> age;
    cout << "Well " << age << " is a really nice age.\n";

    //help it work better on different operating systems
    return 0;
}
