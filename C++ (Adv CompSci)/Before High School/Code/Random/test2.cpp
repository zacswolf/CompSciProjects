#include <iostream>

using namespace std;

int main()
{
    int num1, num2;

    cout << "Enter 2 numbers\n";
    cin >> num1 >> num2;

    if ( num1 == num2 )
        cout << num1 << " is equal to " << num2 << endl;

    if ( num1 != num2 )
        cout << num1 << " is not equal to " << num2 << endl;

    if ( num1 > num2 )
        cout << num1 << " is greater then " << num2 << endl;

    if ( num1 < num2 )
        cout << num1 << " is less then  " << num2 << endl;

    if ( num1 >= num2 )
        cout << num1 << " is greater then or equal to " << num2 << endl;

    if ( num1 <= num2 )
        cout << num1 << " is less then or equal to " << num2 << endl;

    int grade;

    cout << "Ok up next\n";
    cout << "Pass or fail\n" << "Whats your grade of a test?\n";
    cin >> grade;
    if ( grade >= 70 )
        cout << "Passed\n" << endl;
    else
        cout << "Failed\n" << endl;

    cout << "Now in more detail\n";

    if ( grade == 100 )
        cout << "Perfect score" << endl;
    else if ( grade >= 90 )
        cout << "A" << endl;
    else if ( grade >= 80 )
            cout << "B" << endl;
    else if ( grade >= 70 )
        cout << "C" << endl;
    else
        cout << "Failed" << endl;

    return 0;
}
