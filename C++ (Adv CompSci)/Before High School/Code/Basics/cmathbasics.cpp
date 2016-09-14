#include <iostream>
//makes it easy to do more complex math
#include <cmath>

using namespace std;

int main()
{
    // defines varibles which are doubles
    double num1, num2;
    //outputs
    cout << "What is your number?\n";
    //stores input
    cin >> num1;
    // makes num2 equal to the square root of num1
    num2 = sqrt(num1);
    cout << num2 << " is the square root of " << num1 << endl;



    //define variables
    int num1, num2, sum;
    //outputs
    cout << "What is the first number?\n";
    //stores input
    cin >> num1;
    cout << "What is the secound number\n";
    cin >> num2;
    //makes sum equal to num1 plus num2
    sum = num1 + num2;
    //says stuff and outputs sum
    cout << "Your sum is: " << sum << endl;

    //tells it to stop, note this help it to better run on different operating systems
    return 0;
}
